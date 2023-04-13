#include <bits/stdc++.h>

// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

enum State {
    VOID, VISITED, IN_PROCESS
};

void dfs(int curV, std::vector<int> &cnt, std::vector<State> &vertex, const std::vector<std::vector<int>> &edges) {
    vertex[curV] = State::IN_PROCESS;
    for (int next : edges[curV]) {
        if (vertex[next] == State::VOID) {
            cnt[next] = cnt[curV] + 1;
            dfs(next, cnt, vertex, edges);
            cnt[next] = 0;
        } else if (vertex[next] == State::IN_PROCESS && cnt[curV] - cnt[next] >= 2) {
            printf("YES");
            exit(0);
        }
    }
    vertex[curV] = State::VISITED;
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
    std::vector<int> cnt(nV, 0);
    for (int i = 0; i < nV; i++) {
        if (vertex[i] == State::VOID) {
            dfs(i, cnt, vertex, edges);
        }
    }
    printf("NO");
    return 0;
}