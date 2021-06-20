#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
	std::vector<int> route(100, -1);
    int maxTime = 0;
    for (int i = 0; i < n; i++) {
		int bus;
		scanf("%d", &bus);
		if (route[bus - 1] != -1 && i - route[bus - 1] > maxTime) {
			maxTime = i - route[bus - 1];
        }
		route[bus - 1] = i;
    }
    printf("%d", maxTime);
    return 0;
}