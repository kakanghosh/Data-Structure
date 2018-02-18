#include <iostream>

using namespace std;

void printArray(int a[], int n){

     for( int i = 0; i < n; i++){
        cout << a[i] << " " ;
     }

     cout << endl;
}

int main()
{
    int array_size; //= 6;
    int arr[100]; // = {5,7,13,2,9,8};
    int temp;

    cout << "-----Bubble Sort------\n\n";

    cout << "Input array  size: ";
    cin >> array_size;

    cout << "Enter " << array_size << " number: " ;

    for( int i = 0; i < array_size; i++ ){
        cin >> arr[i];
    }



    printArray(arr,array_size);

    for( int i = array_size-1; i > 0; i-- ){

       for ( int j = 0; j < i; j++){

            if( arr[j] > arr[j+1] ){

              temp = arr[j+1];
              arr[j+1] = arr[j];
              arr[j] = temp;
            }
       }
    }


     printArray(arr,array_size);



    return 0;
}


