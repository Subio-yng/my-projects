#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n + nQ * log(n))
// Space complexity: O(n)

struct Place {

    int pos;

    int cost;

    static Place read() {
        int p, c;
        scanf("%d %d", &p, &c);
        return {p, c};
    }
};

Place binSeach(const std::vector<Place> &list, int qPos, bool type) {
    int left = -1;
    int right = (int) list.size();
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (list[mid].pos < qPos || list[mid].pos == qPos && type) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (type && left != -1 || right == (int) list.size()) {
        return list[left];
    }
    return list[right];
}

int main() {
    int n, nQ, cost;
    scanf("%d %d %d", &n, &nQ, &cost);
    std::vector<Place> list(n);
    for (int i = 0; i < n; i++) {
        list[i] = Place::read();
    }
    std::sort(list.begin(), list.end(), [](const Place &left, const Place &right) {
        return left.pos < right.pos;
    });
    std::vector<Place> bestLeft;
    bestLeft.push_back(list[0]);
    long long curCost = list[0].cost;
    for (int i = 1; i < n; i++) {
        curCost += 1LL * (list[i].pos - list[i - 1].pos) * cost;
        if (list[i].cost < curCost) {
            bestLeft.push_back(list[i]);
            curCost = list[i].cost;
        }
    }
    std::vector<Place> bestRight;
    bestRight.push_back(list.back());
    curCost = list.back().cost;
    for (int i = n - 2; i >= 0; i--) {
        curCost += 1LL * (list[i + 1].pos - list[i].pos) * cost;
        if (list[i].cost < curCost) {
            bestRight.push_back(list[i]);
            curCost = list[i].cost;
        }
    }
    std::reverse(bestRight.begin(), bestRight.end());
    const long long INF = 8'000'000'000'000'000'000;
    for (int i = 0; i < nQ; i++) {
        int qPos;
        scanf("%d", &qPos);
        Place left = binSeach(bestLeft, qPos, true);
        Place right = binSeach(bestRight, qPos, false);
        long long bestDist = INF;
        if (left.pos <= qPos) {
            bestDist = left.cost + 1LL * (qPos - left.pos) * cost;
        }
        if (qPos <= right.pos) {
            bestDist = std::min(bestDist, right.cost + 1LL * (right.pos - qPos) * cost);
        }
        printf("%lld\n", bestDist);
    }
    return 0;
}