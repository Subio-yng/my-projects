#include <stdio.h>
#include <vector>

// Time complexity: O(nS^2)
// Space complexity: O(nS)

struct Sensor {

    int i;

    int j;

    int dist;

    static Sensor read() {
        int i, j, d;
        scanf("%d %d %d", &i, &j, &d);
        return {i, j, d};
    }

    bool canMergeSensor(const Sensor &a) const {
        int di = a.i - i;
        int dj = a.j - j;
        int sumDist = dist + a.dist;
        return di * di + dj * dj <= sumDist * sumDist;
    }
};

const int N_SIDES = 4;

void dfs(int cur,
         std::vector<bool> &visited,
         std::vector<std::vector<bool>> &canTouch,
         const std::vector<Sensor> &sensors
) {
    visited[cur] = true;
    for (int i = 0; i < (int) sensors.size(); i++) {
        if (!visited[i] && sensors[cur].canMergeSensor(sensors[i])) {
            dfs(i, visited, canTouch, sensors);
            for (int j = 0; j < N_SIDES; j++) {
                canTouch[j][cur] = canTouch[j][cur] | canTouch[j][i];
            }
        }
    }
}

int main() {
    const int UP = 0;
    const int LEFT = 1;
    const int BOTTOM = 2;
    const int RIGHT = 3;
    int sizeI, sizeJ, nS;
    scanf("%d %d %d", &sizeI, &sizeJ, &nS);
    std::vector<Sensor> sensors(nS);
    std::vector<std::vector<bool>> canTouch(N_SIDES, std::vector<bool>(nS, false));
    for (int i = 0; i < nS; i++) {
        Sensor cur = Sensor::read();
        sensors[i] = cur;
        if (cur.i - cur.dist <= 0) {
            canTouch[UP][i] = true;
        }
        if (cur.j - cur.dist <= 0) {
            canTouch[LEFT][i] = true;
        }
        if (cur.i + cur.dist >= sizeI) {
            canTouch[BOTTOM][i] = true;
        }
        if (cur.j + cur.dist >= sizeJ) {
            canTouch[RIGHT][i] = true;
        }
    }
    std::vector<bool> visited(nS, false);
    for (int i = 0; i < nS; i++) {
        if (!visited[i]) {
            dfs(i, visited, canTouch, sensors);
        }
    }
    for (int i = 0; i < nS; i++) {
        if ((canTouch[UP][i] || canTouch[RIGHT][i]) &&
            (canTouch[LEFT][i] || canTouch[BOTTOM][i])
        ) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}