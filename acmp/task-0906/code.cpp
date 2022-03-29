#include <stdio.h>
#include <map>

// Time complexity: O(1)
// Space complexity: O(1)

struct State {

	int a;

	int b;

	int c;

	bool operator <(const State &right) const {
		if (a == right.a) {
			if (b == right.b) {
				return c < right.c;
			}
			return b < right.b;
		}
		return a < right.a;
	}
};

int function(int a, int b, int c, std::map<State, int> &memory) {
	State cur = {a, b, c};
	if (memory.find(cur) == memory.end()) {
		if (a <= 0 || b <= 0 || c <= 0) {
			memory[cur] = 1;
		} else if (a > 20 || b > 20 || c > 20) {
			memory[cur] = function(20, 20, 20, memory);
		} else if (a < b && b < c) {
			memory[cur] = function(a, b, c - 1, memory) +
				function(a, b - 1, c - 1, memory) -
				function(a, b - 1, c, memory);
		} else {
			memory[cur] = function(a - 1, b, c, memory) +
				function(a - 1, b - 1, c, memory) +
				function(a - 1, b, c - 1, memory) -
				function(a - 1, b - 1, c - 1, memory);
		}
	}
	return memory[cur];
}

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	std::map<State, int> memory;
	printf("%d", function(a, b, c, memory));
	return 0;
}