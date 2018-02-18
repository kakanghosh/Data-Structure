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
    int temp , j;

        cout << "-----Insertion Sort------\n\n";

    cout << "Input array  size: ";
    cin >> array_size;

    cout << "Enter " << array_size << " number: " ;

    for( int i = 0; i < array_size; i++ ){
        cin >> arr[i];
    }




    printArray(arr,array_size);

    for( int i = 1; i < array_size; i++  ){

        j = i;

       while( j > 0 && ( arr[j] < arr[j-1] ) ){

            temp = arr[j - 1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
       }

    }

    printArray(arr,array_size);

    return 0;
}
