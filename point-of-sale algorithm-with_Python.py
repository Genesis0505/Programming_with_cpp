daily_sales = []
weekly_total = 0
weekly_count = 0
monthly_total = 0
monthly_count = 0

for day in range(1, 31):  # Assuming a month with 30 days for simplicity
    daily_sales_input = int(input("Enter the number of spare parts sold for day {}: ".format(day)))
    daily_sales.append(daily_sales_input)
    daily_total = sum(daily_sales)

    daily_average = daily_total / len(daily_sales)

    weekly_total += daily_total
    weekly_count += len(daily_sales)

    if day % 7 == 0:  # End of the week
        weekly_average = weekly_total / weekly_count
        print("Weekly Average for Week {}: {:.2f}".format(day // 7, weekly_average))
        weekly_total = 0
        weekly_count = 0

    monthly_total += daily_total
    monthly_count += len(daily_sales)

    if day == 30:  # End of the month
        monthly_average = monthly_total / monthly_count
        print("Monthly Average: {:.2f}".format(monthly_average))
