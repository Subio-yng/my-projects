#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(len(str))
// Space complexity: O(buf)

std::vector<int> getPrefixFunction(std::string sample) {
	std::vector<int> p((int) sample.size(), 0);
	for (int i = 1; i < sample.length(); i++) {
		int prev = p[i - 1];
		while (prev > 0 && sample[i] != sample[prev]) {
			prev = p[prev - 1];
		}
		if (sample[i] == sample[prev]) {
			prev++;
		}
		p[i] = prev;
	}
	return p;
}

int main() {
	char buf[1 + 10000];
	scanf("%s", &buf);
	std::vector<int> pStr1 = getPrefixFunction(buf);
	std::string str1(buf);
	scanf("%s", &buf);
	std::string str2(buf);
	str2 += str2;
	int j = 0;
	for (int i = 0; i < (int) str2.length(); i++) {
		if (str1[j] == str2[i]) {
			j++;
			if (j == (int) str1.length()) {
				printf("%d", i - j + 1);
				return 0;
			}
		} else if (j != 0) {
			j = pStr1[j - 1];
			i--;
		}
	}
	printf("-1");
	return 0;
}