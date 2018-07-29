from urllib2 import urlopen

u = urlopen("https://projecteuler.net/project/resources/p054_poker.txt").read()
z = ['2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A']
n, c, f = 0, 0, lambda x, y: z.index(x[0]) - z.index(y[0])

def rank(h):
  hn, hs, d = [h[i][0] for i in xrange(5)], [h[i][1] for i in xrange(5)], dict()
  for e in h:
    if e[0] not in d: d[e[0]] = 1
    else: d[e[0]] += 1
  if  len(set(hs)) == 1:
    if hn == z[-5:]: return [10]
    if (z.index(hn[0]) <= 8 and all(hn[i + 1] == z[z.index(hn[i]) + 1] for i in xrange(4))):
      return [9, z.index(hn[0])]
  if max(d.values()) >= 4:
    g, h = 0, 0
    for e in d:
        if d[e] >= 4: g = e
        else: h = e
    return [8, z.index(g), z.index(h)]
  if sorted(d.values()) == [2, 3]:
    g, h = 0, 0
    for e in d:
        if d[e] == 3: g = e
        else: h = e
    return [7, z.index(g), z.index(h)]
  if len(set(hs)) == 1: return [6] + [z.index(e) for e in hn[::-1]]
  if (z.index(hn[0]) <= 8) and all(hn[i + 1] == z[z.index(hn[i]) + 1] for i in xrange(4)):
    return [5, z.index(hn[0])]
  if max(d.values()) == 3:
    g, h = 0, []
    for e in d:
        if d[e] == 3: g = e
    return [4, z.index(g)] + [z.index(e) for e in hn[::-1] if e != g]
  if sum(1 if d[e] >= 2 else 0 for e in d) == 2:
    h, g = [], []
    for e in d:
        if d[e] >= 2: h += [z.index(e)]
        else: g += [z.index(e)]
    return [3] + sorted(h)[::-1] + sorted(g)[::-1]
  if max(d.values()) == 2:
    g = 0
    for e in d:
        if d[e] == 2: g = z.index(e)
    return [2, g] + [z.index(e) for e in hn[::-1] if z.index(e) != g]
  return [1] + [z.index(e) for e in hn[::-1]]

for s in u.split("\n"):
  if n == 1000: break
  h1, h2 = sorted(s.split(" ")[0:5], f), sorted(s.split(" ")[5:], f)
  for i, e in enumerate(rank(h1)):
    if e > rank(h2)[i]:
      c += 1
      break
    elif e < rank(h2)[i]: break
  n += 1

print c
