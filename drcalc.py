import time
time.sleep(2.27)
print ("EDLE v1.4 framework loaded in 2.27 sec")
grama=int(input("Weight: \n"))
para=int(input("Money: \n"))
jedange=para/grama
print ("1 UNIT costs",jedange, "\n","5 UNITS costs",jedange*5,"\n","15 UNITS costs",jedange*15,"\n")
gramcheck=int(input("How much weight would you like the cost of?\n"))
print (gramcheck,"costs",gramcheck*jedange)