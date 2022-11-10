#include <bits/stdc++.h>

// Time complexity: O(n * sum)
// Space complexity: O(n * sum)

class BigInteger {

private:

    int len;

    std::string num;

public:

    BigInteger(const std::string &str)
        : len((int) str.length())
        , num(str)
    {}

    void operator =(const std::string &str) {
        len = (int) str.length();
        num = str;
    }

    void operator += (const BigInteger &a) {
        int j = a.len - 1;
        int i = len - 1;
        int plus = 0;
        while (i >= 0 && j >= 0) {
            num[i] += a.num[j] - '0' + plus;
            plus = (num[i] - '0') / 10;
            while (num[i] > '9') {
                num[i] -= 10;
            }
            i--;
            j--;
        }
        if (j < 0 && plus == 0) {
            len = (int) num.length();
            return;
        }
        while (i >= 0 && plus > 0) {
            num[i] += plus;
            plus = (num[i] - '0') / 10;
            if (num[i] > '9') {
                num[i] -= 10;
            }
            i--;
        }
        std::reverse(num.begin(), num.end());
        while (j >= 0) {
            num.push_back(a.num[j] + plus);
            plus = (num.back() - '0') / 10;
            while (num.back() > '9') {
                num.back() -= 10;
            }
            j--;
        }
        if (plus > 0) {
            num.push_back(plus + '0');
        }
        std::reverse(num.begin(), num.end());
        len = (int) num.length();
    }

    void print() {
        printf("%s", num.c_str());
    }
};

int main() {
    int n, sum;
    scanf("%d %d", &n, &sum);
    std::vector<std::vector<BigInteger>> cnt(n + 1, std::vector<BigInteger>(sum + 1, BigInteger("0")));
    cnt[0][0] = "1";
    for (int len = 1; len <= n; len++) {
        for (int curSum = 0; curSum <= sum; curSum++) {
            for (int last = 0; last <= std::min(curSum, 9); last++) {
                cnt[len][curSum] += cnt[len - 1][curSum - last];
            }
        }
    }
    cnt[n][sum].print();
    return 0;
}