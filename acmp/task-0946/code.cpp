#include <stdio.h>
#include <deque>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::deque<int> shelf;
    for (int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);
        if (operation == 1) {
            int val;
            scanf("%d", &val);
            shelf.push_front(val);
        } else if (operation == 2) {
            int val;
            scanf("%d", &val);
            shelf.push_back(val);
        } else if (operation == 3) {
            printf("%d ", shelf.front());
            shelf.pop_front();
        } else {
            printf("%d ", shelf.back());
            shelf.pop_back();
        }
    }
    return 0;
}