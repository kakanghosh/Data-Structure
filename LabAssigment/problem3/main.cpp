#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int arr[100], num;


    cout << "Choice odd numbers of element" <<endl;
    cin >> num;

    if( num % 2 != 0){
    cout << "Input numbers: " << endl;
    for( int i = 0; i < num; i++){
        cin >> arr[i];
    }

    cout << "\n\nArray values: ";
    for( int i = 0; i < num; i++){
        cout << arr[i] << " ";
    }

    cout << "\n\nAfter deleting "<< arr[num/2] << " from the middle: ";

    for( int i = num/2; i < num ; i++){
       arr[i] = arr[i+1];
    }

    for( int i = 0; i < num - 1; i++){
        cout << arr[i] << " ";
    }


    cout << endl;



    }else{
      cout << "Invalid inputs" << endl;
    }

    getch();
    return 0;
}
