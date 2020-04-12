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

// count all (a, b, c) st 1<=a<=b<=c<=N st there exist 'd'
// (a+b), c, d form a pythagorean triplet

namespace Solver {

	vector<IntPair> v(6000);

	// generate all primitive triplets (a, b, c) st a<=b<=z
	void generatePrimitivePythagoreanTriplets(int z) {
		fr(m, 1, z/2+1)fr(n, 1, m) {
			int a=m*m-n*n, b=2*m*n, c=m*m+n*n;
			if(b>z)break; if(a>b)swap(a, b);
			if(gcd(a, b)==1 and b<=z)v.emplace_back(a, b);
		}
	}

	int solve2(int N) {
		Long ans=0;
		for (auto [x, y] : v) {
			fr(i, 1, N) {
				if(i*y>N)break;
				fr(a, 1, i*x) {
					if(2*a>i*x)break;
					int b=i*x-a;
					if(b>i*y)continue;
					++ans;
				}
			}
			fr(i, 1, N) {
				if(i*x>N)break;
				fr(a, 1, i*y) {
					if(2*a>i*y)break;
					int b=i*y-a;
					if(b>i*x)continue;
					++ans;
				}
			}
		}
		return ans;
	}

	bool solve(int _) {
		generatePrimitivePythagoreanTriplets(6000);
		int low=100, high=3000;int ans=high;
		rp(_, 200) {
			if(low>high)return prl(ans);
			int mid=(low+high)/2;
			if(solve2(mid)>1e6) {
				minimize(ans, mid);
				high=mid-1;
			} else {
				low=mid+1;
			}
		}
		return 1;
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






// 1818
// Time taken: 0.89073s

