#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {1,2,3,4,5,6};
    int n = 5, lock = 0, item;

    for( int i = 0; i <= n; i++){
        cout << arr[i] << " ";
    }

    cout << "\nSearch number in the array: " ;
    cin >> item;

    arr[n+1] = item;

    while(arr[lock] != item ){
          lock++;
    }

    if( lock == (n+1) ){
        lock = 0;
        cout << lock;
    }else{
      cout << "Position: " << lock+1;
    }





    return 0;
}
