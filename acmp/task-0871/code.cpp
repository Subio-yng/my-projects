#include <bits/stdc++.h>

// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

enum State {
    VOID, VISITED, IN_PROCESS
};

bool dfs(int curV, int prevV, std::vector<State> &vertex, const std::vector<std::vector<int>> &edges) {
    vertex[curV] = State::IN_PROCESS;
    for (int nextV : edges[curV]) {
        if (vertex[nextV] == State::VOID) {
            if (dfs(nextV, curV, vertex, edges)) {
                return true;
            }
        } else if (vertex[nextV] == State::IN_PROCESS && nextV != prevV) {
            return true;
        }
    }
    vertex[curV] = State::VISITED;
    return false;
}

int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<int>> edges(nV);
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        from--;
        to--;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    std::vector<State> vertex(nV, State::VOID);
    for (int i = 0; i < nV; i++) {
        if (vertex[i] == State::VOID && dfs(i, i, vertex, edges)) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}