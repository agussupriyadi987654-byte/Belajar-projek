'''
 Level1

 1
 23
 456
 78910

 Level 5

    *
   ***
  *****
 *******

 '''

a = 4
b = 1
for i in range(a):
    for j in range(i+1):
        print(b, end="")
        b+=1
    print()
print()
for i in range(0,a*2,2):
    for j in range(a-i//2+1):
        print(" ", end="")
    for j in range(i+1):
        print("*",end="")
    print()
