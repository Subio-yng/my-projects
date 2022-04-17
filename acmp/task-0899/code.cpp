#include <stdio.h>
#include <string>
#include <stack>

char getOppositeBracket(char a) {
	if (a == ')') {
		return '(';
	} else if (a == ']') {
		return '[';
	} else if (a == '}') {
		return '{';
	} else {
		throw 1;
	}
}

bool checkLine(const std::string &str) {
	std::stack<char> last;
	for (char cur : str) {
		if (last.empty() || cur == '(' || cur == '[' || cur == '{') {
			last.push(cur);
		} else if (last.top() == getOppositeBracket(cur)) {
			last.pop();
		} else {
			return false;
		}
	}
	return last.empty();
}

int main() {
	char buf[1 + 255] = {};
	while (scanf("%255s", &buf) != EOF) {
		if (checkLine(buf)) {
			printf("0");
		} else {
			printf("1");
		}
	}
	return 0;
}