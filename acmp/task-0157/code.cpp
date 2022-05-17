#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(len)
// Space complexity: O(len)

long long getFactorial(int n) {
	long long res = n;
	for (int i = 2; i < n; i++) {
		res *= i;
	}
	return res;
}

int main() {
	const int ALPHABET_SIZE = 26;
	char buf[1 + 15];
	scanf("%s", &buf);
	std::string str(buf);
	std::vector<int> words(ALPHABET_SIZE, 0);
	for (char next : str) {
		words[next - 'a']++;
	}
	long long ans = getFactorial((int) str.length());
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (words[i] > 1) {
			ans /= getFactorial(words[i]);
		}
	}
	printf("%lld", ans);
	return 0;
}