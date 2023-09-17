#include <bits/stdc++.h>

class BigInteger {

private:

    static const int MOD = 1'000'000'000;

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
        number.push_back(n);
        if (n >= MOD) {
            number.back() %= MOD;
            number.push_back(n / MOD);
        }
    }

    BigInteger(const std::string str) {
        number.push_back(0);
        int mult = 1;
        for (int i = (int) str.length() - 1; i >= 0; i--) {
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
    }

    const BigInteger operator +(BigInteger a) const {
        BigInteger res = *this;
        if (a.number.size() > res.number.size()) {
            std::swap(a, res);
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
    char buf[1 + 100];
    scanf(" %s", &buf);
    BigInteger a(buf);
    scanf(" %s", &buf);
    BigInteger b(buf);
    BigInteger(a * b).print();
    return 0;
}