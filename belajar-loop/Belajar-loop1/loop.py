'''
tantangan :
step harus positif

Target :

Level1
****
***
**
*
'''
a:int = 4
for i in range(a):
    for j in range(a-i):
        print("*",end="")
    print()

print()
'''
Level2
1
22
333
4444
'''
for i in range(a):
    for j in range(i+1):
        print(i+1,end="")
    print()

print()
'''
Level2
1
12
123
1234
'''
for i in range(a):
    for j in range(i+1):
        print(j+1,end="")
    print()
