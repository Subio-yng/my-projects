#include <stdio.h>
#include <vector>
#include <algorithm>
   
// Time complexity: O(nV^3)
// Space complexity: O(nV^2)
   
struct Edge {
   
    int from;
   
    int to;
   
    int weight;
};
   
int main() {
    const int UNDEF = 100000;
    const int INF = 1'000'000'000;
    int nV;
    scanf("%d", &nV);
    std::vector<Edge> edges;
    for (int from = 0; from < nV; from++) {
        for (int to = 0; to < nV; to++) {
            int weight;
            scanf("%d", &weight);
            if (weight != UNDEF) {
                edges.push_back({from, to, weight});
            }
        }
    }
    for (int curV = 0; curV < nV; curV++) {
        std::vector<int> prev(nV);
        std::vector<int> dist(nV, INF);
        dist[curV] = 0;
        for (int i = 1; i < nV; i++) {
            for (Edge nextE : edges) {
                if (dist[nextE.from] < INF) {
                    int newDist = dist[nextE.from] + nextE.weight;
                    if (newDist < dist[nextE.to]) {
                        dist[nextE.to] = newDist;
                        prev[nextE.to] = nextE.from;
                    }
                }
            }
        }
        for (Edge nextE : edges) {
            if (dist[nextE.from] < INF && dist[nextE.to] > dist[nextE.from] + nextE.weight) {
                prev[nextE.to] = nextE.from;
                int curTo = nextE.to;
                for (int i = 0; i < nV; i++) {
                    curTo = prev[curTo];
                }
                int endFrom = curTo;
                std::vector<int> way;
                do {
                    way.push_back(curTo);
                    curTo = prev[curTo];
                } while (curTo != endFrom);
                way.push_back(curTo);
                std::reverse(way.begin(), way.end());
                printf("YES\n");
                printf("%d\n", (int) way.size());
                for (int next : way) {
                    printf("%d ", next + 1);
                }
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}