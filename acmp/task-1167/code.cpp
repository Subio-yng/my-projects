#include <stdio.h>
#include <algorithm>
#include <string>

// Time complexity: O(len)
// Space complexity: O(len)

int function(const std::string &str) {
	if ('0' <= str.front() && str.front() <= '9') {
		return str.front() - '0';
	}
	int len = (int) str.length();
	int pointId = 0;
	int bracket = 0;
	for (int i = 3; i < len; i++) {
		if (str[i] == '(') {
			bracket++;
		}
		if (str[i] == ')') {
			bracket--;
		}
		if (str[i] == ',' && bracket == 0) {
			pointId = i;
			break;
		}
	}
	std::string first = str.substr(2, pointId - 2);
	std::string second = str.substr(pointId + 1, len - pointId - 1);
	if (str.front() == 'M') {
		return std::max(function(first), function(second));
	}
	if (str.front() == 'm') {
		return std::min(function(first), function(second));
	}
}

int main() {
	char buf[1 + 1000];
	scanf("%s", &buf);
	printf("%d", function(buf));
	return 0;
}