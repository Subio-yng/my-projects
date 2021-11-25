#include <stdio.h>
#include <algorithm>
#include <map>

// Time complexity: O((n + m) * log(n))
// Space complexity: O(n)

int main() {
	int n;
	scanf("%d", &n);
	std::map<int, int> colonies;
	for (int i = 0; i < n; i++) {
		scanf("%d", &colonies[i]);
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int id, val;
		scanf("%d %d", &id, &val);
		id--;
		auto curColony = colonies.lower_bound(id);
		long long sum = 0;
		int dif = 0;
		while (val > 0) {
			if (curColony == colonies.end()) {
				curColony = colonies.lower_bound(0);
			}
			if (curColony->first < id) {
				dif += curColony->first + n - id;
			} else {
				dif += curColony->first - id;
			}
			sum += 1LL * std::min(curColony->second, val) * dif;
			id = curColony->first;
			if (curColony->second < val) {
				val -= curColony->second;
				colonies.erase(curColony->first);
				curColony = colonies.lower_bound(id);
			} else {
				curColony->second -= val;
				val = 0;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}