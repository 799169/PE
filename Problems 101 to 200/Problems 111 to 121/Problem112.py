from random import randint

import sys
sys.stdout = open("output.txt", "w")

"""
For d=1..9 and i=0..9:
dp1[d][i] = no. of d digit increasing numbers with first digit = i
dp2[d][i] = no. of d digit decreasing numbers with last digit = i
dp22[d][i] = no. of d digit decreasing numbers with first digit = i
inc(n) = no. of d digit increasing numbers <= n, where 'n' has 'd' digits
dec(n) = no. of d digit decreasing numbers <= n, where 'n' has 'd' digits

"""

# dp1[d][i] for d=1..9 and i=1..9
dp1 = [[0]*10 for _ in range(10)]
for i in range(0, 9 + 1): dp1[1][i] = 1
for d in range(2, 9 + 1):
	for i in range(1, 9 + 1):
		dp1[d][i] = sum(dp1[d-1][j] for j in range(i, 9+1))

# for j in dp1: print(j)

def DP1(d, i):
	c = 0
	if i==0:
		return 1 if d==1 else 0
	if d==2:
		for i2 in range(i, 10):
			c += 1
	if d==3:
		for i2 in range(i, 10):
			for i3 in range(i2, 10):
				c += 1
	if d==4:
		for i2 in range(i, 10):
			for i3 in range(i2, 10):
				for i4 in range(i3, 10):
					c += 1
	if d==5:
		for i2 in range(i, 10):
			for i3 in range(i2, 10):
				for i4 in range(i3, 10):
					for i5 in range(i4, 10):
						c += 1
	if d==6:
		for i2 in range(i, 10):
			for i3 in range(i2, 10):
				for i4 in range(i3, 10):
					for i5 in range(i4, 10):
						for i6 in range(i5, 10):
							c += 1
	return c

for d in range(2, 6):
	for i in range(0, 10):
		if(dp1[d][i] != DP1(d, i)):
			print(d, i, dp1[d][i], DP1(d, i))

# dp2[d][i] for d=1..9 and i=0..9
dp2 = [[0]*10 for _ in range(10)]
for i in range(0, 9 + 1): dp2[1][i] = 1
for d in range(2, 10): dp2[d][0] = 1
for d in range(2, 9 + 1):
	for i in range(1, 9 + 1):
		dp2[d][i] = sum(dp2[d-1][j] for j in range(i, 9+1))
	dp2[d][0] = sum(dp2[d-1][j] for j in range(0, 9+1)) + 0
for d in range(2, 10): dp2[d][0] -= 1

# for j in dp2: print(j)

def DP2(d, i):
	c = 0
	if d==2:
		for i2 in range(max(i, 1), 10):
			c += 1
	if d==3:
		for i2 in range(i, 10):
			for i3 in range(max(i2, 1), 10):
				c += 1
	if d==4:
		for i2 in range(i, 10):
			for i3 in range(i2, 10):
				for i4 in range(max(i3, 1), 10):
					c += 1
	if d==5:
		for i2 in range(i, 10):
			for i3 in range(i2, 10):
				for i4 in range(i3, 10):
					for i5 in range(max(i4, 1), 10):
						c += 1
	if d==6:
		for i2 in range(i, 10):
			for i3 in range(i2, 10):
				for i4 in range(i3, 10):
					for i5 in range(i4, 10):
						for i6 in range(max(i5, 1), 10):
							c += 1
	return c

for d in range(2, 6):
	for i in range(0, 10):
		if(dp2[d][i] != DP2(d, i)):
			print(d, i, dp2[d][i], DP2(d, i))

# dp2[d][i] for d=1..9 and i=0..9
dp22 = [[0]*10 for _ in range(10)]
for i in range(0, 9 + 1): dp22[1][i] = 1
for d in range(2, 9 + 1):
	for i in range(1, 9 + 1):
		dp22[d][i] = sum(dp22[d - 1][j] for j in range(1, i + 1)) + 1

# for j in dp22: print(j)

def DP22(d, i):
	c = 0
	if i==0:
		return 1 if d==1 else 0
	if d==2:
		for i2 in range(0, i+1):
			c += 1
	if d==3:
		for i2 in range(0, i+1):
			for i3 in range(0, i2+1):
				c += 1
	if d==4:
		for i2 in range(0, i+1):
			for i3 in range(0, i2+1):
				for i4 in range(0, i3+1):
					c += 1
	if d==5:
		for i2 in range(0, i+1):
			for i3 in range(0, i2+1):
				for i4 in range(0, i3+1):
					for i5 in range(0, i4+1):
						c += 1
	if d==6:
		for i2 in range(0, i+1):
			for i3 in range(0, i2+1):
				for i4 in range(0, i3+1):
					for i5 in range(0, i4+1):
						for i6 in range(0, i5+1):
							c += 1
	return c

# for d in range(2, 6):
# 	for i in range(0, 10):
# 		if(dp22[d][i] != DP22(d, i)):
# 			print(d, i, dp22[d][i], DP22(d, i), "asdasd")
# 			break

def dpp1(d):
	return sum(dp1[d][i] for i in range(1, 10))

def dpp2(d):
	return sum(dp2[d][i] for i in range(0, 10))

def bouncy(d):
	return 9*10**(d-1) - dpp1(d) - dpp2(d) + 9

def inc(n):
	a, d, z = [int(x) for x in str(n)], len(str(n)), 0
	z += sum(dp1[d][k] for k in range(1, a[0]))
	if a[1] < a[0]:
		return z
	for i in range(2, d):
		z += sum(dp1[d - i + 1][k] for k in range(a[i - 2], a[i - 1]))
		if a[i] < a[i-1]:
			return z
	return z + a[d - 1] - a[d - 2] + 1

def is_inc(x):
	a = [int(x) for x in str(x)]
	d = len(a)
	for i in range(d - 1):
		if a[i] > a[i + 1]: return False
	return True

def inc2(x):
	a = [int(x) for x in str(x)]
	d = len(a); c = 0
	for i in range(10**(d-1), x+1):
		if is_inc(i): c += 1
	return c

# for i in range(100, 110):
# 	n = randint(10010, 10**6)
# 	if (inc(n) != inc2(n)):
# 		print(n, inc(n), inc2(n))
# 		break

def dec(n):
	a, d, z = [int(x) for x in str(n)], len(str(n)), 0
	z += sum(dp22[d][k] for k in range(1, a[0]))
	i = 1
	if a[i] > a[i - 1]:
		a[i] = a[i - 1]
		a[i + 1] = 9
	for i in range(2, d):
		if a[i] > a[i - 1]:
			a[i] = a[i - 1]
			if i < d - 1: a[i + 1] = 9
		if a[i - 1] == 0: return z + 1
		z += sum(dp22[d - i + 1][k] for k in range(1, a[i - 1])) + 1
	if n==200:
		print(a)
	return z + a[d - 1] + 1

def is_dec(x):
	a = [int(x) for x in str(x)]
	d = len(a)
	for i in range(d - 1):
		if a[i] < a[i + 1]: return False
	return True

def dec2(x):
	a = [int(x) for x in str(x)]
	d = len(a); c = 0
	for i in range(10**(d-1), x+1):
		if is_dec(i): c += 1
	return c

# for i in range(100, 110):
# 	n = randint(10**4, 10**5)
# 	# n = i
# 	if (dec(n) != dec2(n)):
# 		print(n, dec(n), dec2(n))
# 		break

def dpp22(d):
	return sum(dp22[d][i] for i in range(0, 10))

def bouncy2(d):
	return 9*10**(d-1) - dpp1(d) - dpp22(d) + 9

def d_num(d):
	return 9*10**(d-1)

def d_prop(n):
	d = len(str(n))
	a = [int(x) for x in str(n)]
	t = (n - 10**(d-1) + 1)
	c = t - inc(n) - dec(n) + a[0]
	if a[1] < a[0]: c -= 1
	c += sum(bouncy2(dd) for dd in range(3, d))
	# print(c, t, n)
	# return c / n
	return (c, n)

# d=6
# a1 = sum(bouncy2(dd) for dd in range(3, d+1))
# print(a1, 10**d-1, a1 / (10**d-1))

l1=10**6
l2=2*10**6
for n in range(l1, l2, 100):
	c1, n1 = d_prop(n)
	if 100 * c1 == 99 * n1:
		print("SOLUTION", n)
		break

# dp1 = [[0]*10 for _ in range(10)]; dp2 = [[0]*10 for _ in range(10)]

# # dp1[i][j] = no. of i digit increasing numbers with first digit = j
# # dp2[i][j] = no. of i digit decreasing numbers with first digit = j

# for j in range(1, 10): dp1[1][j] = dp2[1][j] = 1
# dp2[1][0] = 1

# for i in range(2, 10):
# 	dp2[i][0] = 1
# 	for j in range(1, 10):
# 		for k in range(j, 10):
# 			dp1[i][j] += dp1[i-1][k]
# 		for k in range(0, j+1):
# 			dp2[i][j] += dp2[i-1][k]

# # number of d digit increasing numbers
# def inc(d): return sum(dp1[d][1:])

# # number of d digit increasing numbers
# def dec(d): return sum(dp2[d][1:])

# # number of d digit bouncy numbers
# def bnums(d): return 9*(10**(d-1))-inc(d)-dec(d)+9

# # number of bouncy numbers with <= d digits
# def cumulativeb(d): return sum(bnums(k) for k in range(3, d+1))

# # number of increasing d digit numbers < n; (n >= 100, d >= 3)
# def counti(n):
# 	a = [int(x) for x in str(n)];d = len(a)
# 	# print(dp1[d][1:])
# 	# print(dp1[d-1][1:])
# 	# print(dp1[d-2][1:])
# 	# print(a, d)
# 	ans=sum(dp1[d][1:a[0]])
# 	if d > 3:
# 		for dd in range(3, d):
# 			ans += sum(dp1[dd][1:])
# 	if (a[0] > a[1]):
# 		return ans
# 	for k in range(1, d-1):
# 		ans += sum(dp1[d-k][a[k-1]:a[k]])
# 		if a[k] > a[k+1]:
# 			return ans
# 		print (ans)
# 	return ans + a[-1] - a[-2] + 1

# # number of increasing d digit numbers < n; (n >= 100, d >= 3)
# def countd(n):
# 	a = [int(x) for x in str(n)];d = len(a)
# 	# print(dp1[d][1:])
# 	# print(dp1[d-1][1:])
# 	# print(dp1[d-2][1:])
# 	# print(a, d)
# 	ans=sum(dp2[d][1:a[0]])
# 	if d > 3:
# 		for dd in range(3, d):
# 			ans += sum(dp2[dd][1:])
# 	if (a[0] > a[1]):
# 		return ans
# 	for k in range(1, d-1):
# 		ans += sum(dp2[d-k][a[k-1]:a[k]])
# 		if a[k] > a[k+1]:
# 			return ans
# 		print (ans)
# 	return ans + a[-1] - a[-2] + 1

# def countb(n):
# 	return n - counti(n) - countd(n) + [int(x) for x in str(n)][0]
# 	# print(dp1[d][1:])
# 	# print(dp1[d-1][1:])
# 	# print(dp1[d-2][1:])
# 	# print(a, d)
# 	ans=sum(dp1[d][1:a[0]])
# 	if d > 3:
# 		for dd in range(3, d):
# 			ans += sum(dp1[dd][1:])
# 	if (a[0] > a[1]):
# 		return ans
# 	for k in range(1, d-1):
# 		ans += sum(dp1[d-k][a[k-1]:a[k]])
# 		if a[k] > a[k+1]:
# 			return ans
# 		print (ans)
# 	return ans + a[-1] - a[-2] + 1

# def isIncreasing(n):
# 	a = [int(x) for x in str(n)];d = len(a)
# 	for i in range(d-1):
# 		if a[i] > a[i+1]: return False
# 	return True

# def isDecreasing(n):
# 	a = [int(x) for x in str(n)];d = len(a)
# 	for i in range(d-1):
# 		if a[i] < a[i+1]: return False
# 	return True

# def isBouncy(n):
# 	return (not isIncreasing(n)) and (not isDecreasing(n))

# # number of increasing d digit numbers <= n; (n >= 100, d >= 3)
# def brutecountb(n):
# 	d=len(str(n));ans=0;
# 	for i in range(10**(d-1), n+1):
# 		if (isBouncy(i)):
# 			# print(i, isBouncy(i))
# 			ans+=1
# 	if (d > 3):
# 		ans += brutecountb(10**(d-1)-1)
# 	return ans

# def brutecounti(n):
# 	d=len(str(n));ans=0;
# 	for i in range(10**(d-1), n+1):
# 		if (isIncreasing(i)):
# 			# print(i, isBouncy(i))
# 			ans+=1
# 	if (d > 3):
# 		ans += brutecounti(10**(d-1)-1)
# 	return ans

# def brutecountd(n):
# 	d=len(str(n));ans=0;
# 	for i in range(10**(d-1), n+1):
# 		if (isDecreasing(i)):
# 			# print(i, isBouncy(i))
# 			ans+=1
# 	if (d > 3):
# 		ans += brutecountd(10**(d-1)-1)
# 	return ans

# # print(dp1[2][1:])
# # print(dp1[3][1:])

# x=59123
# print(counti(x), brutecounti(x), "increasing below", x)

# # print(isBouncy(121))

# print(brutecountb(537), "bouncy below 538")

# def proportionb(d):
# 	return cumulativeb(d) / (10**d - 1)

# print(cumulativeb(3), proportionb(7))

# # print (dp2)

# # no. of increasing numbers with <= d digits

# # 4 digit numbers
# c=0
# # for i in range(1, 10):
# # 	for j in range(i, 10):
# # 		for k in range(j, 10):
# # 			for l in range(k, 10):
# # 				c += 1

# def f3(j):
# 	c=0
# 	for k in range(j+1):
# 		for l in range(k+1):
# 			c+=1
# 	return c
# def f4(j):
# 	c=0
# 	for k in range(j+1):
# 		for l in range(k+1):
# 			for m in range(l+1):
# 				c+=1
# 	return c

# c=0
# for i in range(1, 10):
# 	for j in range(i+1):
# 		for k in range(j+1):
# 			for l in range(k+1):
# 				for t in range(l+1):
# 					c += 1
# # print([f3(k) for k in range(1, 10)])
# # print(sum(dp2[5][1:]), c)

# # for i in dp2[1:]:
# # 	print (i[1:])


