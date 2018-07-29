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

using namespace std;
using namespace chrono;

#define all(x) begin(x), end(x)

typedef long long Long;
typedef long double LongDouble;
typedef vector <int> IntVector;

struct BigInteger {

    static const int N = 220;
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

    int sumOfDigits() {
        int i, s = 0, t;
        for (i = 0; i < N; ++i) {
            t = a[i];
            while (t > 0) {
                s += t % 10;
                t /= 10;
            }
        }
        return s;
    }

};


struct Problem56 {

    BigInteger b;
    int x, y, z, c, i, j, mx = 1;

    auto solve() {
        for (x = 2; x < 100; ++x) {
            b.clear();
            b.a[BigInteger::N - 1] = 1;
            for (y = 1; y < 100; ++y) {
                b.multiply(x);
                mx = max(b.sumOfDigits(), mx);
            }
        }
        return mx;
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
    Answer:        972
 Time taken:   0.06400s
************************/
