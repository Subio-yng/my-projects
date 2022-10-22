#include <stdio.h>
#include <vector>

// Time complexity: O(n * nP)
// Space complexity: O(n)

struct Coord {

    int i;

    int j;

    static Coord read() {
        int i, j;
        scanf("%d %d", &i, &j);
        return {i, j};
    }

    int getDistTo(const Coord &a) const {
        int di = i - a.i;
        int dj = j - a.j;
        return di * di + dj * dj;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Coord> base(n);
    for (int i = 0; i < n; i++) {
        base[i] = Coord::read();
    }
    std::vector<int> cntPerson(n, 0);
    int nPerson;
    scanf("%d", &nPerson);
    for (int iP = 0; iP < nPerson; iP++) {
        Coord cur = Coord::read();
        int bestId = 0;
        int bestDist = base[0].getDistTo(cur);
        for (int i = 1; i < n; i++) {
            int curDist = base[i].getDistTo(cur);
            if (curDist < bestDist) {
                bestId = i;
                bestDist = curDist;
            }
        }
        cntPerson[bestId]++;
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", cntPerson[i]);
    }
    return 0;
}