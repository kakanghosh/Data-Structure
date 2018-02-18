#include <iostream>

using namespace std;

#define MAX 3

struct node{

   int data;
   node* next;

};

class circular
{

     node *start, *circular_queue;
     node *rear_node, *front_node;
     int rear, fr ;

 public:

     // Constructor
    circular(){
      rear = fr = 0;
      start = NULL;
      front_node = rear_node = NULL;


    }

    //Enqueue method

    void Enqueue(int number)
    {

        if( (fr == 1 && rear == MAX ) || ( fr == rear+1 ) ){

            cout << "\nCircular Queue is FULL!!!" << endl;
        }else{

             if( isEmpty() ){

              circular_queue = newNode();

              // front and rear node

              rear_node = circular_queue;
              front_node = circular_queue;
              //

              circular_queue->data = number;
              start = circular_queue;

//              cout << "value of start: " << front_node << endl;
//              cout << "start->next: " << front_node->next << endl;

            //  circular_queue = circular_queue->next;
              cout << number << " is Enqueued!!!" << endl;

              rear = 1;
              fr = 1;
        }else if( rear == MAX ){

            rear = 1;
            circular_queue = start; // starting from the first node
            rear_node = start;      // initialize rear node from the begging
            circular_queue->data = number;

             cout << "value of start: " << start << endl;
              cout << "start->next: " << start->next << endl;

            cout << number << " is Enqueued!!!" << endl;

            circular_queue = circular_queue->next;

        }else{

            circular_queue = circular_queue->next = newNode();
            rear_node = circular_queue;
            circular_queue->data = number;

//             cout << "value of start: " << front_node << endl;
//              cout << "start->next: " << front_node->next << endl;

            cout << number << " is Enqueued!!!" << endl;
            // circular_queue = circular_queue->next;
            rear++;

        }

        }


    }

    //Dequeue method

    void Dequeued()
    {

        int number;

        if( isEmpty()){

            cout << "\nCircular queue is Empty!!!" << endl;
        }else{

           number = front_node->data;

         //  cout << fr << " " << rear << endl;

           if( fr == MAX && fr != rear ){
              fr = 1;
              front_node = start;
              cout << number << " Dequeued!!!" << endl;
           }else if( fr == rear ){
              rear = fr = 0;
            cout << number << " Dequeued!!!" << endl;
              rear_node = front_node = NULL;
           }else{


                cout << number << " Dequeued!!!" << endl;
               //  front_node = newAddress(front_node,start);
                  front_node = front_node->next;
                 fr++;


           }


        }

    }


    // isEmpty method

    bool isEmpty()
    {

        if( rear == 0 && fr == 0){
            return true;
        }
        return false;
    }

   //Return new node address

   node* newNode()
   {

       node* temp = new node;
       temp->data = NULL;
       temp->next = NULL;

       return temp;
   }

   node* newAddress( node *a , node *b )
   {

          while( a != b ){
             b = b->next;
          }

          a = b->next;
          return a;
   }

    void display(  ){

            node *starting, *ending;

            starting = front_node;
            ending = rear_node;

           if( starting != NULL ){

                while( starting != ending ){

                 cout << starting->data << " ";
                 starting = starting->next;
            }

            cout << starting->data ;
           }else{

              cout << "Circular queue is Empty!" << endl;
           }

   }


};

int getData(){
     int n;
    cout << "Enter data: ";
    cin >> n;

    return n;
}

int main()
{

    circular que;
    int number;
    int choice;
    bool flag = true;


    while( flag ){

        cout << "\n\n1.Enqueue." << endl;
        cout << "2.Dequeue." << endl;
        cout << "3.Display." << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch( choice){

       case 1:
           que.Enqueue(getData());
           break;

       case 2:
         que.Dequeued();
         break;

       case 3:
        que.display();
        break;



        }


    }

    return 0;
}
