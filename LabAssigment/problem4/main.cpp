#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int n, low, hi;

    cout << "Enter array size? " << endl;
    cin >> n;

    int arr[n];

    for ( int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    low = hi = arr[0];

     for ( int i = 1; i < n; i++){

          if( arr[i] > hi ){
             hi = arr[i];
          }

          if( arr[i] < low){
             low  = arr[i];
          }

     }

     cout << "Highest number in the array " << hi << endl;
     cout << "Lowest number in the array " << low << endl;

    getch();
    return 0;
}
