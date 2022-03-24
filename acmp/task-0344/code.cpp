#include <stdio.h>
#include <vector>
#include <algorithm>
 
// Time complexity: O(n * log(n))
// Space complexity: O(n)
 
struct Point {
 
    int val;
     
    int id;
};
 
int main() {
    int n;
    scanf("%d", &n);
    std::vector<Point> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i].val);
        list[i].id = i + 1;
    }
    std::sort(list.begin(), list.end(), [](const Point &left, const Point &right) {
        return left.val < right.val;
    });
    int minDiff = list[1].val - list[0].val;
    int id1 = list[0].id;
    int id2 = list[1].id;
    for (int i = 2; i < n; i++) {
        int curDiff = list[i].val - list[i - 1].val;
        if (curDiff < minDiff) {
            minDiff = curDiff;
            id1 = list[i - 1].id;
            id2 = list[i].id;
        }
    }
    printf("%d\n", minDiff);
    printf("%d %d", id1, id2);
    return 0;
}