#include <stdio.h>
#include <vector>
#include <map>
#include <set>

// Time complexity: O(nE * log(nE))
// Space complexity: O(nE)

enum Part {
    UNMARKED, LEFT, RIGHT
};

void dfs(int curV, Part curColor, bool &check, std::vector<Part> &colors, std::map<int, std::set<int>> &edges) {
    for (int e : edges[curV]) {
        if (colors[e] == curColor) {
            check = false;
            break;
        }
        if (colors[e] == Part::UNMARKED) {
            if (curColor == Part::LEFT) {
                colors[e] = Part::RIGHT;
            } else {
                colors[e] = Part::LEFT;
            }
            dfs(e, colors[e], check, colors, edges);
        }
    }
}

int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::map<int, std::set<int>> edges;
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from - 1].insert(to - 1);
        edges[to - 1].insert(from - 1);
    }
    bool ans = true;
    std::vector<Part> colors(nV, Part::UNMARKED);
    for (int i = 0; i < nV; i++) {
        if (colors[i] == Part::UNMARKED) {
            colors[i] = Part::LEFT;
        }
        dfs(i, colors[i], ans, colors, edges);
    }
    if (ans) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}