#include <stdio.h>
#include <vector>
#include <map>
 
// Time complexity: O(n * log(n))
// Space complexity: O(n)

struct Edge {

    int left;

    int right;
};

int main() {
    int n;
    scanf("%d", &n);
    std::map<int, Edge> list;
    for (int coord = 0; coord < n; coord++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (list[y].left == 0) {
            list[y].left = x;
        }
        list[y].right = std::max(list[y].right, x);
        list[y].left = std::min(list[y].left, x);
    }
    std::vector<Edge> minWay((int) list.size());
    minWay[0].right = list.begin()->first + list.begin()->second.right - 2;
    minWay[0].left = minWay[0].right + list.begin()->second.right - list.begin()->second.left;
    auto prevLvl = list.begin();
    auto curLvl = list.upper_bound(prevLvl->first);
    for (int i = 1; curLvl != list.end(); i++, curLvl++) {
        minWay[i].right = curLvl->first - prevLvl->first;
        minWay[i].left = curLvl->first - prevLvl->first;
        if (curLvl->second.left >= prevLvl->second.right) {
            minWay[i].right += std::min(minWay[i - 1].right + curLvl->second.right - prevLvl->second.right,
                                        minWay[i - 1].left + curLvl->second.right - prevLvl->second.left);
            minWay[i].left = minWay[i].right + curLvl->second.right - curLvl->second.left;
        } else if (curLvl->second.right <= prevLvl->second.left) {
            minWay[i].left += std::min(minWay[i - 1].left + prevLvl->second.left - curLvl->second.left,
                                       minWay[i - 1].right + prevLvl->second.right - curLvl->second.left);
            minWay[i].right = minWay[i].left + curLvl->second.right - curLvl->second.left;
        } else {
            minWay[i].right += curLvl->second.right - curLvl->second.left +
                               std::min(minWay[i - 1].left + abs(prevLvl->second.left - curLvl->second.left),
                                        minWay[i - 1].right + prevLvl->second.right - curLvl->second.left);
            minWay[i].left += curLvl->second.right - curLvl->second.left +
                              std::min(minWay[i - 1].right + abs(curLvl->second.right - prevLvl->second.right),
                                       minWay[i - 1].left + curLvl->second.right - prevLvl->second.left);
        }
        prevLvl = curLvl;
    }
    printf("%d", std::min(minWay.back().left, minWay.back().right));
    return 0;
}