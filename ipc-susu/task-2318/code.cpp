#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int start, end, startPos, endPos;
    scanf("%d %d %d %d", &start, &end, &startPos, &endPos);
    int cnt = 0;
    if (std::min(endPos, startPos) <= start && start <= std::max(endPos, startPos) &&
        (endPos - startPos) * (end - start) > 0
    ) {
        cnt += abs(startPos - end);
        if (std::min(start, end) < endPos && endPos < std::max(start, end)) {
            cnt++;
        }
    } else {
        cnt += abs(startPos - endPos) + 1 + abs(endPos - start) + abs(start - end);
        if (start == endPos) {
            cnt--;
        }
    }
    printf("%d", cnt + 2);
    return 0;
}