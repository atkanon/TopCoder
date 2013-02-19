#! c:\Python32/python.exe
# -*- coding:utf-8 -*-
#SRM343 division2 easy 

class PersistentNumber:
	def getPersistence(self, n):
		cnt = 0
		while n > 10:
			cnt += 1
			t = n
			sum = 1
			while t > 1:
				sum *= t%10
				t = int(t/10)
			n = sum
		return cnt
	def test(self, i, n, ans):
		print("Test Case #" + str(i) + "...", end='')
		res = self.getPersistence(n)
		if res == ans:
			print("PASSED")
		else:
			print("FAILED")
			print("\tExpected Value is " + str(ans))
			print("\tBut " + str(res) + " is returned")

obj = PersistentNumber()
obj.test(0, 99, 2)
obj.test(1, 268, 4)
obj.test(2, 6, 0)
obj.test(3, 68889789, 3)
obj.test(4, 86898, 7)
