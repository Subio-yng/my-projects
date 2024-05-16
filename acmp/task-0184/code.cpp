#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int getDays(int month) {
    if (month == 2) {
        return 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int main() {
    const int N_MONTHS = 12;
    std::vector<int> prevDays(N_MONTHS, 0);
    for (int i = 1; i < N_MONTHS; i++) {
        prevDays[i] = prevDays[i - 1] + getDays(i);
    }
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int day, month, hour, minute;
        scanf("%d.%d. %d:%d", &day, &month, &hour, &minute);
        a[i] = ((prevDays[month - 1] + day - 1) * 8 + hour - 10) * 60 + minute;
    }
    std::sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += a[i] - a[i - 1] + 1;
    }
    printf("%d:%02d", sum / 60, sum % 60);
    return 0;
}