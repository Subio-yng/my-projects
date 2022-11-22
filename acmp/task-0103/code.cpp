#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

class BigInteger {

private:

    static const int SIZE_NUM = 9;

    std::vector<int> num;

public:

    BigInteger(const std::string &str) {
        int right = (int) str.length();
        while (right > 0) {
            int left = std::max(0, right - SIZE_NUM);
            num.push_back(atoi(str.substr(left, (right - left)).c_str()));
            right -= SIZE_NUM;
        }
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
    char buf[1 + 100];
    scanf(" %s", &buf);
    BigInteger a(buf);
    scanf(" %s", &buf);
    a += BigInteger(buf);
    printf("%s", a.toString().c_str());
    return 0;
}