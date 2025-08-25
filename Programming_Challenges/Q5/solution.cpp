#include <iostream>
#include <iomanip>
using namespace std;

/*
## Monthly Budget
### A student has established the following monthly budget:
```
Housing 500.00
Utilities 150.00
Household Expenses 65.00
Transportation 50.00
Food 250.00
Medical 30.00
Insurance 100.00
Entertainment 150.00
Clothing 75.00
Miscellaneous 50.00
```
### Write a program that has a MonthlyBudget structure designed to hold each of these expense categories. The program should pass the structure to a function that asks the user to enter the amounts spent in each budget category during a month. The program should then pass the structure to a function that displays a report indicating the amount over or under in each category, as well as the amount over or under for the entire monthly budget.
*/

struct MonthlyBudget
{
    double housing = 500.00;
    double utilities = 150.00;
    double householdExpenses = 65.00;
    double transportation = 50.00;
    double food = 250.00;
    double medical = 30.00;
    double insurance = 100.00;
    double entertainment = 150.00;
    double clothing = 75.00;
    double miscellaneous = 50.00;
};

void getExpenses(MonthlyBudget &spent)
{
    cout << "Enter the amount spent in each category during the month:" << endl;
    cout << "Housing: ";
    cin >> spent.housing;
    cout << "Utilities: ";
    cin >> spent.utilities;
    cout << "Household Expenses: ";
    cin >> spent.householdExpenses;
    cout << "Transportation: ";
    cin >> spent.transportation;
    cout << "Food: ";
    cin >> spent.food;
    cout << "Medical: ";
    cin >> spent.medical;
    cout << "Insurance: ";
    cin >> spent.insurance;
    cout << "Entertainment: ";
    cin >> spent.entertainment;
    cout << "Clothing: ";
    cin >> spent.clothing;
    cout << "Miscellaneous: ";
    cin >> spent.miscellaneous;
}

void reportExpenses(const MonthlyBudget &budget, const MonthlyBudget &spent)
{
    cout << "\nExpense Report:\n";
    struct Category
    {
        const char *name;
        double budgeted;
        double spent;
    } categories[] = {
        {"Housing", budget.housing, spent.housing},
        {"Utilities", budget.utilities, spent.utilities},
        {"Household Expenses", budget.householdExpenses, spent.householdExpenses},
        {"Transportation", budget.transportation, spent.transportation},
        {"Food", budget.food, spent.food},
        {"Medical", budget.medical, spent.medical},
        {"Insurance", budget.insurance, spent.insurance},
        {"Entertainment", budget.entertainment, spent.entertainment},
        {"Clothing", budget.clothing, spent.clothing},
        {"Miscellaneous", budget.miscellaneous, spent.miscellaneous}};

    double totalBudget = 0, totalSpent = 0;
    cout << "Category           Budgeted    Spent    Over(+)/Under(-)\n";
    cout << "--------------------------------------------------------\n";
    for (const auto &cat : categories)
    {
        double diff = cat.spent - cat.budgeted;
        cout.width(18);
        cout << left << cat.name;
        cout.width(10);
        cout << right << fixed << setprecision(2) << cat.budgeted;
        cout.width(10);
        cout << right << fixed << setprecision(2) << cat.spent;
        cout.width(10);
        cout << right << fixed << setprecision(2) << diff << endl;
        totalBudget += cat.budgeted;
        totalSpent += cat.spent;
    }
    cout << "--------------------------------------------------------\n";
    cout << "Total Budgeted: " << fixed << setprecision(2) << totalBudget << endl;
    cout << "Total Spent:    " << fixed << setprecision(2) << totalSpent << endl;
    cout << "Overall:        " << fixed << setprecision(2) << (totalSpent - totalBudget)
         << (totalSpent > totalBudget ? " (Over Budget)" : " (Under Budget)") << endl;
}

int main()
{
    MonthlyBudget budget;
    MonthlyBudget spent;
    getExpenses(spent);
    reportExpenses(budget, spent);
    return 0;
}