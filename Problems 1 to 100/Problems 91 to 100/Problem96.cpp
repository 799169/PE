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

ifstream ff("p096_sudoku.txt");

template <class T> struct PriorityQueue {
	
	pair<T, int> a[100];int an=-1;

	int parentIndex(int i) { return (i-1)/2;}
	int leftChildIndex(int i) { return 2*i+1;}
	int rightChildIndex(int i) { return 2*i+2;}
	int size() { return an+1;}

	void floatUp(int i) {		
		int j=parentIndex(i);
		while (i>0 and a[i].second<a[j].second) {nil;swap(a[i], a[j]);i=j;j=parentIndex(i);}
	}

	void sinkDown(int i) {
		int j=leftChildIndex(i);int k=rightChildIndex(i);
		if(k<=an and a[k].second<a[j].second)swap(j, k);
		while(j<=an and a[i].second>a[j].second) {nil
			swap(a[i], a[j]);i=j;j=leftChildIndex(i);k=rightChildIndex(i);
			if(k<=an and a[k].second<a[j].second)swap(j, k);
		}
	}

	void push(T t, int x) {++an;a[an].first=t;a[an].second=x;floatUp(an);}
	auto top() { return a[0]; }
	auto pop() {auto r=a[0];a[0].first=a[an].first;a[0].second=a[an].second;--an;sinkDown(0);return r;}
	void updatePriority(const T t, int g) {rp(i, an+1) if(t==a[i].first) {a[i].second=g;floatUp(i);sinkDown(i);return;}}
	string toString() {string r="";rp(i, an)r+=ts(a[i].first)+":"+ts(a[i].second)+" ";return r+"\n";}
	void display() {prl(toString());}
	void clear() {an=-1;}
};


struct Sudoku {
	unordered_set<int> boxes[9], rows[9], columns[9]; // digits from 0 to 9 that are already in row[5]
	unordered_set<int> options[9][9];
	PriorityQueue<IntPair> pq; int a[9][9];
	IntPair moves[100]; int mn=0;

	int boxNumber(int i, int j) {
		if(i<3 and j<3)return 0;
		if(i<3 and j<6)return 1;
		if(i<3 and j<9)return 2;
		if(i<6 and j<3)return 3;
		if(i<6 and j<6)return 4;
		if(i<6 and j<9)return 5;
		if(i<9 and j<3)return 6;
		if(i<9 and j<6)return 7;
		if(i<9 and j<9)return 8;
		return 0;
	}
	// ok()==1 implies the sudoku is solvable
	bool ok() {
		rp(i, 9)rp(j, 9)if(a[i][j]==0 and sz(options[i][j])==0)return 0;
		return 1;
	}
	bool done() {
		rp(i, 9)rp(j, 9)if(a[i][j]<1 or a[i][j]>9)return 0; 
		rp(i, 9)if(sz(boxes[i])!=9)return 0;
		rp(i, 9)if(sz(rows[i])!=9)return 0;
		rp(i, 9)if(sz(columns[i])!=9)return 0;
		return 1;
	}
	void updateAll() {
		rp(i, 9){boxes[i].clear();rows[i].clear();columns[i].clear();rp(j, 9)options[i][j].clear();}
		rp(i, 9)rp(j, 9) if(a[i][j]>0) {
			boxes[boxNumber(i, j)].insert(a[i][j]);
			rows[i].insert(a[i][j]);
			columns[j].insert(a[i][j]);
		}
		rp(i, 9)rp(j, 9)if(a[i][j]==0)fr(d, 1, 10) {
			if(boxes[boxNumber(i, j)].count(d))continue;
			if(rows[i].count(d))continue;
			if(columns[j].count(d))continue;
			options[i][j].insert(d);
		}
		pq.clear();
		rp(i, 9)rp(j, 9)if(a[i][j]==0)pq.push(mp(i, j), sz(options[i][j]));
	}
	void input() {
		string ss;ff>>ss;ff>>ss;pq.clear();mn=0;
		rp(i, 9) { string s;ff>>s;rp(j, 9)a[i][j]=s[j]-'0'; }
		updateAll();
	}
	void display() {
		rp(i, 9) {
			rp(j, 9)pr((int)a[i][j], "");
			prl();
		}
	}

	void put(int x, int y, int d) {
		moves[mn++]=mp(x, y);a[x][y]=d;rows[x].insert(d);columns[y].insert(d);
		boxes[boxNumber(x, y)].insert(d);
		rp(j, 9)if(j!=y and a[x][j]==0)if(options[x][j].erase(d))pq.updatePriority(mp(x, j), sz(options[x][j]));
		rp(i, 9)if(i!=x and a[i][y]==0)if(options[i][y].erase(d))pq.updatePriority(mp(i, y), sz(options[i][y]));
		rp(i, 9)rp(j, 9)if(boxNumber(i, j)==boxNumber(x, y) and a[i][j]==0 and mp(i, j)!=mp(x, y))
			if(options[i][j].erase(a[x][y]))pq.updatePriority(mp(i, j), sz(options[i][j]));
	}

	bool tryOnce() {
		auto [p, z] = pq.pop();auto [x, y]=p;
		if(z!=1)return 0;
		put(x, y, *begin(options[x][y]));return 1;
	}

	bool recurse(int depth=1) {nil
		if(depth<=0)return done();updateAll();
		rp(i, 100)if(!tryOnce())break;
		rp(i, 9)rp(j, 9)if(a[i][j]==0 and sz(options[i][j])==0)return 0;
		if(done())return 1;
		auto [p, z] = pq.pop();auto [x, y]=p;
		auto lst=options[x][y];
		for(int d:lst) {
			put(x, y, d);
			if(recurse(depth-1))return 1;
			int i=mn-1;
			while(i>=0) {nil
				auto [xx, yy]=moves[i];a[xx][yy]=0;--mn;--i;
				if(mp(xx, yy)==mp(x, y))break;
			}
			updateAll();
		}
		return done();
	}

	bool solve() {
		return recurse(70);
	}

} sud;

namespace Solver {

	bool solve(int testNumber) {
		int ans=0;
		rp(_, 50) {
			sud.input();
			if(_>=0) {
				// sud.display();prl("\n");
			sud.solve();
				if(!sud.done()){
					sud.display();
					tr(_)
				}
				// tr(sud.done())
				ans+=sud.a[0][0]*100+sud.a[0][1]*10+sud.a[0][2];
				// sud.display();prl("\n");
			}
		}
		prl(ans);
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






//24702
//Time taken: 0.07814s


