#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef LOCAL_DEFINE
	#include "DebugUtils.cpp"
#endif

using namespace std;
using namespace __gnu_pbds;

using Long = long long;
using LD = long double;
using IntPair = pair<int, int>;
using IntVector = vector<int>;

#define rp(i, n)    for (int i = 0; i < (int) (n); ++i)
#define fr(i, x, n) for (int i = (x); i < (int) (n); ++i) 
#define rf(i, x, y) for (int i = (x); i >= (int) (y); --i) 
#define sz(a)       ((int) (a).size())
#define mp          make_pair
#define pb          push_back

template <class T>                      void read(T& x)                  { cin >> x; }
template <class T, class... U>          void read(T& t, U&... u)         { read(t); read(u...); }
template <class T>                      void reada(T* a, int n)          { rp(i, n) read(a[i]); }

template <class T = bool>               bool println()                   { return !!(cout << endl); }
template <class T>                      bool print(T t)                  { return !!(cout << t); }
template <class T>                      bool println(T t)                { print(t); return println(); }
template <class T, class... U>          bool print(T t, U... u)          { print(t); print(' '); return print(u...); }
template <class T, class... U>          bool println(T t, U... u)        { print(t); print(' '); return println(u...); }

template <class T>                      T maxa(T* x, int n)              { return *max_element(x, x + n); }
template <class T>                      T mina(T* x, int n)              { return *min_element(x, x + n); }
template <class T>                      T suma(T* x, int n)              { T s = T(); rp(i, n) s += x[i]; return s; }

template <class T, class U>             auto maxx(T t, U u)         -> typename common_type<T, U>::type       { return (t > u) ? t : u; }
template <class T, class U, class... V> auto maxx(T t, U u, V... v) -> typename common_type<T, U, V...>::type { return maxx(maxx(t, u), v...); }
template <class T, class U>             auto minn(T t, U u)         -> typename common_type<T, U>::type       { return (t < u) ? t : u; }
template <class T, class U, class... V> auto minn(T t, U u, V... v) -> typename common_type<T, U, V...>::type { return minn(minn(t, u), v...); }

template <class T, class U>             bool minimize(T& t, U u)         { if (u < t) { t = u; return 1; } return 0; }
template <class T, class U>             bool maximize(T& t, U u)         { if (u > t) { t = u; return 1; } return 0; }
template <class T, class U, class... V> bool minimize(T& t, U u, V... v) { if (auto m = minn(u, v...); m < t)  { t = m; return 1; } return 0; }
template <class T, class U, class... V> bool maximize(T& t, U u, V... v) { if (auto m = maxx(u, v...); m > t)  { t = m; return 1; } return 0; }

template <class T> T powi(T x, int y) { T ans = 1; while (y > 0) { if (y & 1) ans *= x; y >>= 1; if (y > 0) x *= x; } return ans; }
template <class T> T sqr(T x)         { return x * x; }

mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count() + 7);
uniform_int_distribution<Long> uid(0L); 
Long randInt(Long x, Long y) { return (uid(mrand) % (y - x + 1)) + x; } // [x, y] inclusive

#define rd read
#define rda reada

#ifdef LOCAL_DEFINE
	Long ITR = 1e7;
#else
	#define tr(x...)   0;
	#define nil        0;
	#define pr(x...)   0;
	#define prl(x...)  0;
	#define pra(x...)  0;
	#define pr2d(x...) 0; 
	#define ts(x...)  "";
#endif

int testCases = 1;
int localTestCases = 1;

const LD EPS = 1e-15;
const Long INF = 1e15;
bool multipleTestCases = 0;


const int MAXN = 1e5;
const int SQRTMAXN = sqrt(MAXN);
const int MAXS = MAXN / 3;	// number of candidates to be checked; all are of the form 6k + 1 or 6k - 1
const int MAXP = MAXN / 10;	// max number of primes expected <= MAXN
bitset<MAXS> sieve;
int primes[MAXP] = {2, 3}, numOfPrimes = 2;

inline int getNumber(int i) { return 3 * i + 5 - (i & 1); }
inline int getIndex(int n) { return (n % 6 == 1) ? (n - 4) / 3 : (n - 5) / 3; }

void generatePrimes() {
	sieve.set();
	for (int i = 0; i < MAXS; ++i) {
		if (sieve[i]) {
			int j = getNumber(i);
			if (j > SQRTMAXN) break;
			for (int k = j * j; k <= MAXN; k += 6 * j)
				sieve[(k - 4) / 3] = false;
			for (int k = j * j + 2 * j * ((i & 1) + 1); k <= MAXN; k += 6 * j)
				sieve[(k - 5) / 3] = false;
		}
	}
	for (int i = 0; i < MAXS; ++i) {
		if (sieve[i]) {
			primes[numOfPrimes] = getNumber(i);
			++numOfPrimes;
		}
	}
	while (primes[numOfPrimes - 1] > MAXN) {
		--numOfPrimes;
	}
}

namespace Solver {

	const int N=100, K=100;
	short a[N][K];

	// index largest prime <= n
	int f(int n) {
		return upper_bound(primes, primes+numOfPrimes, n)-primes-1;
	}

	bool solve(int testNumber) {
		generatePrimes();
		rp(i, N)fill_n(a[i], K, 0);
		rp(i, K)a[0][i]=1;
		fr(i, 2, N) {
			a[i][0]= 1-(i&1);
			fr(j, 1, K) {
				a[i][j]=a[i][j-1];
				int p=primes[j];
				if(p>i)break;
				fr(k, 1, 100) {
					if(i-k*p<0)break;
					if(i==9)tr(i, k, p, j, f(i-k*p));
					a[i][j]+=a[i-k*p][max(min(j-1, f(i-k*p)), 0)];
				}
				if(a[i][j]>5000){prl(i, j);goto gg;}//return prl(i);
			}
		}
gg:
		pra(primes, 10);
		fr(i, 2, 20) {pr(i, "");pra(a[i], 9)}
		return prl();
	}


	void solve() {
		#ifdef LOCAL_DEFINE
			freopen("input.txt", "r", stdin); freopen("output.txt", "w+", stdout); freopen("output.txt", "a", stderr); read(localTestCases);
		#else
			ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
		#endif
		rp(_, localTestCases) { if (multipleTestCases) read(testCases); rp(i, testCases) solve(i + 1); println(); }
	}

};


int main() {
	auto t1 = chrono::high_resolution_clock::now(); Solver::solve(); auto t2 = chrono::high_resolution_clock::now(); chrono::duration<double> t = t2 - t1;
	cout << endl; cerr << "\nTime taken: " << fixed << setprecision(5) << t.count() << "s\n" << endl;
	return 0;
}






//24702
//Time taken: 0.07814s


