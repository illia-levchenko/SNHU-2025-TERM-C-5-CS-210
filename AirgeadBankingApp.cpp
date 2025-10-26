/*
* AirgeadBankingApp.cpp
*
* console program that shows how an investment grows
* with and without an additional monthly deposit.
*
*   CS-210 Project Two:  Airgead Banking App
*
*      Author : Illia Levchenko
*      Date   : 10/05/2025
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <string>
using namespace std;

struct YearRow {
    int year;
    double yearEndBalance;
    double yearEndInterest;
};

// input validation and value obtaining function for DOUBLE values
double readDouble(const string& prompt, bool allowZero, bool mustBePositive) {
    double inputVal;
    while (true) {
        cout << prompt;
        if (!(cin >> inputVal)) {
            cout << "  Invalid number. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (!allowZero && inputVal == 0.0) {
            cout << "  Zero is not allowed here. Try again.\n";
            continue;
        }
        if (mustBePositive && inputVal < 0.0) {
            cout << "  Please enter a non-negative value.\n";
            continue;
        }
        return inputVal;
    }
}

// input validation and value obtaining function for INT values
int readInt(const string& prompt, int MIN_VAL) {
    int inputVal;
    while (true) {
        cout << prompt;
        if (!(cin >> inputVal)) {
            cout << "  Invalid integer. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (inputVal < MIN_VAL) {
            cout << "  Please enter a value >= " << MIN_VAL << ".\n";
            continue;
        }
        return inputVal;
    }
}

// computing function - deposit occurs at the start of each month, then interest is applied.
vector<YearRow> computeSchedule(double initial, double monthlyDeposit, double annualRatePercent, int years) {
    vector<YearRow> rows;
    rows.reserve(years);

    double balance = initial;
    double monthlyRate = (annualRatePercent / 100.0) / 12.0;

    for (int y = 1; y <= years; ++y) {
        double yearlyInterest = 0.0;

        for (int m = 0; m < 12; ++m) {
            balance += monthlyDeposit;                    // deposit first
            double interest = balance * monthlyRate;      // interest on new balance
            balance += interest;
            yearlyInterest += interest;
        }

        rows.push_back({ y, balance, yearlyInterest });
    }

    return rows;
}

// reporting
void printReport(vector<YearRow>& rows, const string& title) {
    // output table header
    cout << "\n" << title << "\n";
    cout << string(60, '=') << "\n";
    cout << left  << setw(8)  << "Year"
         << right << setw(24) << "Year End Balance"
         << right << setw(28) << "Year End Earned Interest" << "\n";
    cout << string(60, '-') << "\n";

    cout.setf(ios::fixed);
    cout << setprecision(2);

    // output table values
    for (const auto& r : rows) {
        cout << left << setw(8) << r.year
             << right << setw(24) << r.yearEndBalance
             << right << setw(28) << r.yearEndInterest << "\n";
    }
}

// main
int main() {

    // input screen header
    cout << "**********************************\n";
    cout << "*********** Data Input ***********\n";

    double initial = readDouble("Initial Investment Amount: $", false, true);
    double monthlyDeposit = readDouble("Monthly Deposit: $", true, true); // zero allowed
    double annualRate = readDouble("Annual Interest (%): ", true, true);  // zero allowed
    int years = readInt("Number of years: ", 1);

    // pause... Press Enter to continue...
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // consume leftover newline
    cin.get();

    // calculations
    auto noDeposit = computeSchedule(initial, 0.0, annualRate, years);
    auto withDeposit = computeSchedule(initial, monthlyDeposit, annualRate, years);

    // reports
    printReport(noDeposit, "Balance and Interest Without Additional Monthly Deposits");
    printReport(withDeposit, "Balance and Interest With Additional Monthly Deposits");

    return 0;
}
