#include <stdio.h>
#include <vector>
#include <set>
 
// Time complexity: O(nE * log(nV))
// Space complexity: O(nV + nE)
 
struct Vertex {
 
    int id;
 
    int dist;
 
    bool operator <(const Vertex &a) const {
        if (this->dist == a.dist) {
            return this->id < a.id;
        }
        return this->dist < a.dist;
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
    std::set<Vertex> inProcess;
    inProcess.insert({startV, 0});
    while (!inProcess.empty()) {
        Vertex bestFrom = *inProcess.begin();
        inProcess.erase(inProcess.begin());
        if (bestFrom.dist == INF) {
            break;
        }
        for (Edge nextE : edges[bestFrom.id]) {
            if (dist[nextE.to] > bestFrom.dist + nextE.weight) {
                inProcess.erase({nextE.to, dist[nextE.to]});
                dist[nextE.to] = bestFrom.dist + nextE.weight;
                inProcess.insert({nextE.to, dist[nextE.to]});
            }
        }
    }
    for (int endV = 0; endV < nV; endV++) {
        printf("%d ", dist[endV]);
    }
    return 0;
}