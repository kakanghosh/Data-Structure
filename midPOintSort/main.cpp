#include <iostream>

using namespace std;

void printArray(int a[], int arraySize){

     for ( int i = 0; i < arraySize; i++){

         cout << a[i] << " " ;
     }

     cout << endl;
}

int main()
{
    int starting, ending , midpoint, small , big, s , b, temp;
    int arr[7] = {7,6,5,4,3,2,1};
    starting = 0 , ending = 6;

    printArray(arr,7);

    while( starting <= ending ){

        small = arr[starting];
        s = starting;


        for( int i = starting+1; i <= ending; i++ ){
             if(  arr[i] < small ){
                 s = i;
             }
        }

         if( arr[starting] > arr[s] ){

                temp = arr[starting];
                arr[starting] = arr[s];
                arr[s] = temp;

                printArray(arr,7);
         }

        starting++;

         big = arr[starting];
         b = ending;

        for( int j = starting; j < ending; j++ ){

            if(  arr[j] > big ){
                b = j;
            }
        }

        if( arr[ending] < arr[b]){
              temp = arr[ending];
              arr[ending] = arr[b];
              arr[b] = temp;

              printArray(arr,7);
        }

        ending--;


    }


    printArray(arr,7);




    return 0;
}

