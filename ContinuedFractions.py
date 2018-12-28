from math import *

(a, b, c) = (0, 1, 1)
D = 23
s = set() 
v = []

for i in range(150):
	d = int(floor((a + b * sqrt(D)) / c))
	v.append(d)
	aa, bb, cc = c * (a - d * c), -1 * b * c, (a - d * c) ** 2 - (D * b * b)
	g = gcd(gcd(int(aa), int(bb)), int(cc))
	a, b, c = aa / g, bb / g, cc / g
	if (a, b, c) in s:
		break
	s.add((a, b, c))


print (v)
