#include <stdio.h>
#include <vector>
#include <queue>
#include <climits>

// Time complexity: O(nE * log(nV))
// Space complexity: O(nV + nE)

struct Vertex {

    int id;

    int dist;

    bool operator <(const Vertex &a) const {
        if (dist == a.dist) {
            return id > a.id;
        }
        return dist > a.dist;
    }
};

struct Edge {

    int to;

    int weight;
};

int main() {
	int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<Edge>> edges(nV);
    for (int i = 0; i < nE; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        from--;
        to--;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }
    std::vector<bool> visited(nV, false);
    std::vector<int> dist(nV, INT_MAX);
    std::priority_queue<Vertex> inProcess;
    inProcess.push({0, 0});
    dist[0] = 0;
    int sumWeight = 0;
    while (!inProcess.empty()) {
        int bestFrom = inProcess.top().id;
        inProcess.pop();
        if (visited[bestFrom]) {
            continue;
        }
        visited[bestFrom] = true;
        sumWeight += dist[bestFrom];
        for (Edge nextE : edges[bestFrom]) {
            if (nextE.weight < dist[nextE.to]) {
                dist[nextE.to] = nextE.weight;
                inProcess.push({nextE.to, dist[nextE.to]});
            }
        }
    }
    printf("%d", sumWeight);
	return 0;
}