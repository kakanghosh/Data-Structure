#include <iostream>

using namespace std;

void Insert(int qu[], int &f, int &r , int item);
void Delete( int qu[], int &f, int &r , int item );

void showItem(int qu[] , int f , int r);

#define queue_max 5
int Queue[queue_max];


int main()
{

   int fr = -1,rr = -1,item;
   bool flag = true;
   int choice;


   while( flag ){

     cout << "1 for insert item" << endl;
     cout << "2 for delete item" << endl;
     cout << "3 for show items" << endl;
     cout << "4 for exit" << endl;

     cout<< "Enter your choice: ";
     cin >> choice;

     switch( choice ){

      case 1:
           cout << "Insert item in the queue: ";
           cin >> item;
           Insert(Queue,fr,rr,item);
        break;

      case 2:

          Delete(Queue,fr,rr,item);

        break;

      case 3:

          showItem(Queue,fr,rr);

        break;

      case 4:

        flag = false;
        break;


     }

   }



    return 0;
}

void Insert(int qu[], int &f, int &r , int item){

     if( r == queue_max - 1 ){
         cout << "Queue full!!!" << endl;
     }else{

         if( r == -1 ){
            f = 0;
         }

         Queue[++r] = item;

         cout << item << " inserted in the queue!!!" << endl;
     }


}


void Delete( int qu[], int &f, int &r , int item ){

       if( f == queue_max || r == -1  ){
          cout << "Underflow" << endl;
       }else{

           item = Queue[f++];

           cout << item << " deleted from the queue!" << endl;
       }
}


void showItem(int qu[] , int f , int r){


    if( !(f == queue_max  || r == -1)  ){
    for( int i = r; i >= f; i--){

         cout <<  Queue[i] << endl;
    }
    }else{

       cout << "Queue empty!!!" << endl;
    }
}
