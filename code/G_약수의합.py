num = int(input())

rst=[]
for i in range(1,num+1):
	if(num%i == 0):
		rst.append(i)

print(sum(rst))
		