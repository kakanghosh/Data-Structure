#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 5

struct node
{

     int data;
     node *link;
};

class queues
{

   int node_counter;
   node *start;
   node *linkedList;

   public:

      //constructor
       queues(){

           node_counter = 0;
           start = NULL;
       }

       // Enqueue method

      void Enqueue(int number){

         if( node_counter == MAX ){

             cout << "\nQueue is Full!" << endl;
         }else if( isEmpty() ){

             node *temp = newNode();
             temp->data = number;
             start = temp;
             node_counter++;

             cout << endl << number << " enqueued!" << endl;
         }else{

             node *temp = newNode();
             temp->data = number;
             temp->link = start;   // creating new node after start node
             start = temp;

             node_counter++;
             cout << endl << number << " enqueued!" << endl;
         }

      }


      // Dequeue method

      void Dequeue(){

         if( isEmpty()){

             cout << "\nQueue is Empty" << endl;
         }else{

            start = start->link;
            node_counter--;

            cout << "\nDequeued!" << endl;

         }


      }

      //Display all node data

     void Display(){

        linkedList = start;

       if( linkedList == NULL ){

          cout << "\nQueue is Empty!" << endl;
       }else{

           cout << endl << "Data: ";

           while( linkedList != NULL ){

            cout << linkedList->data << " ";
            linkedList = linkedList->link;
        }

        cout << endl;

       }

     }

    //checking queue is empty or not?

    bool isEmpty(){

       if( node_counter == 0) return true;
       return false;

    }


   private:

    //create new node address
    node* newNode(){

         node *temp = new node;
         temp->data = NULL;
         temp->link = NULL;
         return temp;
    }


};



int main()
{

    queues *qu = new queues;

    int choice;
    bool flag = true;
    int number;

    while( flag ){

        cout << "\n1. Enqueue." << endl;
        cout << "2. Dequeue."  << endl;
        cout << "3. Display." << endl;
        cout << "4. Exit." << endl;

        cout << endl << "\nEnter choice: ";
        cin >> choice;

        system("cls");

        switch( choice ){

        case 1:

             cout << "\nEnter number: ";
             cin >> number;
             qu->Enqueue(number);
            break;

        case 2:

            qu->Dequeue();

            break;

        case 3:

            qu->Display();

            break;

        case 4:
              flag = false;
            break;

        }

    }


    return 0;
}
