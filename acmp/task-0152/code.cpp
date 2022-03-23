#include <stdio.h>
#include <vector>
  
// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

enum State {
    NEW, IN_PROCESS, VISITED
};

bool dfs(int curV, std::vector<State> &stateV, const std::vector<std::vector<int>> &edges) {
    stateV[curV] = State::IN_PROCESS;
    bool isCycle = false;
    for (int nextV : edges[curV]) {
        isCycle = stateV[nextV] == State::IN_PROCESS;
        if (stateV[nextV] == State::NEW) {
            isCycle = dfs(nextV, stateV, edges);
        }
        if (isCycle) {
            break;
        }
    }
    stateV[curV] = State::VISITED;
    return isCycle;
}

int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<int>> edges(nV);
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from - 1].push_back(to - 1);
    }
    std::vector<State> stateV(nV, State::NEW);
    for (int i = 0; i < nV; i++) {
        if (stateV[i] != VISITED && dfs(i, stateV, edges)) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}