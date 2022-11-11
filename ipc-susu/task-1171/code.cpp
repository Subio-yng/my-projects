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

    void operator +=(const BigInteger &a) {
        static int RANGE = 1'000'000'000;
        int i = len - 1;
        int j = a.len - 1;
        int plus = 0;
        while (i >= 0 && j >= 0) {
            num[i] += a.num[j] + plus;
            plus = 0;
            if (num[i] >= RANGE) {
                num[i] -= RANGE;
                plus++;
            }
            j--;
            i--;
        }
        if (j < 0 && plus == 0) {
            return;
        }
        while (j >= 0) {
            num.insert(num.begin(), a.num[j] + plus);
            plus = 0;
            if (num.front() >= RANGE) {
                num.front() -= RANGE;
                plus++;
            }
            j--;
        }
        while (i >= 0 && plus > 0) {
            num[i] += plus;
            plus = 0;
            if (num[i] >= RANGE) {
                num[i] -= RANGE;
                plus++;
            }
        }
        if (plus > 0) {
            num.insert(num.begin(), plus);
        }
        len = (int) num.size();
    }

    std::string toString() const {
        std::string res = std::to_string(num.front());
        for (int i = 1; i < len; i++) {
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