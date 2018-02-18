#include <iostream>
#include <stdlib.h>
#include <new>
using namespace std;

void setArray(int *a, int s){

    for( int i = 0; i < s; i++){
         a[i] = i+1;
    }
}

void getArray(int *a, int s){

    for( int i = 0; i < s; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Size of array: ";
    cin >> n;

    int *a = new (nothrow) int[n]; //(int*)calloc(n,sizeof(int));

    if( a== nullptr){
        return 0;
    }

    setArray(a,n);
    //  free(a);

    //a = (int*)realloc(a,sizeof(int)*n*2);

  //    setArray(a,n*2);

    getArray(a,n);
    free(a);

    return 0;
}
