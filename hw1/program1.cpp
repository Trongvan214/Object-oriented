//Author: Trong Van
//Student ID: x454v285
//Programming Number: 1

//Description:  an account program the help keep track of money

#include <iostream>
#include <string>
#include <math.h>       /* fabs, round */
#include <iomanip>


using namespace std;

struct Money {
    int d;
    int c;
};

struct Account {
    double interest;
    Money money;
    string name;
};

//function prototype
Account createAccount();
Account deposit(Account account, Money deposit);
Money withdraw(Account &account, Money withdraw);
void accrue(Account &account);
void print(Account account);
void print(Money money);
Money doubleToStruct(double money);
double structToDouble(Money money);

int main ()
{
    //test case
    //tip: to test all cases type start balance $100.* / interest  < 10
    //test amounts
    Money deposit1 = {75,5001}
        ,deposit2 = {-33, -2};

    Money withdraw1 = {75,5001}
        , withdraw2 = {-20, -20}
        , withdraw3 = {130, 50}
        , withdraw4 = {200, 34};

    //make new account
    Account guest = createAccount();

    //deposit
    guest = deposit(guest, deposit1);

    //withdraw
    withdraw(guest, withdraw1);

    //accrue
    accrue(guest);

    //deposit negative amount
    guest = deposit(guest, deposit2);
    //withdraw negative amount
    withdraw(guest, withdraw2);

    //withdraw and leave neg amount in account > -50
    withdraw(guest, withdraw3);

    //withdraw and leave neg amount in account < -50
    withdraw(guest, withdraw4);

    Money money = {103, 232};
    //test print
    print(money);
    print(guest);
    return 0;
}

//function the create a new account
Account createAccount(){
    //make a new account
    Account newAccount;
    double startBalance;
    cout << "Let’s set up your account.\n";
    cout << "First, what's the name of the account? ";
    cin >> newAccount.name;
    cout << "What is the interest rate of your "<<newAccount.name<<" account? ";
    cin >> newAccount.interest;
    cout<<"Finally, what is the starting balance of your "<<newAccount.name<<" account? $";
    //holder for dollars/cents
    cin >> startBalance;
    cout << "In your " << newAccount.name << ", you have $" << startBalance << ".\n\n";
    newAccount.money = doubleToStruct(startBalance);
    return newAccount;
}

//function to put in money
Account deposit(Account account, Money deposit){
    //if given deposit is negative value
    if(deposit.d < 0 && deposit.c < 0){
        cout << "Cannot make negative deposit.\n\n";
    }
    else {
        double depositAmount = structToDouble(deposit);
        double currentBalance = structToDouble(account.money);
        double newBalance = currentBalance+depositAmount;
        account.money = doubleToStruct(newBalance);
        cout << fixed << setprecision(2);
        cout << "$" << depositAmount << " deposited into " << account.name << endl;
        cout << "You now have $" << newBalance << " in your Savings account.\n\n";
    }
    return account;
}

//function to take out money
Money withdraw(Account &account, Money withdraw){
    //if given withdraw is a negative
    if(withdraw.d < 0 && withdraw.c < 0){
        cout << "Cannot make negative withdrawl.\n";
        cout << "$0.00 withdrawn from " << account.name << ".\n\n";
        //give back $0.00
        withdraw.d = 0;
        withdraw.c = 0;
    }
    else {
        double currentBalance = structToDouble(account.money);
        double withdrawAmount = structToDouble(withdraw);
        double newBalance = currentBalance - withdrawAmount;
        //check to see if balance is greater than -50
        if(newBalance > -50){
            account.money = doubleToStruct(newBalance);
            cout << fixed << setprecision(2);
            cout << "$" << withdrawAmount << " withdrawn from " << account.name << endl;
            cout << "Withdrew $" << withdrawAmount << " from " << account.name;
            //check to see if +/-
            if(newBalance > 0){
                cout << ". Now, you now have $" << newBalance << "\n\n";
            }
            else {
                cout << ". Now, you now have ($" << fabs(newBalance) << ")\n\n";
            }
        }
        //overwithdrawn more than -50
        else {
            double maxWithdrawAmount = currentBalance + 50;
            account.money = doubleToStruct(-50.00);
            currentBalance = structToDouble(account.money);
            cout << fixed << setprecision(2);
            cout << "$" << maxWithdrawAmount << " withdrawn from " << account.name << endl;
            cout << "It’s not very effective." << endl;
            cout << "You now have ($"<<fabs(currentBalance)<<") in your " << account.name << " account.\n\n";
        }
    }
    return withdraw;
}

//function that add accrue
void accrue(Account &account){
    double currentBalance = structToDouble(account.money);
    double acrrue = currentBalance*(account.interest/100.0);
    double newBalance = currentBalance+acrrue;
    account.money = doubleToStruct(newBalance);
    cout << fixed << setprecision(2);
    cout << "At " << account.interest << "%, your " << account.name;
    cout << " account earned $" << acrrue;
    cout << ". You now have $" << newBalance << " in your " << account.name << ".\n\n";
}

//function that print out money
void print(Account account){
    double currentBalance = structToDouble(account.money);
    //check if +/-
    cout << fixed << setprecision(2);
    if(currentBalance < 0){
        cout << "($" << fabs(currentBalance) << ")\n";
    }
    else {
        cout << "$" << currentBalance << endl;
    }
}

//function that print out money
void print(Money money){
    double currentBalance = structToDouble(money);
    //check if +/-
    cout << fixed << setprecision(2);
    if(currentBalance < 0){
        cout << "($" << fabs(currentBalance) << ")\n";
    }
    else {
        cout << "$" << currentBalance << endl;
    }
}

double structToDouble(Money money){
    return money.d + money.c/100.0;
}
Money doubleToStruct(double money){
    double fractpart, wholepart;
    fractpart = modf(money , &wholepart);
    Money moneyStruct;
    moneyStruct.d = wholepart;
    moneyStruct.c = round(fractpart*100);
    return moneyStruct;
}
