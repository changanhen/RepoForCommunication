a=0
n=int(input("请输入n值："))
for i in range(1,n+1):
    a=a+(-1)**(i-1)/(2*i-1)
    print(4*a)
