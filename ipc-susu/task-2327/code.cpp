#include <bits/stdc++.h>

// Time complexity: O(n * (log(n) + maxCost * nTypes))
// Space complexity: O(n + nTypes * maxCost)

struct Comp {

    int cost;

    int score;

    int id;
};

int main() {
    int nTypes, n;
    scanf("%d %d", &nTypes, &n);
    std::vector<std::vector<Comp>> comps(nTypes);
    for (int i = 0; i < n; i++) {
        int cost, score, type;
        scanf("%d %d %d", &cost, &score, &type);
        comps[type - 1].push_back({cost, score, i});
    }
    int startCost = 0;
    int startScore = 0;
    int maxSize = 0;
    for (int i = 0; i < nTypes; i++) {
        std::sort(comps[i].begin(), comps[i].end(), [](const Comp &left, const Comp &right) {
            if (left.cost == right.cost) {
                return left.score > right.score;
            }
            return left.cost < right.cost;
        });
        maxSize = std::max(maxSize, (int) comps[i].size());
        startCost += comps[i][0].cost;
        startScore += comps[i][0].score;
    }
    int maxCost;
    scanf("%d", &maxCost);
    if (startCost > maxCost) {
        printf("-1");
        return 0;
    }
    std::vector<int> sum(maxCost + 1, 0);
    std::vector<std::vector<int>> id(maxCost + 1, std::vector<int>(nTypes, 0));
    std::vector<bool> isFull(maxCost + 1, false);
    sum[startCost] = startScore;
    isFull[startCost] = true;
    for (int i = 1; i < maxSize; i++) {
        for (int curCost = startCost; curCost <= maxCost; curCost++) {
            if (!isFull[curCost]) {
                continue;
            }
            for (int iType = 0; iType < nTypes; iType++) {
                if (i >= (int) comps[iType].size()) {
                    continue;
                }
                int nextCost = curCost
                               - comps[iType][id[curCost][iType]].cost
                               + comps[iType][i].cost;
                int nextScore = sum[curCost]
                                - comps[iType][id[curCost][iType]].score
                                + comps[iType][i].score;
                if (nextCost <= maxCost && nextScore > sum[nextCost]) {
                    sum[nextCost] = nextScore;
                    id[nextCost] = id[curCost];
                    id[nextCost][iType] = i;
                    isFull[nextCost] = true;
                }
            }
        }
    }
    int bestCost = startCost;
    for (int i = startCost + 1; i <= maxCost; i++) {
        if (sum[bestCost] < sum[i]) {
            bestCost = i;
        }
    }
    printf("%d\n", sum[bestCost]);
    for (int i = 0; i < nTypes; i++) {
        printf("%d ", comps[i][id[bestCost][i]].id + 1);
    }
    return 0;
}