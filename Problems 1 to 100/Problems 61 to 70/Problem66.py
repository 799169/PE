from math import *

ans, mx = 5, 9

for D in range(2, 1001):
	(a, b, c) = (0, 1, 1)
	s, v, e, f = set(), [], int(sqrt(D)), False
	if e * e == D: continue
	for i in range(D * 2):
		d = int(floor((a + b * sqrt(D)) / c))
		v.append(d)
		aa, bb, cc = c * (a - d * c), -1 * b * c, (a - d * c) ** 2 - (D * b * b)
		g = gcd(gcd(int(aa), int(bb)), int(cc))
		a, b, c = aa / g, bb / g, cc / g
		if (a, b, c) in s: break
		s.add((a, b, c))
	for i in range(100):
		a, b, j, k = 0, 1, i % len(v[1:]), 0
		while k < i:
			k, j = k + 1, j - 1
			if j < 0: j = len(v[1:]) - 1
			a, b = b, a + b * v[1:][j]
		x = v[0] * b + a
		if x * x - D * b * b == 1:
			f = True
			if x > mx: mx, ans = x, D
			break
	if not f: print ("Increase limit ", D)

print (ans, mx)
