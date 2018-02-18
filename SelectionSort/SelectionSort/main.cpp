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
    int temp , j, minimum, n;


    cout << "-----Selection Sort------\n\n";

    cout << "Input array  size: ";
    cin >> array_size;

    cout << "Enter " << array_size << " number: " ;

    for( int i = 0; i < array_size; i++ ){
        cin >> arr[i];
    }


    printArray(arr,array_size);

    for( int i = 0; i < array_size; i++  ){

        minimum = arr[i];
        n = i;

         for (  j = i ; j < array_size; j++ ){
            if( minimum > arr[j] ){
               minimum = arr[j];
               n = j;
            }
         }

        temp = arr[i];
        arr[i] = minimum;
        arr[n] = temp;

    }

    printArray(arr,array_size);

    return 0;
}
