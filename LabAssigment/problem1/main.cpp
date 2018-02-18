#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int arr_1[10],arr_2[10], n = 0;

    cout<< "Input ten numbers: " <<endl;

    for( int i = 0; i < 10; i++){
        cin >> arr_1[i];
    }

    for( int j = 9 ; j >= 0 ; j--){
        arr_2[j] = arr_1[n]*3;
        n++;
    }


    cout << "\n\nInput: ";

    for( int i = 0; i < 10; i++){
      cout << arr_1[i] << " ";
    }

    cout << "\n\nOutput: ";

    for( int i = 0; i < 10; i++){
      cout << arr_2[i] << " ";
    }


    getch();
    return 0;
}
