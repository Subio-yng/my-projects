#include <stdio.h>
#include <vector>
#include <algorithm>
 
// Time complexity: O(nV * nE)
// Space complexity: O(nE)
 
struct Edge {
 
    int from;
     
    int to;
     
    int weight;
     
    static Edge read() {
        int f, t, w;
        scanf("%d %d %d", &f, &t, &w);
        return {f - 1, t - 1, w};
    }
};
 
int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<Edge> edges(nE);
    for (int i = 0; i < nE; i++) {
        edges[i] = Edge::read();
    }
    const int INF = 1'000'000'000;
    std::vector<int> dist(nV, -INF);
    dist[0] = 0;
    for (int i = 1; i < nV; i++) {
        for (Edge nextE : edges) {
            if (-INF != dist[nextE.from]) {
                dist[nextE.to] = std::max(dist[nextE.to], std::min(INF, dist[nextE.from] + nextE.weight));
            }
        }
    }
    if (dist[nV - 1] == -INF) {
        printf(":(");
        return 0;
    }
    for (int i = 0; i < nV; i++) {
        for (Edge nextE : edges) {
            if (-INF != dist[nextE.from] && dist[nextE.to] < dist[nextE.from] + nextE.weight) {
                dist[nextE.to] = INF;
            }
        }
    }
    if (dist[nV - 1] == INF) {
        printf(":)");
    } else {
        printf("%d", dist[nV - 1]);
    }
    return 0;
}