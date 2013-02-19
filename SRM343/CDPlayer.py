#! c:\Python32/python.exe
# -*- coding:utf-8 -*-
#SRM343 division2 medium

class CDPlayer:
	def isdistinct(self, s, n):
		res = 1
		while 1:
			if len(s) <= n:
				for i in range(0, len(s)):
					for j in range(i+1, len(s)):
						if s[i] == s[j]:
							res = 0
				return res
			else:
				return self.isdistinct(s[0:n], n)*self.isdistinct(s[n:len(s)], n)

	def isRandom(self, list, n):
		s = ""
		for _s in list:
			s += _s
		for i in range(0, n):
			if 1 == self.isdistinct(s[0:i][::-1], n)*self.isdistinct(s[i:len(s)], n):
				return i
		return -1

	def test(self, i, list, n, ans):
		print("Tase Case #" + str(i) + "...", end='')
		res = self.isRandom(list, n)
		if res == ans:
			print("PASSED")
		else:
			print("FAILED")
			print("\tExpected Value is " + str(ans))
			print("\tBut " + str(res) + " is returned")

obj = CDPlayer()
obj.test(0, ["BBAC"], 3, 1)
obj.test(1, ["BACAB", "BCA"], 3, 2)
obj.test(2, ["AAACBACBACBACBACBACBACB"], 3, -1)
obj.test(3, ["ABCDEABDECBAECDEDACB"], 5, 0)
obj.test(4, ["ABCABCABCABCABCABCABC", "ABCABCABCABCABCABCABC"], 22, -1)
obj.test(5, ["AAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAA",
			"AAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAA",
			"AAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAA",
			"AAAAAAAAAAAAAAAA"], 1, 0)
obj.test(6, ["ADEF"], 12, 0)
