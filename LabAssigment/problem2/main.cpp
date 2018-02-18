#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int arr[100], num, mid;


    cout << "Choice even numbers of element" <<endl;
    cin >> num;

    if( num % 2 == 0){
    cout << "Input numbers: " << endl;
    for( int i = 0; i < num; i++){
        cin >> arr[i];
    }

    cout << "\n\nInsert value in the middle: " << endl;
    cin >> mid;

    cout << "\n\nArray values: ";
    for( int i = 0; i < num; i++){
        cout << arr[i] << " ";
    }

    for( int i = num; i >= num / 2; i--){
       arr[i] = arr[i-1];
    }

    arr[num/2] = mid;

    cout << "\n\nAfter inserting "<< mid << " in the middle: ";
    for( int i = 0; i <= num; i++){
        cout << arr[i] << " ";
    }


    cout << endl;



    }else{
      cout << "Invalid inputs" << endl;
    }

    getch();
    return 0;
}
