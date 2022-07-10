#include <stdio.h>
#include <vector>

// Time complexity: O((n + q) * log(n))
// Space complexity: O(n)

int gcd(int a, int b) {
	while (b > 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

void buildTree(int v, int left, int right, std::vector<int> &tree, const std::vector<int> &a) {
	if (left == right) {
		tree[v] = a[left];
		return;
	}
	int mid = (left + right) / 2;
	buildTree(2 * v, left, mid, tree, a);
	buildTree(2 * v + 1, mid + 1, right, tree, a);
	tree[v] = gcd(tree[2 * v], tree[2 * v + 1]);
}

struct Tree {
	
	std::vector<int> tree;

	Tree(const std::vector<int> &a) {
		int size = (int) a.size();
		tree.resize(4 * size);
		buildTree(1, 0, size - 1, tree, a);
	}

	int gcdTree(int v, int left, int right, int qLeft, int qRight) {
		if (qLeft <= left && right <= qRight) {
			return tree[v];
		}
		if (qRight < left || right < qLeft) {
			return 0;
		}
		int mid = (left + right) / 2;
		return gcd(gcdTree(2 * v, left, mid, qLeft, qRight),  
			gcdTree(2 * v + 1, mid + 1, right, qLeft, qRight));
	}

	int getGcd(int qLeft, int qRight) {
		return gcdTree(1, 0, (int) tree.size() / 4 - 1, qLeft, qRight);
	}
};

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	Tree tree(a);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int left, right;
		scanf("%d %d", &left, &right);
		printf("%d ", tree.getGcd(left - 1, right - 1));
	}
	return 0;
}