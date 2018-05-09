//Author: Trong Van
//Student ID: x454v285
//Programming Number: 2
//filename: program2.cpp
//Description:  an account program the help keep track of money 
//              amd this time implement it using classes

// Add Or Subtract Libraries As Needed
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <math.h> 
#include <stdlib.h> 

// Place Money Class Definition Here
class Money {
    int dollars, cents;
    public:
        Money();
        Money(int gDollars, int gCents);
        Money(int gDollars);
        Money(double money);
        int getPennies() const;
        bool isNegative() const;
        void add(const Money &m);
        void subtract(const Money &m);
        bool isEqual(const Money &m) const;
        void print() const;
        void setDollars(int gDollars);
        void setCents(int gCents);
};
// Place Account Class Definition Here
class Account {
    double interest;
    std::string name;
    Money money;
    public: 
        Account();
        Account(std::string g_name, double g_interest, Money g_money);
        Account(std::string gName, double gInterest, int gDollars);
        Account(std::string gName, double gInterest, double amount);
        std::string getName() const;
        double getRate() const;
        const Money getBalance() const;
        void setName(std::string newName);
        void deposit(const Money &m);
        void deposit(int d, int c);
        void deposit(int d);
        void deposit(double d);
        const Money withdraw(const Money &m);
        const Money withdraw(int d, int c);
        const Money withdraw(int d);
        const Money withdraw(double d);
        void accrue();
        void print() const;
        void transferTo(Account &dest, const Money &amount);
        
};
// Define Non-Member Function Here
const Account createAccount();

// Test Functions; *** DO NOT ALTER ***
bool moneyGetPennies(int arg);
bool moneyIsNegative(bool expected);
bool moneyAdd();
bool moneySubtractPos();
bool moneySubtractNeg();
void moneyPrint(double arg);
bool acctGetName();
bool acctGetRate();
bool acctGetBalance();
bool acctSetName();
bool acctDep01();
bool acctDep02();
bool acctDep03();
bool acctDep04();
void acctBadDep();
bool acctWith01();
bool acctWith02();
bool acctWith03();
bool acctWith04();
bool acctWithPart01();
bool acctWithPart02();
void acctBadWith();
bool acctAccrue();
void acctPrint(double arg);
bool acctTransfer();

// Main Function; *** DO NOT ALTER ***
int main()
{
	char prev = std::cout.fill('.');

	std::cout << "*** TESTING MONEY CLASS FUNCTIONS ***\n";
	std::cout << std::setw(57) << std::left << "1. Testing Money class GetPennies:" << (moneyGetPennies(555)) << std::endl;
	std::cout << std::setw(57) << std::left << "2. Testing Money class GetPennies:" << (moneyGetPennies(-555)) << std::endl;
	std::cout << std::setw(57) << std::left << "3. Testing Money class IsNegative:" << (moneyIsNegative(true)) << std::endl;
	std::cout << std::setw(57) << std::left << "4. Testing Money class IsNegative:" << (moneyIsNegative(false)) << std::endl;
	std::cout << std::setw(57) << std::left << "5. Testing Money class Add:" << (moneyAdd()) << std::endl;
	std::cout << std::setw(57) << std::left << "6. Testing Money class Subtract:" <<  (moneySubtractPos()) << std::endl;
	std::cout << std::setw(57) << std::left << "7. Testing Money class Subtract:" <<  (moneySubtractNeg()) << std::endl;
	std::cout << std::setw(57) << std::left << "8. Testing Money class Print ( Must match $5.44 ):"; (moneyPrint(5.44)); std::cout << std::endl;
	std::cout << std::setw(57) << std::left << "9. Testing Money class Print ( Must match ($5.44) ):"; (moneyPrint(-5.44)); std::cout << std::endl;

	std::cout << "\n*** TESTING ACCOUNT CLASS FUNCTIONS ***\n";
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "1. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class GetName:" << (acctGetName()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "2. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class GetRate:" << (acctGetRate()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "3. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class GetBalance:" << (acctGetBalance()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "4. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class SetName:" << (acctSetName()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "5. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class Deposit #1:" << (acctDep01()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "6. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class Deposit #2:" << (acctDep02()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "7. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class Deposit #3:" << (acctDep03()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "8. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class Deposit #4:" << (acctDep04()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "9. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class Deposit (ERROR):"; acctBadDep();
	std::cout << std::setw(4) << std::left << "10. " << std::setw(53) << std::left << "Testing Account class Withdraw #1:" << (acctWith01()) << std::endl;
	std::cout << std::setw(4) << std::left << "11. " << std::setw(53) << std::left << "Testing Account class Withdraw #2:" << (acctWith02()) << std::endl;
	std::cout << std::setw(4) << std::left << "12. " << std::setw(53) << std::left << "Testing Account class Withdraw #3:" << (acctWith03()) << std::endl;
	std::cout << std::setw(4) << std::left << "13. " << std::setw(53) << std::left << "Testing Account class Withdraw #4:" << (acctWith04()) << std::endl;
	std::cout << std::setw(4) << std::left << "14. " << std::setw(53) << std::left << "Testing Account class Withdraw (OVERDRAW):" << (acctWithPart01()) << std::endl;
	std::cout << std::setw(4) << std::left << "15. " << std::setw(53) << std::left << "Testing Account class Withdraw (PARTIAL):" << (acctWithPart02()) << std::endl;
	std::cout << std::setw(4) << std::left << "16. " << std::setw(53) << std::left << "Testing Account class Withdraw (ERROR):"; acctBadWith();
	std::cout << std::setw(4) << std::left << "17. " << std::setw(53) << std::left << "Testing Account class Accrue: " << (acctAccrue()) << std::endl;
	std::cout << std::setw(4) << std::left << "18. " << std::setw(53) << std::left << "Testing Account class Transfer: " << (acctTransfer()) << std::endl;
	std::cout << std::setw(4) << std::left << "19. " << std::setw(53) << std::left << "Testing Account class Print ( Must match $50.00 ):"; (acctPrint(50.00)); std::cout << std::endl;
	std::cout << std::setw(4) << std::left << "20. " << std::setw(53) << std::left << "Testing Account class Print ( Must match ($50.00) ):"; (acctPrint(-50.00)); std::cout << std::endl;

	Account account = createAccount();
	std::cout << "\n\n*** TESTING NON-CLASS FUNCTION CREATEACCOUNT ***\n";
	std::cout << std::setw(19) << std::left << "1. Account Name:" << account.getName() << std::endl;
	std::cout << std::setw(19) << std::left << "2. Interest Rate:" << account.getRate() << std::endl; 
	std::cout << std::setw(19) << std::left << "3. Balance:"; (account.getBalance()).print(); std::cout << std::endl; 

	std::cout.fill(prev);

	return 0;
}


// Implement Money Class Functions Here
Money::Money(){
    dollars = 0;
    cents = 0;
}
Money::Money(int gDollars, int gCents){
    dollars = gDollars;
    cents = gCents;
}
Money::Money(int gDollars){
    dollars = gDollars;
    cents = 0;
}
Money::Money(double money){
    double fractpart, wholepart;
    fractpart = modf(money , &wholepart);
    dollars = wholepart;
    cents = round(fractpart*100);
}
int Money::getPennies() const{
    return (dollars*100)+cents;
}
bool Money::isNegative() const{
    //if one these negative than we have negative balance
    if(dollars < 0 || cents < 0){
        return true;
    }
    return false;
}
void Money::setDollars(int gDollars){
    dollars = gDollars;
}
void Money::setCents(int gCents){
    cents = gCents;
}
void Money::add(const Money &m){
    double balance = m.getPennies()+ getPennies();
    double newBalance = balance/100;
    //split whole and fraction out
    double fractpart, wholepart;
    fractpart = modf(newBalance, &wholepart);
    dollars = wholepart;
    cents = round(fractpart*100);
}   
void Money::subtract(const Money &m){
    double balance = getPennies() - m.getPennies();
    double newBalance = balance/100;
    //split whole and fraction out
    double fractpart, wholepart;
    fractpart = modf(newBalance, &wholepart);
    dollars = wholepart;
    cents = round(fractpart*100);
}
bool Money::isEqual(const Money &m) const{
    if(getPennies() == m.getPennies()){
        return true;
    }
    return false;
}
void Money::print() const {
    double balance = dollars + (cents/100.0);
    //check if +/-
    std::cout << std::fixed << std::setprecision(2);
    if(balance < 0){
        std::cout << "($" << std::fabs(balance) << ")\n";
    }
    else {
        std::cout << "$" << balance << "\n";
    }
}

// Implement Account Class Functions Here
/*----------Memeber functions------------*/
Account::Account(){
    name = "Savings";
    interest = 0;
}
Account::Account(std::string gName, double gInterest, Money gMoney){
    name = gName;
    interest = gInterest;
    money = gMoney;
}
Account::Account(std::string gName, double gInterest, int gDollars){
    name = gName;
    interest = gInterest;
    Money m(gDollars);
    money = m;
}
Account::Account(std::string gName, double gInterest, double amount){
    name = gName;
    interest = gInterest;
    Money m(amount);
    money = m;
}
std::string Account::getName() const{
    return name;
}
double Account::getRate() const{
    return interest;
}
const Money Account::getBalance() const{
    return money;
}
void Account::setName(std::string newName){
    name = newName;
}
void Account::deposit(const Money &m){
    if(!m.isNegative()){
        money.add(m);
    }
    else {
        std::cout << "Cannot deposit negative amount.\n";
    }
}
void Account::deposit(int d, int c){
    Money m(d,c);
    if(!m.isNegative()){
        money.add(m);  
    }
    else {
        std::cout << "Cannot deposit negative amount.\n";
    }    
}
void Account::deposit(int d){
    Money m(d);
    if(!m.isNegative()){
        money.add(m);
    }
    else {
        std::cout << "Cannot deposit negative amount.\n";
    }
}
void Account::deposit(double d){
    Money m(d);
    if(!m.isNegative()){
        money.add(m);
    }
    else {
        std::cout << "Cannot deposit negative amount.\n";
    }
}
const Money Account::withdraw(const Money &m){
    if(m.isNegative()){
        std::cout << "Cannot withdraw negative amount.\n";
        Money empty;
        return empty;
    }
    Money mm;
    mm = m;
    money.subtract(mm);
    //check if money < -50
    if(money.getPennies() < -5000){
        //see how much past -5000 is it 
        double diff = -5000 - money.getPennies();
        //add back to the account so it's at -5000
        Money diffM(diff/100);
        money.add(diffM);
        //subtract the withdraw amount by that to get the total withdraw amount
        mm.subtract(diffM);
    } 
    return mm;
}
const Money Account::withdraw(int d, int c){
    Money m(d,c);
    if(m.isNegative()){
        std::cout << "Cannot withdraw negative amount.\n";
        Money empty;
        return empty;
    }
    Money mm;
    mm = m;
    money.subtract(mm);
    if(money.getPennies() < -5000){
        double diff = -5000 - money.getPennies();
        Money diffM(diff/100);
        money.add(diffM);
        mm.subtract(diffM);
    } 
    return mm;
}
const Money Account::withdraw(int d){
    Money m(d);
    if(m.isNegative()){
        std::cout << "Cannot withdraw negative amount.\n";
        Money empty;
        return empty;
    }
    Money mm;
    mm = m;
    money.subtract(mm);
    if(money.getPennies() < -5000){
        double diff = -5000 - money.getPennies();
        Money diffM(diff/100);
        money.add(diffM);
        mm.subtract(diffM);
    } 
    return mm;
}
const Money Account::withdraw(double d){
    Money m(d);
    if(m.isNegative()){
        std::cout << "Cannot withdraw negative amount.\n";
        Money empty;
        return empty;
    }
    Money mm;
    mm = m;
    money.subtract(mm);
    if(money.getPennies() < -5000){
        double diff = -5000 - money.getPennies();
        Money diffM(diff/100);
        money.add(diffM);
        mm.subtract(diffM);
    } 
    return mm;
}
void Account::accrue(){
    double balance = money.getPennies()/100;
    double accrueAmount = balance*interest;
    Money m(accrueAmount);
    money.add(m);
}
void Account::print() const{
    double balance = money.getPennies()/100;
    //check if +/-
    std::cout << std::fixed << std::setprecision(2);
    if(balance < 0){
       std::cout << "($" << std::fabs(balance) << ")\n";
    }
    else {
        std::cout << "$" << balance << "\n";
    }
}
void Account::transferTo(Account &dest, const Money &amount){
    //if amount is negative
    if(!amount.isNegative()){
        money.subtract(amount);
        dest.deposit(amount);
    }
}

// Implement Non-Member Function Here
const Account createAccount(){
    std::string startBalance;
    double interest;
    std::string name;
    std::cout << "Let’s set up your account.\n";
    std::cout << "First, what's the name of the account? ";
    std::cin >> name;
    std::cout << "What is the interest rate of your "<< name <<" account? ";
    std::cin >> interest;
    std::cout<<"Finally, what is the starting balance of your " << name <<" account? ";
    //put start balance as a string and then filter out the '$' than turn into an double
    std::cin >> startBalance;
    //make a new account
    if(startBalance[0] == '$'){
        startBalance[0] = '0';
    }
    double balance = atof(startBalance.c_str());
    Account newAccount(name,interest,balance);
    return newAccount;
}


// Test Functions; *** DO NOT ALTER ***
bool moneyGetPennies(int arg)
{
	Money money(arg / 100, arg % 100);
	return money.getPennies() == arg;
}

bool moneyIsNegative(bool expected)
{
	if (expected == true) {
		Money money1(-5, 55);
		Money money2(5, -55);
		Money money3(-5);
		Money money4(-5.55);
		return ( ( money1.isNegative() && 
					money2.isNegative() && 
					money3.isNegative() && 
					money4.isNegative() ) == expected );
	} else {
		Money money1(5, 55);
		Money money2(5);
		Money money3(5.55);
		Money money4;
		return ( !( !(money1.isNegative()) && 
					!(money2.isNegative()) && 
					!(money3.isNegative()) &&
					!(money4.isNegative()) ) == expected );
	}
}

void moneyPrint(double arg)
{
	Money money(arg);
	money.print();
}

bool moneyAdd()
{
	Money left(4, 64), right(5, 36);
	left.add(right);
	
	return left.isEqual(10);
}

bool moneySubtractPos()
{
	Money money(20);
	money.subtract(10.11);
	return money.isEqual(9.89);
}

bool moneySubtractNeg()
{
	Money money(20);
	money.subtract(30.11);
	
	return money.isEqual(-10.11);
}

bool acctGetName()
{
	Account account;

	return (account.getName() == "Savings");
}

bool acctGetRate()
{
	Account account("Savings", 0.01, Money(5, 0));

	return (account.getRate() == 0.01);
}

void acctPrint(double arg)
{
	Account account("Savings", 0.015, arg);
	account.print();
}

bool acctGetBalance()
{
	Money money(50);
	Account account("Savings", 0.01, money);
	Money bal = account.getBalance();

	return (bal.isEqual(money));
}

bool acctSetName()
{
	std::string name = "ROTH IRA";
	Account account("Savings", 0.01, 5);

	account.setName(name);
	return (name == account.getName());
}

bool acctDep01()
{
	Money money(5.63);
	Account account;

	account.deposit(money);

	return ((account.getBalance()).isEqual(money));
}

bool acctDep02()
{
	Account account;

	account.deposit(5, 63);

	return ((account.getBalance()).isEqual(5.63));
}

bool acctDep03()
{
	Account account;

	account.deposit(20);

	return ((account.getBalance()).isEqual(20));
}

bool acctDep04()
{
	Account account;

	account.deposit(5.63);

	return ((account.getBalance()).isEqual(5.63));
}


void acctBadDep()
{
	Account account;
	account.deposit(-50);
}

bool acctWith01()
{
	Money money(25.44);
	Account account("Savings", 0.015, 50);

	Money w = account.withdraw(money);

	return (w.isEqual(money) && (account.getBalance()).isEqual(24.56));
}

bool acctWith02()
{
	Account account("Savings", 0.015, 50);

	Money w = account.withdraw(25, 44);

	return (w.isEqual(25.44) && (account.getBalance()).isEqual(24.56));
}

bool acctWith03()
{
	Account account("Savings", 0.015, 50);

	Money w = account.withdraw(24);

	return (w.isEqual(24) && (account.getBalance()).isEqual(26));
}

bool acctWith04()
{
	Account account("Savings", 0.015, 50);

	Money w = account.withdraw(25.44);

	return (w.isEqual(25.44) && (account.getBalance()).isEqual(24.56));
}

bool acctWithPart01()
{
	Account account("Checking", 0.015, 54.33);

	Money w = account.withdraw(60);

	return w.isEqual(60) && (account.getBalance()).isEqual(-5.67);
}

bool acctWithPart02()
{
	Account account("Checking", 0.015, 54.33);

	Money w = account.withdraw(300);

	return w.isEqual(104.33) && (account.getBalance()).isEqual(-50);
}

void acctBadWith()
{
	Account account;

	account.withdraw(-10);
}

bool acctAccrue()
{
	Account account("Roth", 0.07, 1000);
	
	account.accrue();

	return (account.getBalance()).isEqual(1070);
}

bool acctTransfer()
{
	Account savings;
	Account checking("Checking", 0.015, 2500);

	checking.transferTo(savings, 500);

	return (savings.getBalance()).isEqual(500) && (checking.getBalance()).isEqual(2000);
}

