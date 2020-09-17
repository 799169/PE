#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std; using namespace chrono; using namespace __gnu_pbds;

/* Pragmas #pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // 

// #pragma GCC target ("mmx,sse,sse2,sse3,sse4.1,sse4.2,avx,avx2,fma,avx512vl")
#pragma GCC target ("mmx,sse,sse2,sse3,sse4.1,sse4.2,tune=native")
//,popcnt

#include <nmmintrin.h>
 */

/* @BEGIN TEMPLATE_CODE */
namespace DEFINES  {

#define __g5(a, b, c, d, e, ...) e
#define __fr2(i, n)              for (int i = 0, i ## $ = n; i <  i ## $; ++i)
#define __fr3(i, a, b)           for (int i = a, i ## $ = b; i <= i ## $; ++i)
#define __fr4(i, a, b, s)        for (int i = a, i ## $ = b, i ## $_ = s; i <= i ## $; i += i ## $_)
#define __frr3(i, b, a)          for (int i = b, i ## $ = a; i >= i ## $; --i)
#define __frr4(i, b, a, s)       for (int i = b, i ## $ = a, i ## $_ = s; i >= i ## $; i -= i ## $_)
#define fr(x...)                 __g5(x, __fr4, __fr3, __fr2) (x)
#define frr(x...)                __g5(x, __frr4, __frr3) (x)
#define rp(n)                    fr(i$$, n)
#define rpp(n)                   fr(j$$, n)
#define trav(i, a)               for (const auto& i : a)
#define iter(i, a)               for (auto& i : a)
#define trv(y, x...)             for (const auto& [x] : y)
#define itr(y, x...)             for (auto& [x] : y)

#define all(a)       (a).begin(), (a).end()
#define rall(a)      (a).rbegin(), (a).rend()
#define rprl(x...)   return prl(x)
#define in(t, x...)  t x; rd(x);
#define ar           array
#define as           assert
#define bg           begin
#define bk           back
#define b_s          binary_search
#define cR(x...)     assert(iR(x))
#define C_T          common_type
#define cc_m         cc_hash_table
#define co           continue
#define eb           emplace_back
#define ef           emplace_front
#define em           emplace
#define elif         else if
#define f_l          forward_list
#define fi           first
#define ft           front
#define g0           get<0>
#define g1           get<1>
#define g2           get<2>
#define g3           get<3>
#define g4           get<4>
#define g5           get<5>
#define gp_m         gp_hash_table
#define istr         istringstream
#define l_b          lower_bound
#define m_m          multimap
#define m_s          multiset
#define mp           make_pair
#define mt           make_tuple
#define n_l          numeric_limits
#define op           operator
#define o_s          ordered_set
#define ostr         ostringstream
#define p_q          priority_queue
#define pb           push_back
#define pf           push_front
#define ppb          pop_back
#define ppf          pop_front
#define rbg          rbegin
#define re           return
#define rsz          resize
#define se           second
#define sstr         stringstream
#define stf          shrink_to_fit
#define t_s          to_string
#define u_b          upper_bound
#define u_m          unordered_map
#define u_mm         unordered_multimap
#define u_ms         unordered_multiset
#define u_s          unordered_set
#define v_t          value_type
#define vt           vector

#define C            const
#define CE           constexpr
#define SCE          static constexpr
#define SCC          static_cast<char>
#define SCI          static_cast<int>
#define SCL          static_cast<ll>
#define SCU          static_cast<uint>
#define CA           const auto
#define IN           inline
#define IV           inline void
#define IB           inline bool
#define IC           inline char
#define II           inline int
#define IL           inline ll
#define IS           inline string
#define IT           inline T
#define IA           inline auto
#define ICA          inline const auto
#define R_C          reinterpret_cast
#define S_A          static_assert
#define S_C          static_cast
#define TMP          template
#define TP           typename
#define TN           TMP <int N>
#define TS           TMP <szt S>
#define TT           TMP <TP T>
#define TU           TMP <TP U>
#define TTT          TMP <TP... T>
#define TNM          TMP <int N, int M>
#define TTN          TMP <TP T, int N>
#define TTS          TMP <TP T, szt S>
#define TTU          TMP <TP T, TP U>
#define TTMN         TMP <TP T, szt M, szt N>
#define TTUV         TMP <TP T, TP U, TP V>
#define TTUVW        TMP <TP T, TP U, TP V, TP W>
#define TTUU         TMP <TP T, TP... U>
#define TTUVV        TMP <TP T, TP U, TP... V>
#define ILAF         if (LOCAL) assert(false)
#define AF           assert(false)

} using namespace DEFINES;
namespace TYPEDEFS {

TT using pairT = pair<T, T>;
TMP <TP T, TP U = less<T>> using o_s = tree<T, null_type, U, rb_tree_tag, tree_order_statistics_node_update>;
TT using  min_pq = p_q<T, vt<T>, greater<T>>;
TT using  max_pq = p_q<T, vt<T>, less<T>>;
TT using min_set = set<T, less<T>>;
TT using max_set = set<T, greater<T>>;
TT using  min_ms = multiset<T, less<T>>;
TT using  max_ms = multiset<T, greater<T>>;

TMP <TP T, TP U, TP V = less<T>> using min_map = map<T, U, less<T>>;
TMP <TP T, TP U, TP V = less<T>> using max_map = map<T, U, greater<T>>;
TMP <TP T, TP U, TP V = less<T>> using  min_mm = multimap<T, U, less<T>>;
TMP <TP T, TP U, TP V = less<T>> using  max_mm = multimap<T, U, greater<T>>;

using  si1 = int8_t;
using  si2 = int16_t;
using  si4 = int32_t;
using  si8 = int64_t;
using  ui1 = uint8_t;
using  ui2 = uint16_t;
using  ui4 = uint32_t;
using  ui8 = uint64_t;
using  szt = size_t;
using uint = ui4;
using  ll  = si8;
using  ull = ui8;
using  flt = float;
using  dbl = double;
using   ld = long double;
using  str = string;

using  pi  = pairT<si4>;
using  pii = pairT<si4>;
using  pl  = pairT<ll>;
using  pll = pairT<ll>;
using  pss = pairT<str>;
using  pdd = pairT<dbl>;

using  pil = pair<si4, ll>;
using  pli = pair<ll, si4>;

using  t3i = tuple<si4, si4, si4>;
using  t3l = tuple<si8, si8, si8>;

using  t4i = tuple<si4, si4, si4, si4>;
using  t4l = tuple<si8, si8, si8, si8>;

using  t5i = tuple<si4, si4, si4, si4, si4>;
using  t5l = tuple<si8, si8, si8, si8, si8>;

using   vb = vt<bool>;
using   vc = vt<char>;
using   vi = vt<si4>;
using   vl = vt<ll>;
using   vd = vt<dbl>;
using  vld = vt<ld>;
using   vs = vt<str>;

using vpii = vt<pii>;
using vpll = vt<pll>;
using vpdd = vt<pdd>;
using vpss = vt<pss>;

using  vvb = vt<vb>;
using  vvc = vt<vc>;
using  vvi = vt<vi>;
using  vvl = vt<vl>;
using  vvd = vt<vd>;
using vvld = vt<vld>;
using  vvs = vt<vs>;

#define int si4

} using namespace TYPEDEFS;
/* @END TEMPLATE_CODE */

namespace REDEFINE_ASSERT {
#undef assert
#define assert(e) { if (!(e)) { printf("\nASSERTION FAILED [LINE: %d] [FUNCTION: %s] [FILE: %s]\n", __LINE__, __FUNCTION__, __FILE__); exit(1); } }
} using namespace REDEFINE_ASSERT;

/* Primitive Types*/                     namespace TO_STRING {

	IS tss(C si1 x)      { re std::t_s(SCI(x)); }
	IS tss(C si2 x)      { re std::t_s(SCI(x)); }
	IS tss(C si4 x)      { re std::t_s(x); }
	IS tss(C si8 x)      { re std::t_s(x); }
	IS tss(C ui1 x)      { re std::t_s(SCI(x)); }
	IS tss(C ui2 x)      { re std::t_s(SCI(x)); }
	IS tss(C ui4 x)      { re std::t_s(x); }
	IS tss(C ui8 x)      { re std::t_s(x); }

	IS tss(C unsigned long x)    { re std::t_s(S_C<ui4>(x)); }

	IS tss(C bool x)     { re (x ? "1" : "0"); }
	IS tss(C char x)     { re str(1, x); }

	IS tss(C flt x)      { re std::t_s(x); }
	IS tss(C dbl x)      { ostr o; o.precision(15); o << fixed << x; re o.str(); }
	IS tss(C ld x)       { ostr o; o.precision(18); o << fixed << x; re o.str(); }

	IS tss(C str &x)     { re x; }
	IS tss(C char* C x)  { re str(x); }
	IS tss(char* C x)    { re str(x); }

}
/* Pair, tuple, bitset, native arrays */ namespace TO_STRING {
	TTU   IS tss(C pair <T, U>& x);
	TTUV  IS tss(C tuple<T, U, V>& x);
	TTUVW IS tss(C tuple<T, U, V, W> & x);

	TS  IS tss(C bitset<S>& x, C int i, C int j) { assert(i >= 0 and j < S); str r; fr(k, i, j) r += (x[i] ? '1' : '0'); re r; }
	TS  IS tss(C bitset<S>& x, C int n = S)        { re tss(x, 0, n - 1);  }

	TTS  IS tss(C T (&a)[S], C int i, C int j);
	TTS  IS tss(C T (&a)[S], C int n = S)     { re tss(a, 0, n - 1); }
}
/* STL Container declarations */         namespace TO_STRING {
	#define  AL allocator
	TMP <TP T, szt S> IS tss(C array<T, S>& x, C int i, C int j);
	TMP <TP T, szt S> IS tss(C array<T, S>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, szt S> IS tss(C array<T, S>& x)          { re tss(x, 0, S - 1); }

	TMP <TP T, TP U = AL<T>> IS tss(C vector<T, U>& x, C int i, C int j);
	TMP <TP T, TP U = AL<T>> IS tss(C vector<T, U>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = AL<T>> IS tss(C vector<T, U>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	TMP <TP T, TP U = AL<T>> IS tss(C deque<T, U>& x, C int i, C int j);
	TMP <TP T, TP U = AL<T>> IS tss(C deque<T, U>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = AL<T>> IS tss(C deque<T, U>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	TMP <TP T, TP U = AL<T>> IS tss(C f_l<T, U>& x, C int i, C int j);
	TMP <TP T, TP U = AL<T>> IS tss(C f_l<T, U>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = AL<T>> IS tss(C f_l<T, U>& x);

	TMP <TP T, TP U = AL<T>> IS tss(C list<T, U>& x, C int i, C int j);
	TMP <TP T, TP U = AL<T>> IS tss(C list<T, U>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = AL<T>> IS tss(C list<T, U>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	TMP <TP T, TP U = less<T>, TP V = AL<T>> IS tss(C set<T, U, V>& x, C int i, C int j);
	TMP <TP T, TP U = less<T>, TP V = AL<T>> IS tss(C set<T, U, V>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = less<T>, TP V = AL<T>> IS tss(C set<T, U, V>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	TMP <TP T, TP U = less<T>, TP V = AL<T>> IS tss(C m_s<T, U, V>& x, C int i, C int j);
	TMP <TP T, TP U = less<T>, TP V = AL<T>> IS tss(C m_s<T, U, V>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = less<T>, TP V = AL<T>> IS tss(C m_s<T, U, V>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	// map and multimap
	TMP <TP T, TP U, TP V = less<T>, TP W = AL<pair<C T, U>>> IS tss(C map<T, U, V, W>& x, C int i, C int j);
	TMP <TP T, TP U, TP V = less<T>, TP W = AL<pair<C T, U>>> IS tss(C map<T, U, V, W>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U, TP V = less<T>, TP W = AL<pair<C T, U>>> IS tss(C map<T, U, V, W>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	TMP <TP T, TP U, TP V = less<T>, TP W = AL<pair<C T, U>>> IS tss(C m_m<T, U, V, W>& x, C int i, C int j);
	TMP <TP T, TP U, TP V = less<T>, TP W = AL<pair<C T, U>>> IS tss(C m_m<T, U, V, W>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U, TP V = less<T>, TP W = AL<pair<C T, U>>> IS tss(C m_m<T, U, V, W>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	// unordered_set and unordered_multiset
	TMP <TP T, TP U = hash<T>, TP V = equal_to<T>, TP W = AL<T>> IS tss(C u_s<T, U, V, W>& x, C int i, C int j);
	TMP <TP T, TP U = hash<T>, TP V = equal_to<T>, TP W = AL<T>> IS tss(C u_s<T, U, V, W>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = hash<T>, TP V = equal_to<T>, TP W = AL<T>> IS tss(C u_s<T, U, V, W>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	TMP <TP T, TP U = hash<T>, TP V = equal_to<T>, TP W = AL<T>> IS tss(C u_ms<T, U>& x, C int i, C int j);
	TMP <TP T, TP U = hash<T>, TP V = equal_to<T>, TP W = AL<T>> IS tss(C u_ms<T, U>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = hash<T>, TP V = equal_to<T>, TP W = AL<T>> IS tss(C u_ms<T, U>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	// unordered_map and unordered_multimap
	TMP <TP T, TP U, TP V = hash<T>, TP W = equal_to<T>, TP X = AL<pair<C T, U>>> IS tss(C u_m<T, U, V, W>& x, C int i, C int j);
	TMP <TP T, TP U, TP V = hash<T>, TP W = equal_to<T>, TP X = AL<pair<C T, U>>> IS tss(C u_m<T, U, V, W>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U, TP V = hash<T>, TP W = equal_to<T>, TP X = AL<pair<C T, U>>> IS tss(C u_m<T, U, V, W>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	TMP <TP T, TP U, TP V = hash<T>, TP W = equal_to<T>, TP X = AL<pair<C T, U>>> IS tss(C u_mm<T, U, V, W, X>& x, C int i, C int j);
	TMP <TP T, TP U, TP V = hash<T>, TP W = equal_to<T>, TP X = AL<pair<C T, U>>> IS tss(C u_mm<T, U, V, W, X>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U, TP V = hash<T>, TP W = equal_to<T>, TP X = AL<pair<C T, U>>> IS tss(C u_mm<T, U, V, W, X>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	// stack, queue, and priority_queue
	TMP <TP T, TP U = deque<T>> IS tss(C stack<T, U>& x, C int i, C int j);
	TMP <TP T, TP U = deque<T>> IS tss(C stack<T, U>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = deque<T>> IS tss(C stack<T, U>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	TMP <TP T, TP U = deque<T>> IS tss(C queue<T, U>& x, C int i, C int j);
	TMP <TP T, TP U = deque<T>> IS tss(C queue<T, U>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = deque<T>> IS tss(C queue<T, U>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	TMP <TP T, TP U = vector<T>, TP V = less<TP T::v_t>> IS tss(C p_q<T, U, V>& x, C int i, C int j);
	TMP <TP T, TP U = vector<T>, TP V = less<TP T::v_t>> IS tss(C p_q<T, U, V>& x, C int n) { re tss(x, 0, n - 1); }
	TMP <TP T, TP U = vector<T>, TP V = less<TP T::v_t>> IS tss(C p_q<T, U, V>& x)          { re tss(x, 0, SCI(x.size()) - 1); }


	#define cc_m_template                                       \
 	TMP <	                                                    \
 			TP   T,                                             \
 			TP   U,                                             \
 			TP   V = TP detail::default_hash_fn<T>::type,       \
	   		TP   W = TP detail::default_eq_fn<T>::type,         \
	   		TP   X = detail::default_comb_hash_fn::type,        \
	   		TP   Y = TP detail::default_resize_policy<X>::type, \
	   		bool B = detail::default_store_hash,                \
	   		TP   A = std::allocator<char>                       \
	   	>

	cc_m_template IS tss(C cc_m<T, U, V, W, X, Y, B, A>& x, C int i, C int j);
	cc_m_template IS tss(C cc_m<T, U, V, W, X, Y, B, A>& x, C int n) { re tss(x, 0, n - 1); }
    cc_m_template IS tss(C cc_m<T, U, V, W, X, Y, B, A>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	#define gp_m_template                                       \
 	TMP <	                                                    \
 			TP T,                                               \
 			TP U,                                               \
 			TP V = TP detail::default_hash_fn<T>::type,         \
	   		TP W = TP detail::default_eq_fn<T>::type,           \
	   		TP X = detail::default_comb_hash_fn::type,          \
	   		TP Y = TP detail::default_probe_fn<X>::type,        \
	   		TP Z = TP detail::default_resize_policy<X>::type,   \
	   		bool B = detail::default_store_hash,                \
			TP A = std::allocator<char>                         \
  		>

	gp_m_template IS tss(C gp_m<T, U, V, W, X, Y, Z, B, A>& x, C int i, C int j);
	gp_m_template IS tss(C gp_m<T, U, V, W, X, Y, Z, B, A>& x, C int n) { re tss(x, 0, n - 1); }
    gp_m_template IS tss(C gp_m<T, U, V, W, X, Y, Z, B, A>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	#define tree_template                                                      \
  	TMP <                                                                      \
  			TP T,                                                              \
  			TP U,                                                              \
  			TP F = std::less<T>,                                               \
	        TP V = rb_tree_tag,                                                \
	        TMP<TP W, TP X, TP Y, TP Z> class NU = null_node_update,           \
	        TP A = std::allocator<char>                                        \
	    >

	tree_template IS tss(C tree<T, U, F, V, NU, A>& x, C int i, C int j);
	tree_template IS tss(C tree<T, U, F, V, NU, A>& x, C int n) { re tss(x, 0, n - 1); }
    tree_template IS tss(C tree<T, U, F, V, NU, A>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	#define trie_template                                                             \
  	TMP <                                                                             \
  			TP T,                                                                     \
	   		TP U,                                                                     \
	   		TP V = TP detail::default_trie_access_traits<T>::type,                    \
	   		TP W = pat_trie_tag,                                                      \
	   		TMP <TP X, TP Y, TP Z, TP _Alloc_> class NU = null_node_update,           \
	        TP A = std::allocator<char>                                               \
	    >

	trie_template IS tss(C trie<T, U, V, W, NU, A>& x, C int i, C int j);
	trie_template IS tss(C trie<T, U, V, W, NU, A>& x, C int n) { re tss(x, 0, n - 1); }
    trie_template IS tss(C trie<T, U, V, W, NU, A>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	#define list_update_template                             \
  	TMP <                                                    \
  			TP T,                                            \
	   		TP U,                                            \
	   		class V = TP detail::default_eq_fn<T>::type,     \
	   		class W = detail::default_update_policy::type,   \
	   		class A = std::allocator<char>                   \
	   	>

	list_update_template IS tss(C list_update<T, U, V, W, A>& x, C int i, C int j);
	list_update_template IS tss(C list_update<T, U, V, W, A>& x, C int n) { re tss(x, 0, n - 1); }
    list_update_template IS tss(C list_update<T, U, V, W, A>& x)          { re tss(x, 0, SCI(x.size()) - 1); }

	// @TODO ordered_set, cc_m, gp_m, other pb ds, more 2d containers
	#undef AL // allocator
}
/* STL Container implementations */      namespace TO_STRING {
	#define AL allocator
	TMP <TP T, szt S> IS tss(C array<T, S>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = AL<T>> IS tss(C vector<T, U>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = AL<T>> IS tss(C deque<T, U>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = AL<T>> IS tss(C f_l<T, U>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = AL<T>> IS tss(C f_l<T, U>& x) {
		str r; bool b = true; trav(e, x) { if (b) b = false; else r += ' '; r += tss(e); } re r;
	}
	TMP <TP T, TP U = AL<T>> IS tss(C list<T, U>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = less<T>, TP V = AL<T>> IS tss(C set<T, U, V>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = less<T>, TP V = AL<T>> IS tss(C m_s<T, U, V>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U, TP V = less<T>, TP W = AL<pair<C T, U>>> IS tss(C map<T, U, V, W>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U, TP V = less<T>, TP W = AL<pair<C T, U>>> IS tss(C m_m<T, U, V, W>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = hash<T>, TP V = equal_to<T>, TP W = AL<T>> IS tss(C u_s<T, U, V, W>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = hash<T>, TP V = equal_to<T>, TP W = AL<T>> IS tss(C u_ms<T, U>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U, TP V = hash<T>, TP W = equal_to<T>, TP X = AL<pair<C T, U>>> IS tss(C u_m<T, U, V, W>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U, TP V = hash<T>, TP W = equal_to<T>, TP X = AL<pair<C T, U>>> IS tss(C u_mm<T, U, V, W, X>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = deque<T>> IS tss(C stack<T, U>& x, C int i, C int j) {
		assert(i >= 0); auto s = x; str r; int k = 0; while (!s.empty()) { if (k >= i) { r += tss(s.top()); if (k != j) r += ' '; } s.pop(); if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = deque<T>> IS tss(C queue<T, U>& x, C int i, C int j) {
		assert(i >= 0); auto s = x; str r; int k = 0; while (!s.empty()) { if (k >= i) { r += tss(s.front()); if (k != j) r += ' '; } s.pop(); if (++k > j) break; } re r;
	}
	TMP <TP T, TP U = vector<T>, TP V = less<TP T::v_t>> IS tss(C p_q<T, U, V>& x, C int i, C int j) {
		assert(i >= 0); auto s = x; str r; int k = 0; while (!s.empty()) { if (k >= i) { r += tss(s.top()); if (k != j) r += ' '; } s.pop(); if (++k > j) break; } re r;
	}

	gp_m_template IS tss(C gp_m<T, U, V, W, X, Y, Z, B, A>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}

	cc_m_template IS tss(C cc_m<T, U, V, W, X, Y, B, A>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}

	tree_template IS tss(C tree<T, U, F, V, NU, A>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}

	trie_template IS tss(C trie<T, U, V, W, NU, A>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}

	list_update_template IS tss(C list_update<T, U, V, W, A>& x, C int i, C int j) {
		assert(i >= 0); str r; int k = 0; trav(e, x) { if (k >= i) { r += tss(e); if (k != j) r += ' '; } if (++k > j) break; } re r;
	}

	#undef AL // allocator

}
/* Other implementations */              namespace TO_STRING {
	TTMN IS tss(C T (&x)[M][N], C int r = M, C int c = N) { int m = 1; vvs v(r, vs(c)); fr(i, r) fr(j, c) m = max(m, (int)(v[i][j] = tss(x[i][j])).size()); str y; iter(e, v) { iter(f, e) y += str(m - int(f.size()), ' ') + f + ' '; y += '\n'; } re '\n' + y; }
	TT IS tss(C vt<vt<T>>& x, C int r, C int c);
	TT IS tss(C vt<vt<T>>& x, C int n)      { re tss(x, n, (int) x[0].size()); }
	TT IS tss(C vt <vt<T>> & x)             { re tss(x, int(x.size())); }
	TTUV IS tss(C tuple<T, U, V> & x)       { CA & [a, b, c] = x; re tss(a) + ':' + tss(b) + ':' + tss(c); }
	TTU IS tss(C pair<T, U>& x)             { re tss(x.fi) + ':' + tss(x.se); }
	TTUVW IS tss(C tuple<T, U, V, W> & x)   { CA& [a, b, c, d] = x; re tss(a) + ':' + tss(b) + ':' + tss(c) + ':' + tss(d); }
	TTS IS tss(C T (&a)[S], C int i, C int j)   { assert(i >= 0); str r = tss(a[i]); fr(k, i + 1, j) r += ' ' + tss(a[k]); re r; }
	TT IS tss(C vt<vt<T>>& x, C int r, C int c) { int m = 1; vvs v(r, vs(c)); fr(i, r) fr(j, c) m = max(m, (int)(v[i][j] = tss(x[i][j])).size()); str y; iter(e, v) { iter(f, e) y += string(m - int(f.size()), ' ') + f + ' '; y += '\n'; } re '\n' + y; }
}
using TO_STRING::tss; namespace TRACE {

#define tr(x...)  do { if (DEBUG_MODE) pr(trace1(#x, x)); }  while (false);
#define trs(x...) trace1(#x, x)
#define nil { if (--MXITR <= 0) { printf("\nINFINITE LOOP ON LINE: %d\n",  __LINE__); exit(1); } }

TMP <TP S, TP T> str trace2(S s, T t) { re tss(*s) + '=' + tss(t) + '\n'; } TMP <TP S, TP T, TP... U> str trace2(S s, T t, U... u) { str q = tss(*s) + '=' + tss(t); re q + trace2(++s, u...); }  TMP <TP... T> str trace1(str s, T... y) { vector<str> v; str t = ""; int z = 0; for (char c : s) { if (c == '(') { ++z; t += c; } else if (c == ')') { --z; t += c; } else if (c == ',') { if (z == 0) { v.pb(t); t = ""; } else t += c; } else t += c; } v.pb(t); re trace2(v.begin(), y...); }
} using namespace TRACE;

/* @BEGIN TEMPLATE_CODE */ namespace FUNCTIONS {

TT II sz(C T& a)       { re SCI(a.size()); }
TT IT sqr(C T& x)      { re x * x; }
TT IA sum(C T& x)      { re accumulate(all(x), 0); }
TT IA min(C T& x)      { re *min_element(all(x)); }
TT IA max(C T& x)      { re *max_element(all(x)); }
TT IV sort(T& a)       { sort(all(a)); }
TT IV sorted(T& a)     { auto b = a; sort(b); re b; }
TT IV rsort(T& a)      { sort(rall(a)); }
TT IV rsorted(T& a)    { auto b = a; rsort(b); re b; }
TT IV reverse(T& a)    { reverse(all(a)); }
TT IA reversed(T& a)   { auto b = a; reverse(b); re b; }
TT IT powi(T x, int i) { assert(i >= 0); T r = 1; while (i > 0) { if (i & 1) r *= x; x *= x; i >>= 1; } re r; }
TT IT div_ceil(C T a, C T b)  { assert(a >= 0 and b > 0); if (a == 0) re 0; if (a <= b) re 1; re (a - 1 + b) / b; }
TT IB iR(C T i, C T n)        { re (i >= 0 and i < n); }
TT IB iR(C T i, C T x, C T y) { re (i >= x and i <= y); }
TT  IV unq(vt<T>& a)          { a.resize(unique(all(a))    - a.begin()); a.shrink_to_fit(); }
TTU IV unq(vt<T>& a, C U& f)  { a.resize(unique(all(a), f) - a.begin()); a.shrink_to_fit(); }
TT IS t_s(C vt<T>& x, C int i, C int j) { if (j < i) re ""; str s = std::t_s(x[i]); fr(k, i + 1, j) s += ' ' + std::t_s(x[k]); re s; }
TT IS t_s(C vt<T>& x)                   { re t_s(x, 0, sz(x) - 1); }
TT struct _y_r { T g; TU explicit _y_r(U&& f): g(forward<U>(f)) {} TMP <TP...V> decltype(auto) operator () (V&& ...v) { re g(ref(*this), forward<V>(v)...); } }; TT decltype(auto) $_$(T && f) { re _y_r<decay_t<T>>(forward<T>(f)); }
TTU  IB  smin(T& t, C U& u)        { C auto v = S_C<C T>(u); if (v < t) { t = v; re true; } re false; }
TTU  IB  smax(T& t, C U& u)        { C auto v = S_C<C T>(u); if (v > t) { t = v; re true; } re false; }
TT   IT& rmin(T& x, T& y)          { re (x <= y) ? x : y; }
TT   IT& rmax(T& x, T& y)          { re (x >= y) ? x : y; }
TTUU IT& rmin(T& x, T& y, U& ...z) { re rmin(x, rmin(y, z...)); }
TTUU IT& rmax(T& x, T& y, U& ...z) { re rmax(x, rmax(y, z...)); }
TTU IA maxx(C T& t, C U& u) { using W = TP C_T<T, U>::type; C W v = S_C<C W>(u); C W w = S_C<C W>(t); re (w >= v) ? w : v; }
TTU IA minn(C T& t, C U& u) { using W = TP C_T<T, U>::type; C W v = S_C<C W>(u); C W w = S_C<C W>(t); re (w <= v) ? w : v; }
TTUVV IA maxx(C T& t, C U& u, C V& ...v) { using W = TP C_T<T, U, V...>::type; re maxx(maxx(S_C<C W>(t), S_C<C W>(u)), v...); }
TTUVV IA minn(C T& t, C U& u, C V& ...v) { using W = TP C_T<T, U, V...>::type; re minn(minn(S_C<C W>(t), S_C<C W>(u)), v...); }
TTUVV IB smin(T& t, C U& u, C V& ...v)   { if (CA m = S_C<C T>(minn(u, v...)); m < t) { t = m; re true; } re false; }
TTUVV IB smax(T& t, C U& u, C V& ...v)   { if (CA m = S_C<C T>(maxx(u, v...)); m > t) { t = m; re true; } re false; }

TTT IS fmt(C str f, C T ...x)  { static char s[100100]; sprintf(s, f.c_str(), x...); re str(s); }
IS join(C str s, C vs& v) { if (v.empty()) re ""; str r = tss(v[0]); fr(i, 1, sz(v) - 1) { r += s; r += tss(v[i]); } re r; }

} using namespace FUNCTIONS;

/* @NOTE MAX_STRING_SIZE */ namespace IR {
	CE int N = 1 << 20, M = SCI(2e6 + 10); char z[N], tm[M], *ec; char *ip = z + N, *ep = z + N; int r = 0; auto i_f = stdin;
	IV cl() { ip = z + N; ep = z + N; r = 0; }
	IB rb() { ep = (ip = z) + (r = fread(z, sizeof(z[0]), N, i_f)); re(r != 0); }
	II gc() { if (ip == ep) if (!rb()) re EOF; re *ip++; }
	IB rd(char& x) { int c = gc(); while (isspace(c) and c != EOF) c = gc(); x = S_C<char>(c); if (c == EOF) { ILAF; re false; } re true; }
	TT IB rdz(T& x) {
		int c = gc(); bool ng = false; x = 0; while (isspace(c) and c != EOF and c != '-') c = gc();
		if (c == '-') { ng = true; c = gc(); } if (c == EOF) { ILAF; re false; } if (!isdigit(c)) { assert(false); re false; }
		while (isdigit(c)) { x = x * 10 + (c - '0'); c = gc(); } if (ng) x = -x; re true;
	}
	TMP <szt S, TP F> IB rds(char (&a)[S], C F& f) {
		S_A(S != 0); char* p = a; int c = gc(), i = 0; while (isspace(c) and c != EOF) c = gc(); if (c == EOF) { *p = '\0'; ILAF; re false; }
		while (!f(c) and c != EOF) { if (++i >= SCI(S) - 2) { *p = '\0'; assert(false); } *p++ = S_C<char>(c); c = gc(); } *p = '\0'; re true;
	}
	TS IB   rd(char (&a)[S]) { re rds(a, [](C int c) { re S_C<bool>(isspace(c)); }); }
	TS IB rdln(char (&a)[S]) { re rds(a, [](C int c) { re (c == '\n') or (c == '\r') or (c == '\f'); }); }
	IB rd(ull & x) { if (!rd(tm)) { x = 0; ILAF; re false; } x = strtoull(tm, &ec, 10); if (*ec != '\0' || errno != 0) { ILAF; re false; } re true; }
	TTU IB rdq(T& x, C U& f)  { if (!rd(tm)) { x = 0; ILAF; re false; } x = f(tm, &ec); if (*ec != '\0' || errno != 0) { ILAF; re false; } re true; }
	IV rd(str& x) { rd(tm); x.assign(tm); }
	IB rd(int& x) { re rdz<int>(x); }
	IB rd(dbl& x) { re rdq(x, strtod); }
	IB rd(ll& x)  { re rdz<ll>(x); }
	IB rd(ld& x)  { re rdq(x, strtold); }
	TTU  IV rd(pair<T, U>& x)     { rd(x.fi); rd(x.se); }
	TTUV IV rd(tuple<T, U, V>& x) { auto& [t, u, v] = x; rd(t); rd(u); rd(v); }
	TT   IV rd(vt<T>& a)          { iter(e, a) rd(e); }
	TTUU IV rd(T& x, U& ...y)     { rd(x); rd(y...); }
	IV rdln(str& x) { rdln(tm); x.assign(tm); }
	TT IT nt() { T _; rd(_); re _; }
	TT IN vt<T> nvt(C int n) { vt<T> a(n); iter(e, a) rd(e); re a; }
	IC nc() { re nt<char> (); }
	IA ni() { re nt<int>(); }
	IL nl() { re nt<ll> (); }
	IS ns() { re nt<str>(); }
	IN vc nvc(C int n) { assert(n >= 0); re nvt<char>(n); }
	IN vi nvi(C int n) { assert(n >= 0); re nvt<int>(n); }
	IN vl nvl(C int n) { assert(n >= 0); re nvt<ll>(n); }
	IN vs nvs(C int n) { assert(n >= 0); re nvt<str>(n); }
} using IR::rd, IR::rdln, IR::nc, IR::ni, IR::nl, IR::ns, IR::nt, IR::nvc, IR::nvi, IR::nvl, IR::nvs, IR::nvt;

namespace OW {
	CE int N = 1 << 20; char b[N], cm[1024]; char *C ep = b + N, *ip = b; int w = 0, tm[64]; auto o_f = stdout;
	IV cl() { ip = b; w = 0; }
	IV fb() { int r = fwrite(b, sizeof(b[0]), w, o_f); if (LOCAL) assert(r == w); ip = b; w = 0; }
	IV pc(C int c) { *ip = S_C<char>(c); ++w; if (++ip == ep) fb(); }
	IB pr(C str& s) { trav(c, s) pc(c); re true; }
	IB prl() { pc('\n'); re true; }
	IB pr(C char* a) { while (*a != '\0') pc(*a++); re true; }
	IB pr(C char c) { pc(c); re true; }
	IB pr(char *a) { while (*a != '\0') pc(*a++); re true; }
	TT IB prz(T x) {
		if (x == 0) { pc('0'); re true; } if (x < 0)  { pc('-'); x = -x; } int *C sp = tm, *ptr = tm;
		while (x > 0) { *ptr++ = SCI(x % 10); x /= 10; } do { pc(*--ptr + '0'); } while (ptr != sp); re true;
	}
	IB pr(C int& x) { re prz<int>(x); }
	IB pr(C ll& x)  { re prz<ll>(x); }
	IB pr(C ull& x) { re prz<ull>(x); }
	IB pr(C dbl& x) { sprintf(cm, "%.15f", x); re pr(cm); }
	IB pr(C ld& x)  { ostr o; o.precision(18); o << fixed << x; re pr(o.str()); }
	TT IB pr(C vt<T>& x) { bool f = true; trav(e, x) { if (f) f = false; else pc(' '); pr(e); } re true; }
	TT IB prl(C T& x) { pr(x); re prl(); }
	TTUU IB  pr(C T& t, C U& ...u) { pr(t); pr(' '); re pr(u...); }
	TTUU IB prl(C T& t, C U& ...u) { pr(t); pr(' '); re prl(u...); }
} using OW::pr, OW::prl;

time_point<high_resolution_clock> start_time;
IN dbl get_time() { re S_C< duration<dbl>>(high_resolution_clock::now() - start_time).count(); }
auto original_stdin  = stdin, original_stdout = stdout, original_stderr = stderr;
IV unset_input()  { assert(IR::i_f = original_stdin); }
IV unset_output() { assert(OW::o_f = original_stdout); }
IV set_input(C str& f)  { assert(IR::i_f = fopen(f.data(), "r")); }
IV set_output(C str& f) { assert(OW::o_f = fopen(f.data(), "w+")); }

struct _G_ {
	_G_() {
		if (LOCAL) {

		} else {
			ios_base::sync_with_stdio(false);
			cin.tie(nullptr);
			cout.tie(nullptr);
		}
		start_time = high_resolution_clock::now();
	}
	~_G_() {
		// if (LOCAL) prl(fmt("\n\nTime taken: %.5fs\n", get_time()));
		// OW::fb();
		// OW::cl();
		// fflush(stdout);
	}
} _g_;
/* @END TEMPLATE_CODE */

/* Solution checker */ namespace SolutionChecker {

struct Data {
	int fileNumber;
	int testNumber;
	int beginInput;
	int beginOutput;
	int endInput;
	int endOutput;
	IS t_s() C {
		str r = tss(fileNumber) + ' ';
		r += tss(testNumber) + ' ';
		r += tss(beginInput) + ' ';
		r += tss(endInput) + ' ';
		r += tss(beginOutput) + ' ';
		r += tss(endOutput) + ' ';
		re r;
	}
}; vt<Data> data_vector;

IV _n(int fileNumber = -1, int testNumber = -1) {
	if (fileNumber == -1) {
		data_vector.back().endInput = IR::ip - IR::z;
		data_vector.back().endOutput = OW::ip - OW::b;
	} else {
		data_vector.eb(Data{fileNumber + 1, testNumber + 1, IR::ip - IR::z, OW::ip - OW::b, 0, 0});
	}
}

II countTokens(C str& s) {
	int ans = 0; str t; istr i(s); while (i >> t) ++ans; re ans;
}

IV _cs(C bool multipleTestCases, C int localTestCases, C bool _check ) {
	if (!_check) {
		ofstream f("stderr.txt");
		assert(fclose(OW::o_f) == 0); OW::fb(); OW::cl();
		assert(fclose(IR::i_f) == 0); IR::cl();
		ifstream completeInputFileForAllFileNumbers("input.txt");
		ifstream completeOutputFileForAllFileNumbers("output.txt");
		ifstream completeExpectedOutputFileForAllFileNumbers("output2.txt");
		str temp;
		str completeInputForAllFileNumbers;  while (getline(completeInputFileForAllFileNumbers, temp)) completeInputForAllFileNumbers += temp + '\n';
		str completeOutputForAllFileNumbers; while (getline(completeOutputFileForAllFileNumbers, temp)) completeOutputForAllFileNumbers += temp + '\n';
		str completeExpectedOutputForAllFileNumbers;  while (getline(completeExpectedOutputFileForAllFileNumbers, temp)) completeExpectedOutputForAllFileNumbers += temp + '\n';
		completeInputFileForAllFileNumbers.close();
		completeOutputFileForAllFileNumbers.close();
		completeExpectedOutputFileForAllFileNumbers.close();
		IR::i_f = fopen("input.txt", "r");  assert(IR::i_f);
		OW::o_f = fopen("output.txt", "a"); assert(OW::o_f);
		f << completeInputForAllFileNumbers << "\n\n\n";
		f << completeOutputForAllFileNumbers << "\n\n\n";
		f << completeExpectedOutputForAllFileNumbers << "\n\n\n";
		f.close();
		re;
	}
	ofstream f("stderr.txt");
	if (!multipleTestCases) {
		bool b = true;
		OW::fb(); OW::cl(); assert(fclose(OW::o_f) == 0);
		fr(fileNumber, 1, localTestCases) {
			ifstream expectedOutputFileForThisFileNumber(str("out") + std::to_string(fileNumber) + ".txt");
			ifstream inputFileForThisFileNumber(str("in") + std::to_string(fileNumber) + ".txt");
			ifstream completeOutputFileForAllFileNumbers("output.txt");
			int tokenNumber = 1; str temp; bool okFileNumber = true;
			str expectedOutputForThisFileNumber; while (getline(expectedOutputFileForThisFileNumber, temp)) expectedOutputForThisFileNumber += temp + '\n';
			str inputForThisFileNumber; while (getline(inputFileForThisFileNumber, temp)) inputForThisFileNumber += temp + '\n';
			str completeOutputForAllFileNumbers; while (getline(completeOutputFileForAllFileNumbers, temp)) completeOutputForAllFileNumbers += temp + '\n';
			expectedOutputFileForThisFileNumber.close(); inputFileForThisFileNumber.close(); completeOutputFileForAllFileNumbers.close();
			str outputForThisFileNumber; trav(dt, data_vector) if (dt.fileNumber == fileNumber) outputForThisFileNumber = completeOutputForAllFileNumbers.substr(dt.beginOutput, dt.endOutput - dt.beginOutput);
			istr expectedOutputStreamForThisFileNumber(expectedOutputForThisFileNumber);
			istr outputStreamForThisFileNumber(outputForThisFileNumber);
			auto message = [&](C str& et, C str& ot) {
				char s[1024]; okFileNumber = false; b = false;
				sprintf(s, "[%d#%d] %s->%s\n", fileNumber, tokenNumber, ot.c_str(), et.c_str()); f << s;
			};
			str et, ot;
			while (expectedOutputStreamForThisFileNumber >> et) {
				if (outputStreamForThisFileNumber >> ot) {
					if (et != ot) {
						message(et, ot);
					} else {
						// correct
						// message(et, ot);
					}
				} else {
					message(et, "");
				}
				++tokenNumber;
			}
			if (outputStreamForThisFileNumber >> ot) {
				// extra tokens in output
				message("", ot);
			}
			if (!okFileNumber) {
				// char s[1024];
				// sprintf(s, "\n[%d] [INPUT, EXPECTED OUTPUT, OUTPUT]:\n%s\n%s\n%s\n", fileNumber, inputForThisFileNumber.c_str(), expectedOutputForThisFileNumber.c_str(), outputForThisFileNumber.c_str());
				f << fmt("\n[%d] [INPUT, EXPECTED OUTPUT, OUTPUT]:\n%s\n%s\n%s\n", fileNumber, inputForThisFileNumber.c_str(), expectedOutputForThisFileNumber.c_str(), outputForThisFileNumber.c_str());
			}
		}
		IR::i_f = fopen("input.txt", "r");  assert(IR::i_f); IR::cl();
		OW::o_f = fopen("output.txt", "a"); assert(OW::o_f); OW::cl();
		if (b) {
			cerr << "ALL CORRECT" << endl;
			f << "ALL CORRECT" << endl;
		}
	} else { // multiple test cases per file
		bool b = true;
		assert(fclose(IR::i_f) == 0);
		assert(fclose(OW::o_f) == 0);

		// trav(e, data_vector) f << e.t_s() << '\n';
		ifstream completeInputFileForAllFileNumbers("input.txt");
		ifstream completeOutputFileForAllFileNumbers("output.txt");
		str temp;
		str completeOutputForAllFileNumbers; while (getline(completeOutputFileForAllFileNumbers, temp)) completeOutputForAllFileNumbers += temp + '\n';
		str completeInputForAllFileNumbers;  while (getline(completeInputFileForAllFileNumbers, temp)) completeInputForAllFileNumbers += temp + '\n';

		map<pii, str> input_map;
		map<pii, str> output_map;
		map<pii, str> expected_output_map;
		map<pii, int> total_tokens_in_output;
		map<pii, int> total_tokens_before_output;
		map<int, int> number_of_testcases_in_file;


		trav(dt, data_vector) {
			input_map[{dt.fileNumber, dt.testNumber}] = completeInputForAllFileNumbers.substr(dt.beginInput, dt.endInput - dt.beginInput);
			output_map[{dt.fileNumber, dt.testNumber}] = completeOutputForAllFileNumbers.substr(dt.beginOutput, dt.endOutput - dt.beginOutput);
			total_tokens_in_output[{dt.fileNumber, dt.testNumber}] = countTokens(output_map[{dt.fileNumber, dt.testNumber}]);
			total_tokens_before_output[{dt.fileNumber, dt.testNumber + 1}] = total_tokens_before_output[{dt.fileNumber, dt.testNumber}] + total_tokens_in_output[{dt.fileNumber, dt.testNumber}];

		}

		fr(fileNumber, 1, localTestCases) {
			ifstream expectedOutputFileForThisFileNumber(str("out") + std::to_string(fileNumber) + ".txt");;
			ifstream inputFileForThisFileNumber(str("in") + std::to_string(fileNumber) + ".txt");

			str inputForThisFileNumber; while (getline(inputFileForThisFileNumber, temp)) inputForThisFileNumber += temp + '\n';
			str expectedOutputForThisFileNumber; while (getline(expectedOutputFileForThisFileNumber, temp)) expectedOutputForThisFileNumber += temp + '\n';
			int numberOfTestCasesInThisFile; assert(istr(inputForThisFileNumber) >> numberOfTestCasesInThisFile); assert(numberOfTestCasesInThisFile >= 1);
			number_of_testcases_in_file[fileNumber] = numberOfTestCasesInThisFile;

			fr(testNumber, 1, numberOfTestCasesInThisFile) {
				int before = total_tokens_before_output[{fileNumber, testNumber}];
				int current = total_tokens_in_output[{fileNumber, testNumber}];
				istr ii(expectedOutputForThisFileNumber);
				int tk = 0;
				while (getline(ii, temp)) {
					int tkc = countTokens(temp);
					if (tk + tkc <= before) {
						tk += tkc;
						continue;
					}
					expected_output_map[{fileNumber, testNumber}] += temp + '\n';
					tk += tkc;
					if (tk + tkc > before + current) {
						break;
					}
				}
			}
			inputFileForThisFileNumber.close();
			expectedOutputFileForThisFileNumber.close();
		}
		fr(fileNumber, 1, localTestCases) {
			bool okFileNumber = true;
			fr(testNumber, 1, number_of_testcases_in_file[fileNumber]) {
				bool okTestNumber = true;
				str outputForThisTestNumber = output_map[{fileNumber, testNumber}];
				str inputForThisTestNumber = input_map[{fileNumber, testNumber}];
				str expectedOutputForThisTestNumber = expected_output_map[{fileNumber, testNumber}];

				istr outputStreamForThisTestNumber(outputForThisTestNumber);
				istr expectedOutputStreamForThisTestNumber(expectedOutputForThisTestNumber);

				int tokenNumber = 1;
				auto message = [&](C str& et, C str& ot) {
					char s[1024]; okFileNumber = false; b = false; okTestNumber = false;
					if (localTestCases == 1) { sprintf(s, "[%d#%d] %s->%s\n", testNumber, tokenNumber, ot.c_str(), et.c_str()); f << s; }
					else { sprintf(s, "[%d.%d#%d] %s->%s\n", fileNumber, testNumber, tokenNumber, ot.c_str(), et.c_str()); f << s; }
				};

				str et, ot;
				while (expectedOutputStreamForThisTestNumber >> et) {
					if (outputStreamForThisTestNumber >> ot) {
						if (et != ot) {
							message(et, ot);
						} else {
							// correct
							// message(et, ot);
						}
					} else {
						message(et, "");
					}
					++tokenNumber;
				}
				if (outputStreamForThisTestNumber >> ot) {
					// extra tokens in output
					message("", ot);
				}
				if (!okTestNumber) {
					char s[1024];
					if (localTestCases == 1) { sprintf(s, "\n[%d] [INPUT, EXPECTED OUTPUT, OUTPUT]:\n%s\n%s\n%s\n", testNumber, inputForThisTestNumber.c_str(), expectedOutputForThisTestNumber.c_str(), outputForThisTestNumber.c_str()); f << s; }
					else { sprintf(s, "\n[%d.%d] [INPUT, EXPECTED OUTPUT, OUTPUT]:\n%s\n%s\n%s\n", fileNumber, testNumber, inputForThisTestNumber.c_str(), expectedOutputForThisTestNumber.c_str(), outputForThisTestNumber.c_str()); f << s; }
				}
			}
			if (!okFileNumber) {

			}
		}
		completeInputFileForAllFileNumbers.close();
		completeOutputFileForAllFileNumbers.close();
		IR::i_f = fopen("input.txt", "r");  assert(IR::i_f);  IR::cl();
		OW::o_f = fopen("output.txt", "a"); assert(OW::o_f); OW::cl();
		if (b) {
			cerr << "ALL CORRECT" << endl;
			f << "ALL CORRECT" << endl;
		}
	}
	f.close();
}

} using namespace SolutionChecker;

/*RandomUtils*/ namespace RU {

	szt f2(uint x) { x ^= x >> 16; x *= 0x7feb352dU; x ^= x >> 15; x *= 0x846ca68bU; re (x ^ (x >> 16)); }
	uint f3(uint x) { x ^= x >> 17; x *= 0xed5ad4bbU; x ^= x >> 11; x *= 0xac4c1b51U; x ^= x >> 15; x *= 0x31848babU; re (x ^ (x >> 14)); }
	ull f64(ull x)  { x += 0x9e3779b97f4a7c15U; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9U; x = (x ^ (x >> 27)) * 0x94d049bb133111ebU; re x ^ (x >> 31); }
	char c; vc v(1); ull X = f64(random_device()() + steady_clock::now().time_since_epoch().count() + (int)(&c) + (int)(&(v[0])) + 7); mt19937_64 mrand64(f64(X)); // [0, 2^64 - 1]
	struct hashi   { szt operator () (C int x) C { re (szt) f3(x + (szt) X); }; };
	struct hashull { szt operator () (C ull x) C { re (szt) f64(x + X); } };
	TT using uid = uniform_int_distribution<T>;  TT using urd = uniform_real_distribution<T>;

	uid<int> uidi(0, numeric_limits<int>::max()); uid<ll>  uidl; /* [0, b) */ uid<ull> uidull(0); /* [0, b) */ urd<dbl> urdd(0, 1); // [0, 1)
	urd<ld>  urdld(0, nextafter<ld>(1.0, numeric_limits<ld>::max())); // [0, 1]

	// IA ri(C int a, C int b) { static uidi(a, b + 1); re uidi(mrand64); } // [a, b]
	IA ri(C int a, C int b)   { assert(b >= a); re (uidi(mrand64) % (b - a + 1)) + a; }   // [a, b]
	IA rl(C ll a, C ll b)     { assert(b >= a); re (uidl(mrand64) % (b - a + 1)) + a; }   // [a, b]
	IA rull(C ull a, C ull b) { assert(b >= a); re (uidull(mrand64) % (b - a + 1)) + a; } // [a, b]

	IA rc() { re (char) ('a' + ri(0, 25)); }  IA rb() { re (bool) uidi(mrand64) % 2; }

	IA rf(C float a, C float b) { assert(b > a); static urd<float> _(a, b); re _(mrand64); } // [a, b)
	IA rdbl(C dbl a, C dbl b)   { assert(b > a); re urdd(mrand64) * (b - a) + a; }           // [a, b)
	IA rld(C ld a, C ld b)      { assert(b > a); re urdld(mrand64) * (b - a) + a; }          // [a, b]

	IA rvb(C int n) { vb a(n); fr(i, n) a[i] = rb(); re a; }
	IA rvc(C int n) { vc a(n); iter(e, a) e = rc(); re a; }
	IA rs(C int n)  { str a(n, 'a'); iter(e, a) e = rc(); re a; }

	IA rvi(C int n, C int a, C int b) { assert(a <= b); vi x(n); iter(e, x) e = ri(a, b); re x; }   IA rvl(C int n, C ll a, C ll b)     { assert(a <= b); vl x(n); iter(e, x) e = rl(a, b); re x; }
	IA rvd(C int n, C dbl a, C dbl b) { assert(a < b); vd x(n); iter(e, x) e = rdbl(a, b); re x; }  IA rvull(C int n, C ull a, C ull b) { assert(a <= b); vt<ull> x(n); iter(e, x) e = rull(a, b); re x; }

} using RU::hashi, RU::hashull, RU::rb, RU::rc, RU::ri, RU::rl, RU::rull, RU::rf, RU::rdbl, RU::rld, RU::rs, RU::rvb, RU::rvc, RU::rvi, RU::rvl, RU::rvull;

/*
	// ar<int, 4> ar_={1, 2, 3, 4};
	// tr(ar_);tr(tss(ar_));tr(tss(ar_, 1, 2));tr(tss(ar_, 3));

	// vt<int> vt_={1, 2, 3, 4};
	// tr(vt_);tr(tss(vt_));tr(tss(vt_, 1, 2));tr(tss(vt_, 3));

	// f_l<int> f_l_={1, 2, 3, 4};
	// tr(f_l_);tr(tss(f_l_));tr(tss(f_l_, 1, 2));tr(tss(f_l_, 3));

	// deque<int> dq_={1, 2, 3, 4};
	// tr(dq_);tr(tss(dq_));tr(tss(dq_, 1, 2));tr(tss(dq_, 3));

	// list<int> li_={1, 2, 3, 4};
	// tr(li_);tr(tss(li_));tr(tss(li_, 1, 2));tr(tss(li_, 3));


	// set<int> set_={1, 2, 3, 4};
	// tr(set_);tr(tss(set_));tr(tss(set_, 1, 2));tr(tss(set_, 3));

	// multiset<int> mset_={1, 1, 2, 3, 4};
	// tr(mset_);tr(tss(mset_));tr(tss(mset_, 1, 2));tr(tss(mset_, 3));

	// map<int, int> map_={{1, 1}, {2, 4}, {3, 6}, {4, 0}};
	// tr(map_);tr(tss(map_));tr(tss(map_, 1, 2));tr(tss(map_, 3));

	// multimap<int, int> mmap_={{1, 1}, {2, 4}, {3, 6}, {4, 0}, {4, 3}};
	// tr(mmap_);tr(tss(mmap_));tr(tss(mmap_, 1, 2));tr(tss(mmap_, 3));

	// u_s<int> u_s_={1, 2, 3, 4};
	// tr(u_s_);tr(tss(u_s_));tr(tss(u_s_, 1, 2));tr(tss(u_s_, 3));

	// u_ms<int> umset_={1, 1, 2, 3, 4};
	// tr(umset_);tr(tss(umset_));tr(tss(umset_, 1, 2));tr(tss(umset_, 3));

	// u_m<int, int> umap_={{1, 1}, {2, 4}, {3, 6}, {4, 0}};
	// tr(umap_);tr(tss(umap_));tr(tss(umap_, 1, 2));tr(tss(umap_, 3));

	// u_mm<int, int> ummap_={{1, 1}, {2, 4}, {3, 6}, {4, 0}};
	// tr(ummap_);tr(tss(ummap_));tr(tss(ummap_, 1, 2));tr(tss(ummap_, 3));

	// @TODO stack, p_q, queue, and templated like p_q<less<int>>, set<int, less<int>>, o_s, gp_m, cc_m

*/
