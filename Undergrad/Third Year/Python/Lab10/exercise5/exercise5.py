import time
import sys

x = sys.argv[1]

for i in range(0, int(x)):
	# %d = number day of the month
	# %b = abbreviated month (JAN)
	# %Y = number year
	date = time.strptime("1 JAN {}".format(2019 - i), "%d %b %Y")
	# %A = weekday name (Monday)
	print('Day for {}: {}'.format(2019 - i, time.strftime("%A", date)))

