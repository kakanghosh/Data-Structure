#include <iostream>

using namespace std;

#define MAX 5

class _queue_{

    int arr[MAX];
    int frontItem;
    int rearItem;

public:
    _queue_(){
       rearItem = -1;
       frontItem = -1;
    }

    void enqueue(int item){

        if( rearItem == MAX-1 ){
            cout << "Queue full!!!" << endl;
        }else if( isEmpty()){
          frontItem = 0;
           arr[++rearItem] = item;
          cout << item << " PUSHED in the queue." << endl;
        }else{

           arr[++rearItem] = item;

           cout << item << " PUSHED in the queue." << endl;
         }
    }

    void dequeue(){

        if( isEmpty() ){
             cout << "Queue is Empty." << endl;
        }else if( isEmpty() == false && frontItem == rearItem ){

             cout << arr[frontItem] << " dequeued!!" << endl;
             frontItem = -1;
             rearItem = -1;
        }else{
        cout << arr[frontItem++] << " dequeued!!" << endl;
        }
    }

    void DISPLAY(){


    }
   private:
    bool isEmpty(){

        if( frontItem == -1 && rearItem == -1 ){
            return true;
        }else{
          return false;
        }
    }
};

int main()
{
   _queue_ qu;

    qu.dequeue();

   qu.enqueue(10);
   qu.enqueue(15);
   qu.enqueue(25);
   qu.enqueue(48);
   qu.enqueue(20);

   cout << endl;


   qu.dequeue();
   qu.dequeue();

   qu.enqueue(54);

    return 0;
}
