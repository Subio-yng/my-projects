#include <stdio.h>
#include <vector>
#include <queue>
  
// Time complexity: O(nE * log(nV))
// Space complexity: O(nV + nE)
  
struct Vertex {
  
    int id;
  
    int dist;
  
    bool operator <(const Vertex &a) const {
        if (this->dist == a.dist) {
            return this->id > a.id;
        }
        return this->dist > a.dist;
    }
};
  
struct Edge {
  
    int to;
  
    int weight;
};
  
int main() {
    int nV, nE, startV;
    scanf("%d %d %d", &nV, &nE, &startV);
    std::vector<std::vector<Edge>> edges(nV);
    for (int i = 0; i < nE; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }
    const int INF = 2009000999;
    std::vector<int> dist(nV, INF);
    dist[startV] = 0;
    std::priority_queue<Vertex> inProcess;
    std::vector<bool> isFinal(nV, false);
    inProcess.push({startV, 0});
    while (!inProcess.empty()) {
        Vertex bestFrom = inProcess.top();
        inProcess.pop();
        if (isFinal[bestFrom.id]) {
            continue;
        }
        if (bestFrom.dist == INF) {
            break;
        }
        isFinal[bestFrom.id] = true;
        for (Edge nextE : edges[bestFrom.id]) {
            if (dist[nextE.to] > bestFrom.dist + nextE.weight) {
                dist[nextE.to] = bestFrom.dist + nextE.weight;
                inProcess.push({nextE.to, dist[nextE.to]});
            }
        }
    }
    for (int endV = 0; endV < nV; endV++) {
        printf("%d ", dist[endV]);
    }
    return 0;
}