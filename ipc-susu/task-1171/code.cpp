#include <bits/stdc++.h>

// Time complexity: O(n * sum)
// Space complexity: O(n * sum)

class BigInteger {

private:

    int len;

    std::vector<int> num;

public:

    BigInteger(int n) {
        num.push_back(n);
        len = 1;
    }

    BigInteger operator +(const BigInteger &a) const {
        BigInteger res = *this;
        static int RANGE = 1'000'000'000;
        int i = 0;
        int j = 0;
        int plus = 0;
        while (j < a.len) {
            res.num[i] += a.num[j] + plus;
            plus = 0;
            if (res.num[i] >= RANGE) {
                res.num[i] -= RANGE;
                plus++;
            }
            j++;
            i++;
        }
        while (plus > 0 && i < len) {
            res.num[i] += plus;
            plus = 0;
            if (res.num[i] >= RANGE) {
                res.num[i] -= RANGE;
                plus++;
            }
            i++;
        }
        if (plus > 0) {
            res.num.push_back(plus);
            res.len++;
        }
        return res;
    }

    void operator +=(const BigInteger &a) {
        if (len > a.len) {
            *this = *this + a;
        } else {
            *this = a + *this;
        }
    }

    std::string toString() const {
        std::string res = std::to_string(num.back());
        for (int i = len - 2; i >= 0; i--) {
            std::string cur = std::to_string(num[i]);
            for (int j = 0; j <= 8 - (int) cur.length(); j++) {
                res += '0';
            }
            res += cur;
        }
        return res;
    }
};

int main() {
    int n, sum;
    scanf("%d %d", &n, &sum);
    std::vector<std::vector<BigInteger>> cnt(n + 1, std::vector<BigInteger>(sum + 1, 0));
    cnt[0][0] = 1;
    for (int len = 1; len <= n; len++) {
        for (int curSum = 0; curSum <= sum; curSum++) {
            for (int last = 0; last <= std::min(curSum, 9); last++) {
                cnt[len][curSum] += cnt[len - 1][curSum - last];
            }
        }
    }
    printf("%s", cnt[n][sum].toString().c_str());
    return 0;
}