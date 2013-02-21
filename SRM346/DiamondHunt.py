#! c:\Python33/python.exe
# -*- coding:utf-8 -*-
#SRM346 division2 easy

class DiamondHunt:
	def countDiamonds(self, s):
		res = 0
		while 1:
			length = len(s)
			flg = 0
			for i in range(0, length-1):
				if s[i] == '<' and s[i+1] == '>':
					s = s[0:i]+s[i+2:length]
					res += 1
					flg += 1
					break
			if flg == 0:
				break
		return res

	def test(self, i, s, ans):
		print("Test Case #" + str(i) + "...", end='')
		res = self.countDiamonds(s)
		if res == ans:
			print("PASSED")
		else:
			print("FAILED")
			print("Expected value is " + str(ans))
			print("But " + str(res) + " is returned")

obj = DiamondHunt()
obj.test(0, "><<><>>><", 3)
obj.test(1, ">>>><<", 0)
obj.test(2, "<<<<<<<<<>>>>>>>>>", 9)
obj.test(3, "><<><><<>>>><<>><<><<>><<<>>>>>><<<", 14)