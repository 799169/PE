#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#ifdef LOCAL
    #include "DebugUtils.h"
#endif

using namespace std;
using namespace chrono;

#define all(x) begin(x), end(x)

typedef long long Long;
typedef long double LongDouble;
typedef vector <int> IntVector;


namespace IntegerUtils {

    int length(Long n) {
        if (n == 0) {
            return 1;
        }
        int r = 0;
        while (n > 0) {
            ++r;
            n /= 10;
        }
        return r;
    }

}

using IntegerUtils::length;

struct BigInteger {

    static const int N = 500;
    long long a[N];

    const long long B = 10000LL;
    const int D = 4;

    void clear() {
        for (int i = 0; i < N; ++i) {
            a[i] = 0LL;
        }
    }

    BigInteger()  {
        clear();
    }

    BigInteger(auto x) {
        clear();
        int i = N - 1;
        while (x > 0) {
            a[i] = x % B;
            x /= B;
            --i;
        }
    }

    void print() {
        int i = 0;
        while (i < N && a[i] == 0) {
            ++i;
        }
        while (i < N) {
            cout << setfill('0') << setw(D) << a[i];
            ++i;
        }
        cout << endl;
    }

    void add(BigInteger &b) {
        auto c = 0LL;
        for (int i = N - 1; i >= 0; --i) {
            a[i] += b.a[i] + c;
            c = 0;
            if (a[i] >= B) {
                a[i] -= B;
                c = 1;
            }
        }
    }

    void multiply(int x) {
        auto c = 0LL;
        for (int i = N - 1; i >= 0; --i) {
            auto d = a[i] * x + c;
            a[i] = d % B;
            c = d / B;
        }
    }

    void normalize(BigInteger &b) {
        auto c = 0LL;
        for (int i = N - 1; i >= 0; --i) {
            b.a[i] += c;
            c = b.a[i] / B;
            b.a[i] %= B;
        }
    }

    void multiply(BigInteger &b,  BigInteger &r) {
        auto c = 0LL;
        r.clear();
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                r.a[i - N + 1 + j] += a[i] * b.a[j];
            }
        }
        normalize(r);
    }

    int numOfDigits() {
        int i = 0;
        while (i < N && a[i] == 0) {
            ++i;
        }
        return length(a[i]) + D * (N - i - 1);
    }


};



struct Problem57 {

    auto solve() {
        BigInteger a(1), b(2), c, d;
        int i, ans = 0;
        for (i = 1; i <= 1000; ++i) {
            c.clear();
            c.add(a);
            a.clear();
            a.add(b);
            b.add(a);
            b.add(c);
            d.clear();
            d.add(a);
            d.add(b);
            if (d.numOfDigits() > b.numOfDigits()) {
                ans += 1;
            }
        }
        return ans;
    }

} solver;


int main() {
    freopen("output.txt", "w+", stdout);
    auto start = high_resolution_clock::now();
    auto ans = solver.solve();
    auto end = high_resolution_clock::now();
    duration <double> diff = end - start;
    cout << setw(12) << " Answer: " << setw(10) << ans;
    cout << "\n Time taken: " << setw(9) << fixed;
    cout << setprecision(5) << diff.count() << "s\n\n";
    return 0;
}

/************************
    Answer:        153
 Time taken:   0.01400s
************************/
