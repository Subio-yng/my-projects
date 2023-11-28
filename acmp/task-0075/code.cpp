#include <bits/stdc++.h>

class BigInteger {

private:

    static const int MOD = 1'000'000'000;

    static const int CELL_SIZE = 9;

    short sign;

    std::vector<int> value;

    void addResidue(int last, int residue) {
        while (0 < residue && last < (int) value.size()) {
            value[last] += residue;
            residue = 0;
            if (value[last] >= MOD) {
                value[last] -= MOD;
                residue = 1;
            }
            last++;
        }
        if (0 < residue) {
            value.push_back(residue);
        }
    }

public:

    static const BigInteger ZERO() {
        return valueOf(0);
    }

    static const BigInteger ONE() {
        return valueOf(1);
    }

    static const BigInteger TEN() {
        return valueOf(10);
    }

    BigInteger()
        : sign(1)
    {}

    BigInteger(const short &setSign, const std::vector<int> &setValue)
        : sign(setSign)
        , value(setValue)
    {}

    static BigInteger valueOf(long long num) {
        short sign = 1;
        if (num < 0) {
            sign = -1;
            num *= -1;
        }
        std::vector<int> value(1, num % MOD);
        if (num >= MOD) {
            value.push_back(num / MOD);
        }
        return {sign, value};
    }

    static BigInteger valueOf(const std::string &str) {
        short sign = 1;
        int last = 0;
        if (str[last] == '-') {
            sign = -1;
            last = 1;
        }
        std::vector<int> value;
        int right = (int) str.length();
        while (right >= last) {
            int left = std::max(0, right - CELL_SIZE);
            value.push_back(std::abs(atoi(str.substr(left, right - left).c_str())));
            right -= CELL_SIZE;
        }
        if ((int) value.size() > 1 && value.back() == 0) {
            value.pop_back();
        }
        return {sign, value};
    }

    void operator =(const BigInteger &a) {
        sign = a.sign;
        value = a.value;
    }

    bool operator ==(const BigInteger &a) const {
        return sign == a.sign && value == a.value;
    }

    bool operator <(const BigInteger &a) const {
        if ((int) value.size() != (int) a.value.size() || sign != a.sign) {
            return sign * value.size() < a.sign * a.value.size();
        }
        for (int i = (int) value.size() - 1; i >= 0; i--) {
            if (value[i] != a.value[i]) {
                return sign * value[i] < a.sign * a.value[i];
            }
        }
        return false;
    }

    bool operator <=(const BigInteger &a) const {
        return *this == a || *this < a;
    }

    bool operator >(const BigInteger &a) const {
        return a < *this;
    }

    bool operator >=(const BigInteger &a) const {
        return a <= *this;
    }

    static BigInteger abs(const BigInteger &a) {
        return {a.sign * a.sign, a.value};
    }

    BigInteger operator +(const BigInteger &a) const {
        if (sign != a.sign) {
            return *this - -a;
        }
        if (value.size() < a.value.size()) {
            return a + *this;
        }
        BigInteger res = *this;
        int residue = 0;
        int last = 0;
        while (last < (int) a.value.size()) {
            res.value[last] += a.value[last] + residue;
            residue = 0;
            if (res.value[last] >= MOD) {
                res.value[last] -= MOD;
                residue = 1;
            }
            last++;
        }
        res.addResidue(last, residue);
        return res;
    }

    BigInteger operator +(long long num) const {
        return *this + valueOf(num);
    }

    void operator +=(const BigInteger &a) {
        *this = *this + a;
    }

    void operator +=(long long num) {
        *this = *this + num;
    }

    BigInteger operator -(const BigInteger &a) const {
        if (sign != a.sign) {
            return *this + -a;
        }
        if (*this == a) {
            return ZERO();
        }
        if (abs(*this) < abs(a)) {
            return -(a - *this);
        }
        BigInteger res = *this;
        int last = 0;
        while (last < (int) a.value.size()) {
            res.value[last] -= a.value[last];
            if (res.value[last] < 0) {
                res.value[last] += MOD;
                res.value[last + 1]--;
            }
            last++;
        }
        while (1 < (int) res.value.size() && res.value.back() == 0) {
            res.value.pop_back();
        }
        return res;
    }

    BigInteger operator -(long long num) const {
        return *this - valueOf(num);
    }

    void operator -=(const BigInteger &a) {
        *this = *this - a;
    }

    void operator -=(long long num) {
        *this = *this - num;
    }

    BigInteger operator -() const {
        return {-1 * sign, value};
    }

    BigInteger operator --() {
        *this -= ONE();
        return *this;
    }

    BigInteger operator ++() {
        *this += ONE();
        return *this;
    }

    BigInteger operator --(int) {
        *this -= ONE();
        return *this;
    }

    BigInteger operator ++(int) {
        *this += ONE();
        return *this;
    }

    BigInteger operator *(const BigInteger &a) const {
        if (value.size() < a.value.size()) {
            return a * *this;
        }
        BigInteger res = ZERO();
        for (int i = 0; i < (int) a.value.size(); i++) {
            BigInteger cur;
            for (int j = i; j > 0; j--) {
                cur.value.push_back(0);
            }
            int last = 0;
            int residue = 0;
            while (last < (int) value.size()) {
                long long mult = 1LL * value[last] * a.value[i] + residue;
                cur.value.push_back(mult % MOD);
                residue = mult / MOD;
                last++;
            }
            cur.addResidue((int) cur.value.size(), residue);
            res += cur;
        }
        while (1 < (int) res.value.size() && res.value.back() == 0) {
            res.value.pop_back();
        }
        res.sign = sign * a.sign;
        return res;
    }

    BigInteger operator *(long long num) const {
        return *this * valueOf(num);
    }

    void operator *=(const BigInteger &a) {
        *this = *this * a;
    }

    void operator *=(long long num) {
        *this = *this * num;
    }

    BigInteger operator /(const BigInteger &b) const {
        if (b == ZERO()) {
            throw 1;
        }
        if (abs(*this) < abs(b)) {
            return ZERO();
        }
        BigInteger a;
        int last = (int) value.size() - (int) b.value.size();
        for (int i = last; i < (int) value.size(); i++) {
            a.value.push_back(value[i]);
        }
        if (a < b) {
            last--;
            a.value.insert(a.value.begin(), value[last]);
        }
        std::vector<int> res;
        while (true) {
            int left = 0;
            int right = MOD + 1;
            while (left + 1 < right) {
                int mid = (left + right) >> 1;
                if (a < b * mid) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            a -= b * left;
            res.push_back(left);
            last--;
            if (last < 0) {
                break;
            }
            if (a.value.back() == 0) {
                a.value.pop_back();
            }
            a.value.insert(a.value.begin(), value[last]);
        }
        std::reverse(res.begin(), res.end());
        return {sign * b.sign, res};
    }

    BigInteger operator /(long long num) const {
        return *this / valueOf(num);
    }

    void operator /=(const BigInteger &a) {
        *this = *this / a;
    }

    void operator /=(long long num) {
        *this = *this / num;
    }

    BigInteger operator %(const BigInteger &b) {
        if (b == ZERO()) {
            throw 1;
        }
        if (abs(*this) < abs(b)) {
            return *this;
        }
        BigInteger a;
        int last = (int) value.size() - (int) b.value.size();
        for (int i = last; i < (int) value.size(); i++) {
            a.value.push_back(value[i]);
        }
        if (a < b) {
            last--;
            a.value.insert(a.value.begin(), value[last]);
        }
        while (true) {
            int left = 0;
            int right = MOD + 1;
            while (left + 1 < right) {
                int mid = (left + right) >> 1;
                if (a < b * mid) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            a -= b * left;
            last--;
            if (last < 0) {
                break;
            }
            if (a.value.back() == 0) {
                a.value.pop_back();
            }
            a.value.insert(a.value.begin(), value[last]);
        }
        return a;
    }

    BigInteger operator %(long long num) {
        return *this % valueOf(num);
    }

    void operator %=(const BigInteger &a) {
        *this = *this % a;
    }

    void operator %=(long long num) {
        *this = *this % num;
    }

    static BigInteger pow(const BigInteger &value, long long ext) {
        if (ext == 0) {
            return ONE();
        }
        BigInteger half = pow(value, ext >> 1);
        if ((ext & 1) == 0) {
            return half * half;
        }
        return half * half * value;
    }

    std::string toString() const {
        std::string res;
        if (sign == -1) {
            res += '-';
        }
        for (int i = (int) value.size() - 1; i >= 0; i--) {
            std::string cur = std::to_string(value[i]);
            if (i != (int) value.size() - 1) {
                for (int j = 0; j < CELL_SIZE - (int) cur.length(); j++) {
                    res += '0';
                }
            }
            res += cur;
        }
        return res;
    }

    int toInt() const {
        int res = 0;
        for (int cur : value) {
            res *= MOD;
            res += cur;
        }
        return sign * res;
    }

    long long toLong() const {
        long long res = 0;
        for (long long cur : value) {
            res *= MOD;
            res += cur;
        }
        return sign * res;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    printf("%s", BigInteger::pow(BigInteger::valueOf(45), n).toString().c_str());
    return 0;
}
