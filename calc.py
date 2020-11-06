
import time
time.sleep(1.27)
print ("EDLE v1.4 framework loaded in 1.27 sec")
grama=int(input("Weight: \n"))
para=int(input("Money: \n"))
jedange=para/grama
print ("1 UNIT costs",jedange, "\n","5 UNITS costs",jedange*5,"\n","15 UNITS costs",jedange*15,"\n")
gramcheck=int(input("How much weight would you like the cost of?\n"))
print (gramcheck,"costs",gramcheck*jedange)
margin=int(input("What is your desired marigin?\n"))
desiredprice=jedange+(margin/100*jedange)
print ("Recommended sale price is ",desiredprice,"for 1 UNIT\n")
saleprice=int(input("How much u sellin? (UNIT)\n"))
print ("Recommeded sale price is: ",saleprice*desiredprice)

