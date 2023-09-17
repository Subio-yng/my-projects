#include <bits/stdc++.h>

class BigInteger {

private:

    static const int MOD = 1'000'000'000;

    int coefficient;

    std::vector<int> number;

    const void addResidue(int last, int residue) {
        while (0 < residue && last < (int) number.size()) {
            number[last] += residue;
            residue = 0;
            if (number[last] >= MOD) {
                number[last] -= MOD;
                residue = 1;
            }
            last++;
        }
        if (0 < residue) {
            number.push_back(residue);
        }
    }

public:

    BigInteger()
    {}

    BigInteger(int n) {
        if (n < 0) {
            coefficient = -1;
            n *= -1;
        } else {
            coefficient = 1;
        }
        number.push_back(n);
        int residue = 0;
        while (number.back() >= MOD) {
            number.back() -= MOD;
            residue++;
        }
        if (residue > 0) {
            number.push_back(residue);
        }
    }

    BigInteger(const std::string str) {
        coefficient = 1;
        number.push_back(0);
        int mult = 1;
        for (int i = (int) str.length() - 1; i >= 0; i--) {
            if (str[i] == '-') {
                coefficient = -1;
                break;
            }
            if (mult == MOD) {
                mult = 1;
                number.push_back(0);
            }
            number.back() += (str[i] - '0') * mult;
            mult *= 10;
        }
    }

    const void operator =(const BigInteger &a) {
        number = a.number;
        coefficient = a.coefficient;
    }

    const bool operator ==(const BigInteger &a) const {
        return coefficient == a.coefficient && number == a.number;
    }

    const bool operator <(const BigInteger  &a) const {
        if ((int) number.size() != (int) a.number.size() || coefficient != a.coefficient) {
            return coefficient * number.size() < a.coefficient * a.number.size();
        }
        int last = (int) number.size() - 1;
        while (last >= 0) {
            if (number[last] != a.number[last]) {
                return coefficient * number[last] < a.coefficient * a.number[last];
            }
            last--;
        }
        return false;
    }

    const bool operator <=(const BigInteger &a) const {
        return *this < a || *this == a;
    }

    const bool operator >(const BigInteger &a) const {
        return a < *this;
    }

    const bool operator >=(const BigInteger &a) const {
        return a <= *this;
    }

    static const BigInteger abs(BigInteger a) {
        a.coefficient = 1;
        return a;
    }

    const BigInteger operator +(BigInteger a) const {
        if (coefficient != a.coefficient) {
            return *this - a;
        }
        BigInteger res = *this;
        if (res.number.size() < a.number.size()) {
            std::swap(res, a);
        }
        int residue = 0;
        int last = 0;
        while (last < (int) a.number.size()) {
            res.number[last] += a.number[last] + residue;
            residue = 0;
            if (res.number[last] >= MOD) {
                res.number[last] -= MOD;
                residue = 1;
            }
            last++;
        }
        res.addResidue(last, residue);
        return res;
    }

    const void operator +=(BigInteger a) {
        *this = *this + a;
    }

    const BigInteger operator -(BigInteger a) const {
        if (coefficient != a.coefficient) {
            a.coefficient *= -1;
            return *this + a;
        }
        BigInteger res = *this;
        if (BigInteger::abs(res) < BigInteger::abs(a)) {
            std::swap(res, a);
            res.coefficient *= -1;
        }
        int last = 0;
        while (last < (int) a.number.size()) {
            res.number[last] -= a.number[last];
            if (res.number[last] < 0) {
                res.number[last] += MOD;
                res.number[last + 1]--;
            }
            last++;
        }
        while (1 < (int) res.number.size() && res.number.back() == 0) {
            res.number.pop_back();
        }
        return res;
    }

    const void operator -=(BigInteger a) {
        *this = *this - a;
    }

    const BigInteger operator *(BigInteger a) const {
        BigInteger b = *this;
        if (a.number.size() > b.number.size()) {
            std::swap(a, b);
        }
        BigInteger res(0);
        for (int i = 0; i < (int) a.number.size(); i++) {
            BigInteger cur;
            for (int j = i; j > 0; j--) {
                cur.number.push_back(0);
            }
            int last = 0;
            int residue = 0;
            while (last < (int) b.number.size()) {
                long long mult = 1LL * b.number[last] * a.number[i] + residue;
                cur.number.push_back(mult % MOD);
                residue = mult / MOD;
                last++;
            }
            cur.addResidue((int) cur.number.size(), residue);
            res += cur;
        }
        while (1 < (int) res.number.size() && res.number.back() == 0) {
            res.number.pop_back();
        }
        res.coefficient = a.coefficient * b.coefficient;
        return res;
    }

    const void operator *=(BigInteger a) {
        *this = *this * a;
    }

    const BigInteger getPow(int pow) const {
        if (pow == 0) {
            return BigInteger(1);
        }
        BigInteger half = getPow(pow / 2);
        if (pow % 2 == 0) {
            return half * half;
        }
        return half * half * *this;
    }

    void print() {
        if (coefficient == -1) {
            printf("-");
        }
        int cur = (int) number.size() - 1;
        printf("%d", number[cur]);
        cur--;
        while (cur >= 0) {
            printf("%09d", number[cur]);
            cur--;
        }
    }
};

int main() {
    char buf[1 + 1000];
    scanf(" %s", &buf);
    BigInteger a(buf);
    scanf(" %s", &buf);
    BigInteger b(buf);
    BigInteger(a - b).print();
    return 0;
}