# Write a script that writes the day of the week for the New Year Day,
# for the last x years (x is given as argument).

import datetime

def function6(x):
    # x - last x years

    days = []
    format = "%d-%m-%Y"
    for i in range(0, x):
        date = "31-12-" + str(2020 - i)

        # strptime: to convert from string to date
        datetime_obj = datetime.datetime.strptime(date, format)

        # strftime: to convert from date to string
        day = datetime.datetime.strftime(datetime_obj, "%A")
        days.append((date, day))

    return days


print(function6(3))
