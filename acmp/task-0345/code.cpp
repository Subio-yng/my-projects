#include <stdio.h>
#include <string>
#include <vector>
#include <map>
 
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)

enum State {
    NEW, IN_PROCESS, VISITED
};

bool dfs(std::string &curV,
         std::string &startV,
         std::map<std::string, State> &stateV,
         std::map<std::string, std::vector<std::string>> &edges
) {
    if (curV == startV && stateV[curV] == State::IN_PROCESS) {
        return true;
    }
    if (stateV[curV] == State::VISITED) {
        return false;
    }
    bool isRecursion = false;
    stateV[curV] = State::IN_PROCESS;
    for (auto nextV : edges[curV]) {
        isRecursion = nextV == startV;
        if (stateV[nextV] == State::NEW) {
            isRecursion = dfs(nextV, startV, stateV, edges);
        }
        if (isRecursion) {
            break;
        }
    }
    stateV[curV] = State::VISITED;
    return isRecursion;
}
 
int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<std::string> list(nV);
    std::map<std::string, std::vector<std::string>> edges;
    std::map<std::string, State> stateV;
    for (int i = 0; i < nV; i++) {
        char buf[1 + 100];
        scanf(" %s", &buf);
        stateV[buf] = State::NEW;
        list[i] = buf;
        int nE;
        scanf("%d", &nE);
        for (int j = 0; j < nE; j++) {
            scanf(" %s", &buf);
            edges[list[i]].push_back(buf);
        }
        scanf(" *****");
    }
    for (int i = 0; i < nV; i++) {
        if (dfs(list[i], list[i], stateV, edges)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        for (auto &nextV : stateV) {
            nextV.second = State::NEW;
        }
    }
    return 0;
}