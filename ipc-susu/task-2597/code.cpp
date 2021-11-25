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
		int idColony, valColony;
		scanf("%d %d", &idColony, &valColony);
		idColony--;
		auto curColony = colonies.lower_bound(idColony);
		long long sum = 0;
		int diff = 0;
		while (valColony > 0) {
			if (curColony == colonies.end()) {
				curColony = colonies.lower_bound(0);
			}
			int curIdColony = curColony->first;
			int &curValColony = curColony->second;
			if (curIdColony < idColony) {
				diff += curIdColony + n - idColony;
			} else {
				diff += curIdColony - idColony;
			}
			sum += 1LL * std::min(curValColony, valColony) * diff;
			idColony = curIdColony;
			if (curValColony < valColony) {
				valColony -= curValColony;
				colonies.erase(curIdColony);
				curColony = colonies.lower_bound(idColony);
			} else {
				curValColony -= valColony;
				valColony = 0;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}