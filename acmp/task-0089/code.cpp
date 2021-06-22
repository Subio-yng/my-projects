#include <stdio.h>
#include <string>
#include <math.h>

// Time complexity: O(n)
// Space complexity: O(buf)

int readTime() {
	int h, m;
	scanf(" %d:%d", &h, &m);
	return h * 60 + m;
}

int divRound(int a, int b) {
	return (a + b / 2) / b;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int DAY = 24 * 60;
	const int DISTANCE = 650 * 60;
	int n;
	scanf("%d", &n);
	int bestTime = 1 + DAY;
	std::string fastest;
	for (int i = 0; i < n; i++) {
		char buf[1 + 50];
		scanf(" \"%[^\"]\"", &buf);
		int startTime = readTime();
		int endTime = readTime();
		int time = endTime - startTime;
		if (time <= 0) {
			time += DAY;
		}
		if (bestTime > time) {
			bestTime = time;
			fastest = buf;
		}
	}
	printf("The fastest train is \"%s\".\n", fastest.c_str());
	printf("Its speed is %d km/h, approximately.", divRound(DISTANCE, bestTime));
	return 0;
}
