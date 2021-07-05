#include <stdio.h>
#include <string>
#include <vector>

// Time complexity: O(n * m)
// Space complexity: O(n)

struct Array {

	std::vector<int> vec;

	int get(int id) {
		return vec[id];
	}

	void update(int left, int right, int val) {
		for (int i = left; i <= right; i++) {
			vec[i] = val;
		}
	}

	void add(int left, int right, int val) {
		for (int i = left; i <= right; i++) {
			vec[i] += val;
		}
	}

	int rsq(int left, int right) {
		int sum = 0;
		for (int i = left; i <= right; i++) {
			sum += vec[i];
		}
		return sum;
	}

	int rmq(int left, int right) {
		int min = vec[left];
		for (int i = left; i <= right; i++) {
			if (min > vec[i]) {
				min = vec[i];
			}
		}
		return min;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	Array list;
	list.vec.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list.vec[i]);
	}
	int operations;
	scanf("%d", &operations);
	for (int i = 0; i < operations; i++) {
		char buf[1 + 10];
		scanf(" %s", &buf);
		std::string inquiry(buf);
		if (inquiry == "get") {
			int id;
			scanf("%d", &id);
			id--;
			printf("%d\n", list.get(id));
		}
		if (inquiry == "update") {
			int left, right, val;
			scanf("%d %d %d", &left, &right, &val);
			left--;
			right--;
			list.update(left, right, val);
		}
		if (inquiry == "add") {
			int left, right, val;
			scanf("%d %d %d", &left, &right, &val);
			left--;
			right--;
			list.add(left, right, val);
		}
		if (inquiry == "rsq") {
			int left, right;
			scanf("%d %d", &left, &right);
			left--;
			right--;
			printf("%d\n", list.rsq(left, right));
		}
		if (inquiry == "rmq") {
			int left, right;
			scanf("%d %d", &left, &right);
			left--;
			right--;
			printf("%d\n", list.rmq(left, right));
		}
	}
	return 0;
}