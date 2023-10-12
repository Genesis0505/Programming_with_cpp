#include <iostream>
#include <vector>

int main() {
    std::vector<int> dailySales;
    int weeklyTotal = 0;
    int weeklyCount = 0;
    int monthlyTotal = 0;
    int monthlyCount = 0;

    for (int day = 1; day <= 30; day++) { // Assuming a month with 30 days for simplicity
        int dailySalesInput;
        std::cout << "Enter the number of spare parts sold for day " << day << ": ";
        std::cin >> dailySalesInput;

        dailySales.push_back(dailySalesInput);
        int dailyTotal = 0;
        for (std::vector<int>::iterator it = dailySales.begin(); it != dailySales.end(); ++it) {
            dailyTotal += *it;
        }

        double dailyAverage = static_cast<double>(dailyTotal) / dailySales.size();

        weeklyTotal += dailyTotal;
        weeklyCount += dailySales.size();

        if (day % 7 == 0) { // End of the week
            double weeklyAverage = static_cast<double>(weeklyTotal) / weeklyCount;
            std::cout << "Weekly Average for Week " << (day / 7) << ": " << weeklyAverage << std::endl;
            weeklyTotal = 0;
            weeklyCount = 0;
        }

        monthlyTotal += dailyTotal;
        monthlyCount += dailySales.size();

        if (day == 30) { // End of the month
            double monthlyAverage = static_cast<double>(monthlyTotal) / monthlyCount;
            std::cout << "Monthly Average: " << monthlyAverage << std::endl;
        }
    }

    return 0;
}
