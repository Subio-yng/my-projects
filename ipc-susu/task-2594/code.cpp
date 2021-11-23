#include <stdio.h>
#include <vector>
#include <stack>

// Time complexity: O(n)
// Space complexity: O(n)

std::vector<int> getPrefixStatistics(const std::vector<int> &a) {
	int n = (int) a.size();
	std::vector<int> count(n);
	std::stack<int> lastMinId;
	lastMinId.push(-1);
	for (int i = 0; i < n; i++) {
		while (lastMinId.top() != -1 && a[i] < a[lastMinId.top()]) {
			lastMinId.pop();
		}
		count[i] = i - 1 - lastMinId.top();
		lastMinId.push(i);
	}
	return count;
}

std::vector<int> getSuffixStatistics(const std::vector<int> &a) {
	int n = (int) a.size();
	std::vector<int> count(n);
	std::stack<int> lastMinId;
	lastMinId.push(n);
	for (int i = n - 1; i >= 0; i--) {
		while (lastMinId.top() != n && a[i] <= a[lastMinId.top()]) {
			lastMinId.pop();
		}
		count[i] = lastMinId.top() - 1 - i;
		lastMinId.push(i);
	}
	return count;
}

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> list(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	std::vector<int> countGreaterTIll = getPrefixStatistics(list);
	std::vector<int> countGreaterOrEqualAfter = getSuffixStatistics(list);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += 1LL * list[i] * (countGreaterOrEqualAfter[i] + 1) * (countGreaterTIll[i] + 1);
	}
	printf("%lld", sum);
	return 0;
}