#include <iostream>

using namespace std;

int main()
{

    int A[9] = {1,3,5,7,8,2,4,6,9};
    int key, i , j ;

     for ( i = 0; i < 9; i++){

         cout << A[i] << " " ;
    }

    cout << endl;


    for( j = 5; j < 9; j++ ){


      key = A[j];

      i = j - 1 ;

      while( i >=0  && A[i] > key ){

         A[i+1] = A[i];
         i--;

      }

       A[i+1] = key;



    }

    for ( i = 0; i < 9; i++){

         cout << A[i] << " " ;
    }


    return 0;
}

