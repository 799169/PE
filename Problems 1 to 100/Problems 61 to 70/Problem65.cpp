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
typedef pair <int, int> IntPair;
typedef vector <int> IntVector;
typedef vector <Long> LongVector;
typedef set <int> IntSet;
typedef set <Long> LongSet;
typedef vector <IntPair> IntPairVector;


namespace IntegerUtils {

    int s;

    int sumOfDigits(Long n) {
        s = 0;
        while (n > 0) {
            s += (n % 10);
            n /= 10;
        }
        return s;
    }

}

using IntegerUtils::sumOfDigits;

struct BigInteger {

    static const int N = 100;
    Long a[N];

    const Long B = 10000;
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

    void set(Long x) {
        clear();
        int i = N - 1;
        while (x > 0) {
            a[i] = x % B;
            x /= B;
            --i;
        }
    }


    void set(const BigInteger &b) {
        clear();
        for (int i = 0; i < N; ++i) {
            a[i] = b.a[i];
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


};


struct Problem65 {

    Long N = 100, i, ans;
    BigInteger a, b, c, d;

    auto solve() {
        a.set(1);
        b.set(f(N));
        for (i = N - 1; i > 1; --i) {
            c.set(b);
            b.multiply(f(i));
            b.add(a);
            a.set(c);
        }
        b.add(b);
        b.add(a);
        ans = 0;
        for (i = 0; i < BigInteger::N; ++i) {
            ans += sumOfDigits(b.a[i]);
        }
        return ans;
    }

    inline Long f(int z) {
        if (z % 3 == 0) {
            return 2 * z / 3;
        }
        return 1;
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
    Answer:        272
 Time taken:   0.00000s
************************/
