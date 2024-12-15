#include <iostream>
#include <string>

using namespace std;

const int MAX_EXPENSES = 100; 

string expenseNames[MAX_EXPENSES];
float expenseAmounts[MAX_EXPENSES];
string expenseDates[MAX_EXPENSES];
int expenseCount = 0;


void addExpense();
void viewExpenses();
void updateExpense();
void deleteExpense();
void menu();

int main() {
    int choice;
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                updateExpense();
                break;
            case 4:
                deleteExpense();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

void menu() {
    cout << "\n========== Daily Expenses Tracker ==========" << endl;
    cout << "1. Add Expense" << endl;
    cout << "2. View Expenses" << endl;
    cout << "3. Update Expense" << endl;
    cout << "4. Delete Expense" << endl;
    cout << "5. Exit" << endl;
}

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        cout << "Error: Cannot add more expenses. Maximum limit reached." << endl;
        return;
    }

    cout << "Enter the name of the expense: ";
    getline(cin, expenseNames[expenseCount]);
    cout << "Enter the amount: ";
    cin >> expenseAmounts[expenseCount];
    cin.ignore(); 
    cout << "Enter the date (DD/MM/YYYY): ";
    getline(cin, expenseDates[expenseCount]);
    

    expenseCount++;
    cout << "Expense added successfully!" << endl;
}

void viewExpenses() {
    if (expenseCount == 0) {
        cout << "No expenses to display." << endl;
        return;
    }

    cout << "\n==========List of Expenses==========" << endl;
    for (int i = 0; i < expenseCount; i++) {
        cout << i + 1 << ". " << expenseNames[i] << " - Php" << expenseAmounts[i] << " - " << expenseDates[i] << endl;
    }
}

void updateExpense() {
    if (expenseCount == 0) {
        cout << "\nNo expenses to update.\n";
        return;
    }

    int index;
    cout << "\nEnter the number of the expense to update: ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > expenseCount) {
        cout << "Invalid expense number.\n";
        return;
    }

    index--;
    cout << "Enter the new name of the expense: ";
    getline(cin, expenseNames[index]);
    cout << "Enter the new amount: ";
    cin >> expenseAmounts[index];
    cin.ignore();
    cout << "Enter the new date (DD-MM-YYYY): ";
    getline(cin, expenseDates[index]);
    

    cout << "Expense updated successfully!" << endl;
}


void deleteExpense() {
    if (expenseCount == 0) {
        cout << "\nNo expenses to delete.\n";
        return;
    }

    int index;
    cout << "\nEnter the number of the expense to delete: ";
    cin >> index;
    cin.ignore(); 

    if (index < 1 || index > expenseCount) {
        cout << "Invalid expense number." << endl;
        return;
    }

    index--;
    for (int i = index; i < expenseCount - 1; i++) {
        expenseNames[i] = expenseNames[i + 1];
        expenseAmounts[i] = expenseAmounts[i + 1];
    }

    expenseCount--;
    cout << "Expense deleted successfully!" << endl;
}
