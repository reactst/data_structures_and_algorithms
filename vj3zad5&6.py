#5
#a
c=2
d=3
print (c<0 and d<0)
#b
print (c%2==0 or d%2==0)
#c
print (c%2==0 and d%2==0 and c>d)
#d
print (c%2==1 or d%2==1)
#e
print (c%2==1 and d%2==1)
#f
print (c%d==0 or d%c==0)
#g
print (c%d==0 or d%c==1)



#6
a=int(input("Unesite 1. broj: "))
b=int(input("Unesite 2. broj: "))
c=int(input("Unesite 3. broj: "))

if (a>b and b>c):
    print ("poredani su",a,b,c)
if (b>a and a>c):
    print ("poredani su",b,a,c)
if (c>a and a>b):
    print ("poredani su",c,a,b)
if (b>c and c>a):
    print ("poredani su",b,c,a)
if (c>b and b>a):
    print ("poredani su",c,b,a)