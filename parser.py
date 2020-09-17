import sys, os, filecmp, requests, shutil, re, time, subprocess, threading, datetime
from html.parser import HTMLParser
from bs4 import BeautifulSoup
from urllib.request import urlopen

loadproblem=False;precompile=False;update_snippets=False;

original_stdout = sys.stdout; original_stdin = sys.stdin;
# sys.stdin = open("input.txt", "r"); sys.stdout = open("output.txt", "w")

# -Wunused-local-typedefs add this w-no-unused

# loadproblem = True
precompile=True; update_snippets=True

# new one is on Python2.py

url = """
https://codeforces.com/problemset/problem/546/B


"""

t1="""<snippet>
	<content><![CDATA[
"""

t2="""#ifdef LOCAL
	#include "utils.h"
#else
	#undef _GLIBCXX_DEBUG
	#undef _GLIBCXX_DEBUG_PEDANTIC
	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>
	#define LOCAL     false
	#define nil       0;
	#define tr(x...)  0;
	#define _n(x...)  0
	#define _cs(x...) 0
	using namespace std; using namespace chrono; using namespace __gnu_pbds;
#endif

#if (not LOCAL) /* @BEGIN TEMPLATE_CODE */

"""

t3="""#endif /* @END TEMPLATE_CODE */
"""

t4=r"""

int _l = 1, _t = 1, MXITR = SCI(1e7); CE ll infl = SCL(4.6e18 + 7); CE bool _c = 1;
CE int inf = SCI(1e9 + 6), md = SCI(1e9 + 7); CE bool _m = 0;
#define DEBUG_MODE 1

bool solve(C int testNumber) {

	re true;
}

void solve(int argc, char* argv[]) {

	if (LOCAL) {
		set_input("input.txt");
		set_output("output.txt");
		rd(_l);
	}
	fr(l, _l) { if (_m) rd(_t); fr(i, _t) { _n(l, i); solve(i + 1); _n(); } } OW::fb();
	if (LOCAL) prl(fmt("\n\nTime taken: %.5fs\n", get_time()));
	OW::fb(); OW::cl(); fflush(stdout);
}

int main(int argc, char* argv[]) { solve(argc, argv); _cs(_m, _l, _c); re 0; }

]]></content>
	<tabTrigger>qwe</tabTrigger>
	<scope>source.cpp, source.c++</scope>
</snippet>
"""

num_cases = 1

def get_test_cases():
	global url; url = url.strip().split()[0]
	bs = BeautifulSoup(requests.get(url).content, 'html.parser')
	atcoder = False; codeforces = True; topcoder = False; codechef = False;
	if (url.find("atcoder") != -1):
		atcoder = True; codeforces = False;
	elif (url.find("codechef") != -1):
		codechef = True; codeforces = False;
	elif (url.find("topcoder") != -1):
		topcoder = True; codeforces = False;
	for br in bs.find_all("br"): br.replace_with("\n")
	input_a = []; output_a = []; global num_cases
	if atcoder:
		span = bs.find_all('span', class_="lang-en")[0]
		cnt = 0
		for i in range(2): bs.find('div', class_="io-style").extract()
		for div in span.find_all('div', class_="part"):
			for pre in div.find_all('pre'):
				if (cnt % 2 == 0): input_a.append(pre.text.strip())
				else: output_a.append(pre.text.strip())
				cnt += 1
		num_cases = (cnt // 2)
	elif codeforces:
		for div in bs.find_all('div', class_="input"):
			for pre in div.find_all('pre'): input_a.append(pre.text.strip())
		for div in bs.find_all('div', class_="output"):
			for pre in div.find_all('pre'): output_a.append(pre.text.strip())
		num_cases = len(input_a)
	elif topcoder:
		num_cases = 0
	elif codechef:
		num_cases = 0
	with open("input.txt", "w") as f: f.write(str(num_cases) + '\n\n')
	with open("output2.txt", "w") as f: pass
	for (i, e) in enumerate(input_a):
		g = str(i+1) + ".txt"
		with open("in" + g, "w") as f: f.write(e + '\n')
		with open("inn" + g, "w") as f: f.write("1\n" + e + '\n')
		with open("out" + g, "w") as f: f.write(output_a[i] + '\n')
		with open("input.txt", "a") as f: f.write(e + '\n\n')
		with open("output2.txt", "a") as f: f.write(output_a[i] + '\n\n')
	with open("stderr.txt", "w") as fe:
		with open("input.txt", "r") as fi: fe.write(fi.read())
		with open("output2.txt", "r") as fi: fe.write(fi.read())
if loadproblem: get_test_cases()

def fix_format(s): return s.replace('$', '\\$').replace('}', '\\}')
def update_sublime_snippets():
	with open("C:/Users/admin/Desktop/Programming/code/utils.h") as utilsh:
		global t1, t2, t3, t4
		s = str(utilsh.read())
		i1=s.find("/* @BEGIN TEMPLATE_CODE */")
		j1=s.find("/* @END TEMPLATE_CODE */")
		i2=s.find("/* @BEGIN TEMPLATE_CODE */", i1+1)
		j2=s.find("/* @END TEMPLATE_CODE */", i2+1)
		a1=fix_format(s[i1+27:j1])
		a2=fix_format(s[i2+26:j2]);
		tt1=fix_format(t1); tt2=fix_format(t2); tt3=fix_format(t3); tt4=fix_format(t4);
		final_str = tt1+"${1:"+tt2+a1+a2+tt3+"}"+tt4;
		with open("C:\\Users\\admin\\AppData\\Roaming\\Sublime Text 3\\Packages\\User\\qwe.sublime-snippet", 'w') as qwe:
			qwe.write(final_str)

def precompile_utils_header():
	os.system("cd C:\\Users\\admin\\Desktop\\Programming\\code")
	os.system("C:\\mingw\\bin\\g++ -Wall  -Wno-reorder -fmax-errors=8 -Wshift-overflow=2 -Wno-unused-but-set-variable -Wconversion -Wfloat-equal -Wshadow -Wno-unused-parameter -Wno-misleading-indentation -Wno-unused-variable -Wno-unused-value -Wextra -Wl,--stack=268435456 -O2 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -std=c++2a -DLOCAL=1 utils.h")

if precompile: precompile_utils_header()
if update_snippets: update_sublime_snippets()


def main():
	pass

if __name__ == "__main__":
	main()
