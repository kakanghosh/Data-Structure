#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;

char* strlwr(char *a);

class Student{

    int st_id;
    char st_name[20];
    int st_mark;

    public:

    void inputInfo(){

      cout << "Enter student ID: " ;
      cin >> st_id;
      cout << "Enter student name: ";
      cin >> st_name;
      cout << "Enter student mark: ";
      cin >> st_mark;

      cout << endl;
    }

    void printInfo(){

       cout << "\nStudent ID: " << st_id << endl;
       cout << "Student Name: " << st_name << endl;
       cout << "Student Mark: " << st_mark << endl << endl;
    }

    int getID(){
      return st_id;
    }

    char* getName(){
       return st_name;
    }

    int getMark(){
        return st_mark;
    }


};

int main()
{
   int n = 3, choice, max_num, min_num, max_num_id , min_num_id;
   bool flag = true , found;
   char name[20];


   Student student[n];

   for(int i = 0; i < n ; i++){
     student[i].inputInfo();
   }


   while(flag){

        found = false;

       cout << "\n\n========----======Get Student Information=======----======" << endl;
       cout << "\nPress 1 to show all the student information." << endl;
       cout << "Press 2 to find out student name who get maximum and minimum mark." << endl;
       cout << "Press 3	to Search a record based on student name." << endl;
       cout << "Press 0 to exit." << endl;

       cout << "\nEnter your choice: ";
       cin >> choice;

       switch(choice){

       //-------------------------------------------------
      // Case One one printing the all student information
      //-------------------------------------------------

      case 1:

          for(int i = 0; i < n ; i++){

             student[i].printInfo();
          }

        break;

        //-------------------------------------------------
       //Case two for maximum and minimum mark holder student name
       //-------------------------------------------------

      case 2:

          max_num = min_num = student[0].getMark();
          max_num_id = min_num_id = student[0].getID();

          for( int i = 1; i < n; i++){

             if( student[i].getMark() > max_num){
                 max_num = student[i].getMark();
                 max_num_id = student[i].getID();

             }else if( student[i].getMark() < min_num){

                 min_num = student[i].getMark();
                 min_num_id = student[i].getID();
             }
          }

          //-------------------------------------------------
          //printing the student name who gets highest mark
          //-------------------------------------------------



          for( int i = 0; i < n; i++ ){

              if( student[i].getID() == max_num_id ){

                  cout << "\nStudent name of highest mark holder: " << student[i].getName() << endl;
                  break;
              }
          }

          //-------------------------------------------------
          // printing the student name who gets lowest mark
          //-------------------------------------------------

           for( int i = 0; i < n; i++ ){

              if( student[i].getID() == min_num_id ){

                  cout << "\nStudent name of lowest mark holder: " << student[i].getName() << endl;
                  break;
              }
          }



        break;

        //-------------------------------------------------
        //Case three for searching for a particular student
        //-------------------------------------------------

      case 3:


        cout << "\nSearch for a student by name: ";
        cin >> name;

        for ( int i = 0; i < n ; i++){

             if( strcmp( strlwr(name) , strlwr(student[i].getName()) ) == 0 ){
                 student[i].printInfo();
                 found = true;
             }
        }

        if( found ==  false ){

             cout  << "\nAs named " << name << " no student have been found. " << endl;
        }



        break;

        //-------------------------------------------------
        //breaking the loop
        //-------------------------------------------------


       case 0:
           cout << "\nThanks for using." << endl;
           flag = false;
        break;


        //-------------------------------------------------
        //Default Case
        //-------------------------------------------------

       default:
          cout << "\nIncorrect Input! Please Enter correctly." << endl;
        break;


       }

   }




    return 0;
}

char* strlwr(char *a){

    int i = 0;

    while(a[i]!= NULL){

         if( a[i] >= 65 && a[i] <= 90 ){
             a[i]+= 32;
         }
         i++;
    }

    return a;
}
