#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(n * inquiries)
// Space complexity: O(n)

struct Subscriber {

	int phoneNumber;

	std::string name;

	std::string address;
};

int main() {
	int n, inquiries;
	scanf("%d %d", &n, &inquiries);
	std::vector<Subscriber> directory(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &directory[i].phoneNumber);
		char buf[1 + 100];
		scanf(" %[^\n]s", &buf);
		directory[i].name = buf;
		scanf(" %[^\n]s", &buf);
		directory[i].address = buf;
	}
	for (int i = 0; i < inquiries; i++) {
		int number;
		scanf("%d", &number);
		for (int j = 0; j < n; j++) {
			if (directory[j].phoneNumber == number) {
				printf("%s (%s)\n", directory[j].name.c_str(), directory[j].address.c_str());
				break;
			}
		}
	}
	return 0;
}