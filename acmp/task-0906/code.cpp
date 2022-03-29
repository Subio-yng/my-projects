#include <stdio.h>
#include <map>

// Time complexity: O(1)
// Space complexity: O(1)

struct Cell {

	int a;

	int b;

	int c;

	 bool operator <(const Cell &right) const {
		if (this->a == right.a) {
			if (this->b == right.b) {
				return this->c < right.c;
			}
			return this->b < right.b;
		}
		return this->a < right.a;
	}

	bool operator !=(const Cell &right) const {
		if (this->a == right.a) {
			if (this->b == right.b) {
				return this->c != right.c;
			}
			return true;
		}
		return true;
	}
};

int function(int a, int b, int c, std::map<Cell, int> &memory) {
	Cell cur = {a, b, c};
	if (memory.lower_bound(cur) == memory.end() || 
		memory.lower_bound(cur)->first.operator!=(cur)
	) {
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
	std::map<Cell, int> memory;
	printf("%d", function(a, b, c, memory));
	return 0;
}