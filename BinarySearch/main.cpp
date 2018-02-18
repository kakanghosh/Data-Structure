#include <iostream>
#include <string.h>

using namespace std;



int main()
{
    int arr[100] = {10,15,22,25,30,40,55} , n = 5;


    int beg = 0,ending = 6 ,mid = (beg+ending)/2 , item = 40;

    while( (beg <= ending) && (arr[mid] != item) ){

         if( item < arr[mid]){

            ending = mid - 1;
         }else{
            beg = mid+1;
         }

         mid = (beg + ending)/2;
    }

    if( arr[mid] == item ) {
        cout << item << " Position in the array is " << mid+1 << endl;
    }else{
        cout << "No data found" << endl;
    }



    return 0;
}



