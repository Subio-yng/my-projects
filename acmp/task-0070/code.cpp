#include <stdio.h>
#include <string>

// Time complexity: O(n + len(str))
// Space complexity: O(buf)

const int MAXSIZE = 1023;

void powerString(std::string &a, int n) {
	std::string temp = a;
	for (int i = 1; i < n; i++) {
		if ((int) temp.length() * (i + 1) >= MAXSIZE) {
			for (int j = 0; (int) temp.length() * i + j < MAXSIZE; j++) {
				a += temp[j];
			}
			break;
		}
		a += temp;
	}
}

int main() {
	freopen("intput.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char buf[1 + 1000];
	scanf("%s", &buf);
	std::string str(buf);
	int n;
	scanf("%d", &n);
	if (n > 0) {
		powerString(str, n);
		printf("%s", str.c_str());
	} else {
		std::string root = str;
		for (int i = -1; i > n; i--) {
			if ((int) root.length() == 1) {
				break;
			}
			root = root.substr(0, (int) root.length() >> 1);
		}
		std::string temp = root;
		powerString(temp, n * -1);
		if (temp == str) {
			printf("%s", root.c_str());
		} else {
			printf("NO SOLUTION");
		}
	}
	return 0;
}