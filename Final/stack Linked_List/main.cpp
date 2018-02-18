#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 5

struct node
{

     int data;
     node *link;
};

class stacks
{

   int nodeCounter;
   node *start;
   node *linkedList;

   public:
       // Constructor
       stacks(){
          nodeCounter = 0;
          start = NULL;
       }

       // PUSH method

       void push(int data)
       {

            if( nodeNumber(start) == MAX ){
                 cout << "\nStack OverFlow!!!" << endl;
            }else if( isEmpty() ){

                linkedList = newNode();
                linkedList->data = data;
                start = linkedList;
                nodeCounter++;

                cout <<endl<< data << " PUSHED in the stack!" << endl;

            }else{

               node *temp = newNode();
               temp->data = data;
               linkedList = start;

               while( linkedList != NULL ){

                   if( linkedList->link == NULL ){

                     linkedList->link = temp;
                     break;
                   }

                   linkedList = linkedList->link;
               }

               nodeCounter++;
               cout << endl << data << " PUSHED in the stack!" << endl;

            }

       }

       // pop method

       void pop(){

            if( nodeCounter == 0 ){

                 cout << "\nStack UnderFlow!" << endl;
            }else if(nodeCounter == 1){

                 cout << "\nPOPED from the stack!" << endl;
                 start = NULL;
                 nodeCounter--;
            }else {

               node *temp ;
               linkedList = start;

               while( linkedList != NULL  ){

                   if( linkedList->link->link == NULL ) break;
                   linkedList = linkedList->link;
               }

               linkedList->link = NULL;
               cout << "\nPOPED from the stack!" << endl;
               nodeCounter--;

            }

       }

       //Display node data

       void display(){

            linkedList = start;

            if( linkedList == NULL ){
                cout << "\nStack is Empty!" << endl;
            }else{

                 cout << endl << "Data: ";
                  while( linkedList != NULL ){

                 cout << linkedList->data << " ";
                 linkedList = linkedList->link;
                }

                cout << endl;
            }
       }

       // counting node number

    int nodeNumber(node *start){

        int counter = 0;

         while( start != NULL ){
             counter++;
             start = start->link;
         }
        return counter;
    }

    // checking if the stack is empty??

    bool isEmpty(){

       if( nodeCounter == 0 )
        return true;
       else
       return false;
    }

   private:

       // return new node address

    node* newNode(){

         node *temp = new node;
         temp->data = NULL;
         temp->link = NULL;
         return temp;
    }


};



int main()
{
    stacks *st = new stacks;

    int choice;
    bool flag = true;
    int number;

    while( flag ){

        cout << "\n1. PUSH." << endl;
        cout << "2. POP."  << endl;
        cout << "3. Display." << endl;
        cout << "4. Exit." << endl;

        cout << endl << "\nEnter choice: ";
        cin >> choice;

        system("cls");

        switch( choice ){

        case 1:

             cout << "\nEnter number: ";
             cin >> number;
             st->push(number);

            break;

        case 2:

              st->pop();

            break;

        case 3:

            st->display();

            break;

        case 4:
              flag = false;
            break;

        }

    }


    return 0;
}
