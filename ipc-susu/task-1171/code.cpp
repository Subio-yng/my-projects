#include <bits/stdc++.h>

// Time complexity: O(n * sum)
// Space complexity: O(sum)

class BigInteger {

private:

    std::vector<int> num;

public:

    BigInteger(int n) {
        num.push_back(n);
    }

    BigInteger operator +(const BigInteger &tmp) const {
        BigInteger res = *this;
        BigInteger a = tmp;
        if ((int) res.num.size() < (int) a.num.size()) {
            std::swap(res, a);
        }
        static const int RANGE = 1'000'000'000;
        int i = 0;
        int j = 0;
        int plus = 0;
        while (j < (int) a.num.size()) {
            res.num[i] += a.num[j] + plus;
            plus = 0;
            if (res.num[i] >= RANGE) {
                res.num[i] -= RANGE;
                plus++;
            }
            j++;
            i++;
        }
        while (plus > 0 && i < (int) res.num.size()) {
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
        }
        return res;
    }

    void operator +=(const BigInteger &a) {
        *this = *this + a;
    }

    std::string toString() const {
        static const int SIZE_NUM = 9;
        std::string res;
        for (int i = (int) num.size() - 1; i >= 0; i--) {
            std::string cur = std::to_string(num[i]);
            if (i < (int) num.size() - 1) {
                for (int j = 0; j < SIZE_NUM - (int) cur.length(); j++) {
                    res += '0';
                }
            }
            res += cur;
        }
        return res;
    }
};

int main() {
    int n, sum;
    scanf("%d %d", &n, &sum);
    std::vector<BigInteger> prev(sum + 1, 0);
    std::vector<BigInteger> cur(sum + 1, 0);
    cur[0] = 1;
    for (int len = 1; len <= n; len++) {
        std::swap(cur, prev);
        for (int curSum = 0; curSum <= sum; curSum++) {
            cur[curSum] = 0;
            for (int last = 0; last <= std::min(9, curSum); last++) {
                cur[curSum] += prev[curSum - last];
            }
        }
    }
    printf("%s", cur[sum].toString().c_str());
    return 0;
}