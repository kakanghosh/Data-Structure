#include <iostream>
#include <stdlib.h>


using namespace std;

struct node{

    int data;
    node *prev;
    node *next;

};

node *newNode( );
void createNewNode( node **start , int num);
void display( node *start );
void deleteNode(node **start, int number);
void searching( node *start , int number );
int nodeCounting(node *start);

int main()
{

    node *start = NULL;

    node *doublyLinkedList = newNode();


    int choice , number;
    bool flag = true;

    while(flag){

        cout << "\n1. Insert node." << endl;
        cout << "2. Delete node." << endl;
        cout << "3. Display." << endl;
        cout << "4. Searching data. " << endl;
        cout << "5. Exit." << endl;

        cout << "\nEnter choice: ";
        cin >> choice;
        system("cls");

        switch(choice){

            case 1:

                cout << "\nEnter node data: ";
                cin >> number;

                createNewNode(&start,number);
                display(start);

                break;

            case 2:
                display(start);
                cout << "Enter data to delete: ";
                cin >> number;
                deleteNode(&start,number);
                display(start);
                break;

            case 3:
                display(start);
                break;

            case 4:
                display(start);
                cout << "\nSearch for data: ";
                cin >> number;

                searching(start , number );
                break;

            case 5:
                flag = false;
                break;

        }

    }




    return 0;
}

// creating new node address
node *newNode(){

    node *a = new node;
    a->data = NULL;
    a->prev = NULL;
    a->next = NULL;

    return a;
}


//  create new node

void createNewNode( node **start , int num){

      node *ex = *start;

      node *temp = newNode();
      temp->data = num;

     if( *start == NULL ){
         *start = temp;
     }else{

         while( ex != NULL ){

              if( ex->next == NULL ){
                  ex->next = temp;
                  ex->next->prev = ex;
                  break;
              }

              ex = ex->next;
         }

     }


}

// delete node

void deleteNode(node **start, int number)
{

    node *example = *start;

    if( *start == NULL ){

         cout << "\nList is Empty!!" << endl;
    }else{

       while( example != NULL ){

           if( (*start)->data == number ){

                // found number on first node
                //making the next node assigning in start node

                *start = (*start)->next;
              //  (*start)->next->prev = NULL;
                example = (*start);
                continue;
           }else if( ( example->data == number ) && ( (*start)->data != number ) && (example->next != NULL) ){  // other node cases

                 example->prev->next = example->next;  // setting previous nodes next node address with deleting nodes next address
                 example->next->prev = example->prev;  //addressing next node previous node address with previous one

                 example = example->next;

                 continue;
           }else if( example->data == number && example->next == NULL ){

               example->prev->next = NULL;
               break;
           }

            example = example->next;
       }

    }


}

//Searching node

void searching( node *start , int number ){

      int nodeNumber  = 0 , total = nodeCounting(start);


      if( start == NULL ){

         cout << "\nList is Empty!!!" << endl;
      }else{

         while( start != NULL ){

              if( start->data == number ){
                 cout << "Position is: " << nodeNumber + 1 << endl;
                 break;
              }
              start = start->next;
              nodeNumber++;
         }

         if( total == nodeNumber ){

             cout << "\nData not found!" << endl;
         }
      }
}



// Display all node data

void display( node *start ){

    if( start == NULL ){

         cout << "\nList is Empty!" << endl;
    }else{

       while( start != NULL ){

          cout << start->data << " ";
          start = start->next;
       }
       cout << endl;
    }
}


// counting nodes

int nodeCounting(node *start){

    int counter = 0;

    if( start == NULL ){
            return counter;
    }else{

       while( start != NULL ){
          start = start->next;
          counter++;
       }
       return counter;
    }

}
