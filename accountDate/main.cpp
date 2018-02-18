#include <iostream>

using namespace std;


class Date{

    string month;
    int day;
    int year;

public:
    Date();
    Date(string m, int d, int y){

        month = m;
        day = d;
        year = y;
     }

    Date( Date& date ){

       month = date.getMonth();
       day = date.getDay();
       year = date.getYear();
    }

    void setDate(){
       cin >> month >> day >> year;
    }

    string getMonth(){
      return month;
    }

    int getDay(){
       return day;
     }

     int getYear(){
       return year;
     }

    ~Date(){
    }
};


class Account{

  int account_id;
  string account_name;
  float balace;
  Date creationDate;
  Date DOB;

  public:
      Account();

      Account( int id, string name , float balance , Date creat , Date dob ){

         account_id = id;
         account_name = name;
         balace = balace;
         creationDate = creat;
         DOB = dob;

      }

    void setAccountInfo(){

       cout << "Enter Account ID: ";
       cin >> account_id;
       cout << "Enter Account Name: ";
       cin >> account_name;
       cout << "Enter Account Balance: ";
       cin >> balace;

       cout << "Enter Creation Month Date Year: ";
       creationDate.setDate();

       cout << "Enter Date of Birth: ";
       DOB.setDate();


    }

    void getAccountInfo(){

        cout << "Account ID: " << account_id << endl;
        cout << "Account Name: "<< account_name << endl;
        cout << "Account Balance: "<< balace << endl;
        cout << "Creation Date  "  << creationDate.getDay() << " - " << creationDate.getMonth() << " - " << creationDate.getYear() << endl ;
        cout << "Date of Birth: " << DOB.getDay() << " - " << DOB.getMonth() << " - " << DOB.getYear() << endl;
    }

     ~Account(){
         cout << "Destructor of account class" << endl;
     }
 };


class hello{

public:

    hello();

    hello(int a){

    }

  ~hello(){
    cout << "Hello world" << endl;
  }
};


int main()
{

   hello h();




    return 0;
}
