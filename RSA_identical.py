import math

m = 2
n = 3127
e = 17
c = 0

while(c != m):
	c = pow(m, 17) % 3127
	print(c, "=", m, "^17 % 3127")
	if(c == m):
		print("c =", c)
		print("m =", m)
	else:
		m += 1
