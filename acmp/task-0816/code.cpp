#include <bits/stdc++.h>

// Time complexity: O(nQ * log(nSets) * log(maxNum))
// Space complexity: O(nSets + maxNum)

void printSet(const std::set<int> &a) {
    if (a.empty()) {
        printf("-1\n");
    } else {
        for (int next : a) {
            printf("%d ", next + 1);
        }
        printf("\n");
    }
}

int main() {
    int nNums, nSets;
    scanf("%d %d", &nNums, &nSets);
    std::vector<std::set<int>> num(nNums);
    std::vector<std::set<int>> set(nSets);
    int nQ;
    scanf("%d", &nQ);
    char buf[1 + 10];
    for (int i = 0; i < nQ; i++) {
        scanf(" %s", &buf);
        std::string cmd(buf);
        if (cmd == "ADD") {
            int qNum, qSet;
            scanf("%d %d", &qNum, &qSet);
            qNum--;
            qSet--;
            num[qNum].insert(qSet);
            set[qSet].insert(qNum);
        } else if (cmd == "LISTSET") {
            int qSet;
            scanf("%d", &qSet);
            printSet(set[qSet - 1]);
        } else {
            int qNum;
            scanf("%d", &qNum);
            printSet(num[qNum - 1]);
        }
    }
    return 0;
}