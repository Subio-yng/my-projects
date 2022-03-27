#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

struct Cell {

    int val;

    int id;
};

int dfs(int curV, std::vector<bool> &visited, std::vector<std::vector<int>> &edges) {
    visited[curV] = true;
    int count = 1;
    std::vector<Cell> orderV;
    for (int nextV : edges[curV]) {
        if (!visited[nextV]) {
            int nextDfs = dfs(nextV, visited, edges);
            orderV.push_back({nextDfs, nextV});
            count += nextDfs;
        }
    }
    std::sort(orderV.begin(), orderV.end(), [](const Cell &left, const Cell &right) {
        return left.val < right.val;
    });
    while ((int) orderV.size() > ((int) edges[curV].size() + 1) / 2) {
        count -= orderV.back().val;
        orderV.pop_back();
    }
    std::vector<int> listV;
    for (Cell v : orderV) {
        listV.push_back(v.id);
    }
    edges[curV] = listV;
    visited[curV] = false;
    return count;
}

void dfsPrint(int curV, std::vector<bool> &visited, const std::vector<std::vector<int>> &edges) {
    visited[curV] = true;
    for (int nextV : edges[curV]) {
        if (!visited[nextV]) {
            dfsPrint(nextV, visited, edges);
        }
    }
    printf("%d\n", curV + 1);
}

int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<int>> edges(nV);
    for (int from = 0; from < nV; from++) {
        int to;
        scanf("%d", &to);
        while (to != 0) {
            edges[from].push_back(to - 1);
            scanf("%d", &to);
        }
    }
    std::vector<bool> visited(nV, false);
    printf("%d\n", dfs(0, visited, edges));
    dfsPrint(0, visited, edges);
    return 0;
}