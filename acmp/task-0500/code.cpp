#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

struct Agent {

	int age;

	int disclosure;
};

int main() {
	int n;
	scanf("%d", &n);
	std::vector<Agent> list(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &list[i].age, &list[i].disclosure);
	}
	std::sort(list.begin(), list.end(), [](const Agent &left, const Agent &right) {
		return left.age < right.age;
	});
	std::vector<int> minSumDisclosure(n);
	minSumDisclosure[0] = list[1].disclosure;
	minSumDisclosure[1] = list[1].disclosure;
	for (int i = 2; i < n; i++) {
		minSumDisclosure[i] += list[i].disclosure + std::min(minSumDisclosure[i - 1], minSumDisclosure[i - 2]);
	}
	printf("%d", minSumDisclosure[n - 1]);
	return 0;
}