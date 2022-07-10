#include <stdio.h>
#include <vector>

// Time complexity: O((n + q) * log(n))
// Space complexity: O(n)

int getGcd(int a, int b) {
	while (b > 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

std::vector<int> a;

struct Tree {
	
	std::vector<int> tree;

	void build(int v, int left, int right) {
		if (left == right) {
			tree[v] = a[left];
			return;
		}
		int mid = (left + right) / 2;
		build(2 * v, left, mid);
		build(2 * v + 1, mid + 1, right);
		tree[v] = getGcd(tree[2 * v], tree[2 * v + 1]);
	}

	Tree() {
		int n = 1;
		while (n < (int) a.size()) {
			n <<= 1;
		}
		a.resize(n);
		tree.resize(2 * n);
		build(1, 0, n - 1);
	}
	
	void updateTree(int v, int left, int right, int i, int val) {
		if (i < left || right < i) {
			return;
		}
		if (left == right) {
			tree[v] = val;
			return;
		}
		int mid = (left + right) / 2;
		updateTree(2 * v, left, mid, i, val);
		updateTree(2 * v + 1, mid + 1, right, i, val);
		tree[v] = getGcd(tree[2 * v], tree[2 * v + 1]);
	}

	void update(int i, int val) {
		updateTree(1, 0, (int) a.size() - 1, i, val);
	}

	int gcdTree(int v, int left, int right, int qLeft, int qRight) {
		if (qLeft <= left && right <= qRight) {
			return tree[v];
		}
		if (qRight < left || right < qLeft) {
			return 0;
		}
		int mid = (left + right) / 2;
		return getGcd(gcdTree(2 * v, left, mid, qLeft, qRight),  
			gcdTree(2 * v + 1, mid + 1, right, qLeft, qRight));
	}

	int gcd(int qLeft, int qRight) {
		return gcdTree(1, 0, (int) a.size() - 1, qLeft, qRight);
	}
};

int main() {
	int n;
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	Tree tree;
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int left, right;
		scanf("%d %d", &left, &right);
		printf("%d ", tree.gcd(left - 1, right - 1));
	}
	return 0;
}