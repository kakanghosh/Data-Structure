#include <iostream>

using namespace std;

#define max 5
void cInsert(int a[] , int &f , int &r , int item);
int cDelete( int a[] , int &f , int &r );

int cQueue[max];



int main()
{
    int item;
    int cRear = -1;
    int cFront = -1;
    int choice;

    while( 1 ){

        cin >> choice;

        switch(choice){

      case 1:

       cout << "Item: ";
       cin >> item;
        cInsert(cQueue,cFront,cRear,item);
        break;

      case 2:
        cDelete(cQueue,cFront,cRear);
        break;

        }







    }


    return 0;
}

void cInsert(int a[] , int &f , int &r , int item){



      if( (f == 0 && r == max - 1) || ( f == r + 1 ) ){

          cout << "Queue overflow!" << endl;
      }else{

          if( r == max - 1 ){

          r = -1;
      }

      if( f == -1 && r == -1  ){

          f = 0;

          a[++r] = item;

          cout << item << " inserted in the queue" << endl;

      }else{

         a[++r] = item;
         cout << item << " inserted in the queue" << endl;

      }

      }


}
int cDelete( int a[] , int &f , int &r ){


      if ( f == -1){
        cout << "Queue underflow!" << endl;
        return 0;
      }else if( f == r){

        cout << cQueue[f] << " Deleted!" << endl;

        f = r = -1;
      }else{
          cout << cQueue[f++] << " Deleted!" << endl;
      }

      if( f == max){
         f = 0;
      }



}
