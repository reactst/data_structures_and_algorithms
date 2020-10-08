def isYearLeap(year):
    if year%4==0:
        return True
    else:
        return False

def daysInMonth(year, month):
    if (isYearLeap==True and month==2):
        return 29
    else if (isYearLeap==True and (month==1 or month==3 or month==5 or month==7 or month==8 or month==10 or month==12)):
        return 31
    else if (isYearLeap==False and month==2):
        return 28
    else:
        return 30

testYears = [1900, 2000, 2016, 1987]
testMonths = [2, 2, 1, 11]
testResults = [28, 29, 31, 30]
for i in range(len(testYears)):
	yr = testYears[i]
	mo = testMonths[i]
	print(yr, mo, "->", end="")
	result = daysInMonth(yr, mo)
	if result == testResults[i]:
		print("OK")
	else:
		print("Failed")