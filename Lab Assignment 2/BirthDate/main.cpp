#include <iostream>
#include <string.h>

using namespace std;

char* strlwr(char *a){
   int i = 0;

   while(a[i]!=NULL){
      if( a[i]>= 65 && a[i]<= 90 ){
        a[i] += 32;
      }
   }

   return a;
}



class Date{

     int date;
     char month[20];
     int year;

  public:
   Date(){

      date = 21;
      strcpy(month,"September");
      year = 1967;

      cout << "MyBirthDate: "  << date << " " << checkMonth(month) << " " << year << endl;

   }


   void inputBirthDate(){

       cout << "Enter your Birth Date: " << endl;
       cin >> date >> month >> year;
   }


   void printBirthDate(){

         cout << "My Birth Date is in: "  << date << " " << checkMonth(month) << " " << year << endl;
    }



  private:
    int checkMonth(char *a){

       if( strcmp( strlwr(a),"january") == 0 ) return 1;
       else if( strcmp( strlwr(a),"february") == 0 ) return 2;
       else if( strcmp( strlwr(a),"march") == 0 ) return 3;
       else if( strcmp( strlwr(a),"april") == 0 ) return 4;
       else if( strcmp( strlwr(a),"may") == 0 ) return 5;
       else if( strcmp( strlwr(a),"june") == 0 ) return 6;
       else if( strcmp( strlwr(a),"july") == 0 ) return 7;
       else if( strcmp( strlwr(a),"august") == 0 ) return 8;
       else if( strcmp( strlwr(a),"september") == 0 ) return 9;
       else if( strcmp( strlwr(a),"october") == 0 ) return 10;
       else if( strcmp( strlwr(a),"november") == 0 ) return 11;
       else if( strcmp( strlwr(a),"december") == 0 ) return 12;


    }


};

int main()
{
    Date MyBirthDate;
    MyBirthDate.inputBirthDate();
    MyBirthDate.printBirthDate();


    return 0;
}
