#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(n * lessons)
// Space complexity: O(n * lessons)

struct Student {

    std::string name;

    std::vector<int> evaluations;

    double averageScore;
};

int main() {
    int n, lessons;
    scanf("%d %d", &n, &lessons);
    std::vector<Student> classroom(n);
    double maxAver1 = -1;
    double maxAver2 = -1;
    double maxAver3 = -1;
    for (int i = 0; i < n; i++) {
        char buf[1 + 100];
        scanf(" %[^\n]s", &buf);
        classroom[i].name = buf;
        classroom[i].evaluations.resize(lessons);
        int sum = 0;
        for (int j = 0; j < lessons; j++) {
            scanf("%d", &classroom[i].evaluations[j]);
            sum += classroom[i].evaluations[j];
        }
        double aver = sum * 1.0 / lessons;
        classroom[i].averageScore = aver;
        if (aver > maxAver1) {
            maxAver3 = maxAver2;
            maxAver2 = maxAver1;
            maxAver1 = aver;
        } else if (aver > maxAver2) {
            maxAver3 = maxAver2;
            maxAver2 = aver;
        } else if (aver > maxAver3) {
            maxAver3 = aver;
        }
    }
    for (int i = 0; i < n; i++) {
        if (classroom[i].averageScore >= maxAver3) {
            printf("%s (", classroom[i].name.c_str());
            for (int j = 0; j < lessons; j++) {
                if (j != 0) {
                    printf(" ");
                }
                printf("%d", classroom[i].evaluations[j]);
            }
            printf(")\n");
        }
    }
    return 0;
}