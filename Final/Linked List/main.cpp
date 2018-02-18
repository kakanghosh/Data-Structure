#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{

    int data;
    node *link;
};

node* getNewNode(void);
void getUserData( node *linkedList , node **start );
void printAllInfo(node *linkedList);
void nodeAtTheBeg(node **start , int num);
void nodeAthThelast(node *linkedList, node **start , int num);
int nodeNumber(node *start);
void deleteNode( node **start , int num);
void searchingNode(node *start , int number);
void nodeAtMiddle(node **start , node *linkedList , int num);
void createNodeAfter( node *linkedList, int num);
void createNodeBefore(node **start , node *linkedList , int num);
void reverseLinkedList( node **start );


int main()
{


    bool flag = true;
    int cases;
    int node_number = 0;
    int number;


    node *start = NULL;
    node *linkedList = getNewNode();
    start = linkedList;

    getUserData(linkedList,&start);


    while(flag){


         cout << "\n\n1. Show all node data." << endl;
         cout << "2. Create node at the begging." << endl;
         cout << "3. Create node at the last." << endl;
         cout << "4. Create node at middle." << endl;
         cout << "5. Create a node after." << endl;
         cout << "6. Create a node before." << endl;

         cout << "7. Delete Node." << endl;
         cout << "8. Search node." << endl;
         cout << "9. Node Number." << endl;
         cout << "10. Reverse linked List." << endl;
         cout << "11.Exit" << endl;




         cout << "\nEnter choice: ";
         cin >> cases;

         system("cls");


         switch(cases){

         // print all the node data

        case 1:

            printAllInfo(start);
            break;

        // Add node at first

        case 2:

            cout << "\nEnter data: ";
            cin >> number;
            nodeAtTheBeg(&start,number);
            printAllInfo(start);
            break;

         // Add node at last

        case 3:

            cout << "\nEnter data: ";
            cin >> number;
            nodeAthThelast(start,&start, number);
            printAllInfo(start);
            break;

           // Add node in the middle

        case 4:
            printAllInfo(start);
            cout << "\nEnter data: ";
            cin >> number;

            nodeAtMiddle(&start,start,number);
            printAllInfo(start);

            break;

          // create a node after

          case 5:

             printAllInfo(start);
             cout << endl;

             cout << "Enter data: ";
            cin >> number;

            createNodeAfter(start,number);
            printAllInfo(start);

            break;

         // create a node before

          case 6:
                printAllInfo(start);
             cout << endl;

             cout << "Enter data: ";
            cin >> number;

            createNodeBefore(&start,start,number);
            printAllInfo(start);

            break;



         // Delete node

        case 7:
            printAllInfo(start);

            cout << "\nEnter data: ";
            cin >> number;

            deleteNode(&start,number);
            printAllInfo(start);
            break;

          // Searching node

        case 8:
            printAllInfo(start);
            cout << "\nEnter data: ";
            cin >> number;

            searchingNode(start,number);
            break;

       // Counting node number

         case 9:
            printAllInfo(start);
            cout << "\nNode Number: "<< nodeNumber(start) << endl;
            break;

         // Reverse linked list
         case 10:

             printAllInfo(start);
             reverseLinkedList(&start);
             printAllInfo(start);

             break;


         //Exit case
        case 11:
            flag = false;
            break;

         }


      }

    return 0;
}

// //////////////////////////////////// //////////////////////////////////
//              Functions          //// //////////////////////////////////
// //////////////////////////////////// //////////////////////////////////

// create a node after

void createNodeAfter( node *linkedList, int num){

       if( linkedList == NULL ){

           cout << "List is Empty!" << endl;
       }else{

           node *temp = getNewNode();

           cout << "Enter new node data: ";
           cin >> temp->data;

     int counter = 0;

     while( linkedList != NULL ){

         if( linkedList->data == num ){

             temp->link = linkedList->link;
             linkedList->link = temp;
             break;

         }
         linkedList = linkedList->link;
     }

       }
}

// Create a node before

void createNodeBefore(node **start , node *linkedList , int num){

      if( nodeNumber(linkedList) == 0 ){

          cout << "List is Empty!" << endl;
      }else{

         int counter = 0;

         node *temp = getNewNode();
         node *a = linkedList;

         cout << "Enter new node data: ";
         cin >> temp->data;

         while( linkedList != NULL ){

             if( linkedList->data == num ){

                  if( counter == 0 ){        // if node is found in first position

                      nodeAtTheBeg(&(*start),temp->data);
                      break;
                  }

                  temp->link = a->link;
                  a->link = temp;         // if node found in other cases
                  break;


             }

             linkedList = linkedList->link;


             if( counter == 1 ){
                a = a->link;         // keeping this node just one node behind
             }

             counter = 1;

         }

      }



}

// return new node address

node* getNewNode(void){
    node *temp = new node;
    temp->data = NULL;
    temp->link = NULL;

    return temp;
}


// user Define user Data

void getUserData( node *linkedList , node **start ){

     int c = 0;
     char a;

     while(1){

        cout << "Create node? Y/N ";
        cin >> a;



        if( a == 'Y' || a == 'y'){

            if( c == 1){

                 linkedList = linkedList->link = getNewNode();
            }

              cout << "Enter data: ";
             cin >> linkedList->data;

             c = 1;
        }else if( a == 'N' || a == 'n' ){

           if( c == 0){

             *start = NULL;
           }

           break;
        }

         system("cls");
     }

     system("cls");

}

// ------- show all the value ----

void printAllInfo(node *linkedList){

    if( linkedList == NULL ){
        cout << "List is Empty!" << endl;
    }else{

        while( linkedList!= NULL ){

          cout << linkedList->data ;


          linkedList = linkedList->link;

          if( linkedList != NULL){
           cout  << " -> ";
          }
    }

    cout << endl;

    //cout << "NULL"<<endl;

    }
}

// -- create node at the begging/////

void nodeAtTheBeg(node **start, int num){

     node *temp = getNewNode();
     //cout << "Enter data: ";
      temp->data = num;

     temp->link = *start;        // switching the start node value
     *start = temp;

}


//  --- create node at the middle

void nodeAtMiddle(node **start , node *linkedList , int num){

       node *temp = getNewNode();
       temp->data = num;

       int counter = 0;

     if(linkedList == NULL ){

        cout << "List is empty." << endl;

     }else if( nodeNumber(linkedList) == 1){

          nodeAtTheBeg( &(*start) , num);

     }else{

         int mid = nodeNumber(linkedList) / 2;

         while( counter < mid ){

              if( counter > 0){
                linkedList = linkedList->link;
              }

              counter++;

         }

         temp->link = linkedList->link;
         linkedList->link = temp;




     }
}


// -- create node at the last ///

void nodeAthThelast(node *linkedList, node **start , int num){

   if(linkedList == NULL){

//     node *temp = getNewNode();
//     cout << "Enter data: ";
//     cin >> temp->data;
//
//     temp->link = *start;
//     *start = temp;

      nodeAtTheBeg(&(*start) , num );
   }


   else{
    node *t;
    node *temp = getNewNode();
    temp->data = num ;

    while( linkedList != NULL ){
       t = linkedList;             // getting the last node address
       linkedList = (linkedList)->link;
    }

     t->link = temp;    // copy node in the NULL link address
   }
}

// Counting node number

int nodeNumber(node *start){
    int counter = 0;

    while( start!= NULL ){
        counter++;
        start = start->link;
    }
    return counter;
}

// Deleting node from the link list

void deleteNode( node **start , int num)
{

      node *a = *start;
      node *b = a;
      int c = 0;

     while( a != NULL ){

          //If first node contains the value
          if( (*start)->data == num ){

              *start = (*start)->link;

           }

           //Other case and the last node

           else if( a->data == num && a->link != NULL ){

              b->link = a->link;

             a = (*start);
             b = a;
             c = 0;
             continue;

           }else if( a->data == num && a->link == NULL  ){

                b->link = NULL;
                break;
           }

           a = a->link;

           if ( c == 1){
            b = b->link;
           }

           c = 1;

     }

}

// searching node

void searchingNode(node *start , int number){

    int nodeNum = 0;
    int total = nodeNumber(start);

    while( start != NULL ){

        if( start->data == number ){
            cout << "Position in the list " << nodeNum + 1<< endl;
            break;
        }

         nodeNum++;
         start = start->link;
    }

    if( total == nodeNum ){

         cout << "Data not found!" << endl;
    }

}

//  Reversing the linked list

void reverseLinkedList( node **start ){

     node *temp = *start;
     node *previous =NULL , *present =  temp , *next; //= present->link;

     while( present != NULL ){

          next = present->link;
          present->link = previous;
          previous = present;


        *start = present;

         present = next;
     }
}
