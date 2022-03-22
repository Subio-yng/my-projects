#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)
 
enum Part {
    UNMARKED, LEFT, RIGHT
};
 
Part getOppositePart(Part cur) {
    if (cur == Part::LEFT) {
        return Part::RIGHT;
    } else if (cur == Part::RIGHT) {
        return Part::LEFT;
    } else {
        throw 1;
    }
}
 
bool dfs(int curV, Part curColor, std::vector<Part> &colors, const std::vector<std::vector<int>> &edges) {
    colors[curV] = curColor;
    for (int nextV : edges[curV]) {
        bool isBipartite = true;
        if (colors[nextV] == Part::UNMARKED) {
            isBipartite = dfs(nextV, getOppositePart(curColor), colors, edges);
        } else {
            isBipartite = colors[curV] != colors[nextV];
        }
        if (!isBipartite) {
            return false;
        }
    }
    return true;
}
 
int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<int>> edges(nV);
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from - 1].push_back(to - 1);
        edges[to - 1].push_back(from - 1);
    }
    std::vector<Part> colors(nV, Part::UNMARKED);
    for (int i = 0; i < nV; i++) {
        if (colors[i] == Part::UNMARKED && !dfs(i, Part::LEFT, colors, edges)) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}