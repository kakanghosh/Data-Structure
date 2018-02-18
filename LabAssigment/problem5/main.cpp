#include <iostream>
#include <conio.h>


void firstchange( int (*a)[3],int row);
void secondchange( int (*a)[3],int row);

using namespace std;

int main()
{
    int first_array[3][3], second_array[3][3];

    cout << "Enter first array elements: " ;

    for( int i = 0; i < 3; i++){
         for( int j = 0; j < 3; j++){

              cin >> first_array[i][j];
         }
    }


    cout << "Enter second array elements: " ;

    for( int i = 0; i < 3; i++){
         for( int j = 0; j < 3; j++){

              cin >> second_array[i][j];
         }
    }

    cout << "\n\n"  << endl;


    cout << "First array elements: \n\n" << endl;

    for ( int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){

             cout << first_array[i][j] << " " ;
        }
    }

     firstchange(first_array,3);

     cout << "\n\nAfter passing first array in the first_change function " << endl;

     for ( int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){

             cout << first_array[i][j] << " " ;
        }
    }



    cout << "\n\nSecond array elements: \n\n" << endl;

    for ( int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){

             cout << second_array[i][j] << " " ;
        }
    }

     secondchange(second_array,3);

     cout << "\n\nAfter passing first array in the second_change function " << endl;

     for ( int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){

             cout << second_array[i][j] << " " ;
        }
    }


    getch();
    return 0;
}

void firstchange( int (*a)[3],int row){

    for( int i = 0; i < row; i++){
        for( int j = 0; j < 3; j++){

           a[i][j] *= 7;
        }
    }

}

void secondchange( int (*a)[3],int row){

    for( int i = 0; i < row; i++){
        for( int j = 0; j < 3; j++){

           a[i][j] += 5;
        }
    }

}
