#include <stdio.h>
#include <vector>
#include <map>

// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

enum Part {
    UNMARKED, LEFT, RIGHT
};

Part getOppositePart(Part cur) {
    if (cur == Part::LEFT) {
        return Part::RIGHT;
    }
    return Part::LEFT;
}

bool dfs(int curV, std::vector<Part> &colors, std::map<int, std::vector<int>> &edges) {
    if (colors[curV] == Part::UNMARKED) {
        colors[curV] = Part::LEFT;
    }
    bool type = true;
    for (int &v : edges[curV]) {
        if (colors[v] == colors[curV]) {
            type = false;
            break;
        }
        if (colors[v] == Part::UNMARKED) {
            colors[v] = getOppositePart(colors[curV]);
            dfs(v, colors, edges);
        }
    }
    return type;
}

int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::map<int, std::vector<int>> edges;
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from - 1].push_back(to - 1);
        edges[to - 1].push_back(from - 1);
    }
    std::vector<Part> colors(nV, Part::UNMARKED);
    for (int i = 0; i < nV; i++) {
        if (!dfs(i, colors, edges)) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}