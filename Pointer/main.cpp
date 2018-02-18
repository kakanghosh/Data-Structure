#include <iostream>

using namespace std;

int main()
{
    int a,c;
    int arr[10];

    int *ptr,*ptrr;
    ptr = &a;
    ptrr = &c;

    ptrr = ptr;

    cout << ptr << endl;
    cout << ptrr << endl;

    cout << endl << endl;

    cout << "Address of variable 'a' = " << &a << endl;
    cout << "Address of variable 'b' = " << &c << endl;

    for( int i = 0; i < 10; i++ ){

        cout << "Address of arr[" << i << "] = " << &arr[i] << endl;
    }

    return 0;
}
