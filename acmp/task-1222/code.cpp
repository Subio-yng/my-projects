#include <stdio.h>
#include <map>
#include <string>

// Time complexity: O(n)
// Space complexity: O(n)

struct Subscriber {

	std::string name;

	std::string address;
};

int main() {
	int n, inquiries;
	scanf("%d %d", &n, &inquiries);
	std::map<int, Subscriber> directory;
	for (int i = 0; i < n; i++) {
		int phoneNumber;
		scanf("%d", &phoneNumber);
		char buf[1 + 100];
		scanf(" %[^\n]s", &buf);
		directory[phoneNumber].name = buf;
		scanf(" %[^\n]s", &buf);
		directory[phoneNumber].address = buf;
	}
	for (int i = 0; i < inquiries; i++) {
		int phoneNumber;
		scanf("%d", &phoneNumber);
		printf("%s (%s)\n", directory[phoneNumber].name.c_str(), directory[phoneNumber].address.c_str());
	}
	return 0;
}