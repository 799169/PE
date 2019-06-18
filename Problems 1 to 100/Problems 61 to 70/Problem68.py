for a in range(1, 10):
	used = set({10, a})
	for b in range(1, 10):
		if b == a: continue
		s = 10 + a + b
		used.add(b)
		for c in range(1, 10):
			zc = 10 + b - c
			if zc <= 0 or zc >= 10 or c == zc or c in used or zc in used: continue
			used.add(c)
			used.add(zc)
			for d in range(1, 10):
				zd = s - c - d
				if zd <= 0 or zd >= 10 or d == zd or d in used or zd in used: continue
				used.add(d)
				used.add(zd)
				for e in range(1, 10):
					ze = s - d - e
					zf = 10 + a - e
					if ze <= 0 or ze >= 10 or e == ze or e in used or ze in used: continue
					if zf <= 0 or zf >= 10 or ze == zf or zf == e or zf in used: continue
					used.add(e)
					used.add(ze)
					used.add(zf)
					v = [(10, a, b), (10 + a - e, b, e), (s - d - e, e, d), (s - c - d, d, c), (10 + b - c, c, a)]
					print (v)
					used.remove(e)
					used.remove(ze)
					used.remove(zf)
				used.remove(d)
				used.remove(zd)
			used.remove(c)
			used.remove(10 + b - c)
		used.remove(b)
	used.remove(a)


w = [(10, 3, 1), (9, 1, 4), (8, 4, 2), (7, 2, 5), (6, 5, 3)]
ww = w[-1:] + w[:-1]
print (ww)

print ("".join("".join(map(str, x)) for x in ww))
