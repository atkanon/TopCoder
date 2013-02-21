#! c:\Python33/python.exe
# -*- coding:utf-8 -*-
#SRM346 division2 medium

n = 10
primes = []

class CommonMultiples:
	def set_prime(self, n):
		global primes
		primes += [2]
		for i in range(3, n+1):
			for j in range(0, len(primes)):
				if i%primes[j] == 0:
					break
				if j == len(primes)-1:
					primes.append(i)
					
	def countCommMult(self, a, lower, upper):
		global primes
		self.set_prime(101)
		multi = 1
		for i in primes:
			cnt = 0
			for j in range(0, len(a)):
				_cnt = 0
				while a[j]%i == 0:
					_cnt += 1
					a[j] /= i
				cnt = max(cnt, _cnt)
			multi *= i**cnt
		return int(upper/multi)-int((lower-1)/multi)

	def test(self, i, a, lower, upper, ans):
		print("Test Case #" + str(i) + "...", end='')
		res = self.countCommMult(a, lower, upper)
		if res == ans:
			print("PASSED")
		else:
			print("FAILED")
			print("Expected value is " + str(ans))
			print("But " + str(res) + " is returned")

obj = CommonMultiples()
obj.test(0, [1, 2, 3], 5, 15, 2)
obj.test(1, [1, 2, 4, 8, 16, 32, 64], 128, 128, 1)
obj.test(2, [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 49], 1, 2000000000, 0)
obj.test(3, [1, 1, 1], 1, 2000000000, 2000000000)