#include <iostream>
#include <stdlib.h>

using namespace std;

struct BSTNode{

     int data;
     BSTNode *left;
     BSTNode *right;
};

BSTNode* newBSTNode();
int data();
void addNewNode( BSTNode **start, int number );
int searching(BSTNode *temp, int number);

int main()
{
    BSTNode *root = NULL;
    int number;

    while( 1){

       // system("cls");

        cout << "Enter data: ";
        cin >> number;
        addNewNode(&root,number);
        cout << endl;





    }

    return 0;
}

//add a node

void addNewNode( BSTNode **start, int number )
{

           if( searching(*start, number) == 1){
             cout << "Data already in the tree" <<endl;
           }else{


      BSTNode *temp = *start;

      if( *start == NULL ){

          *start = newBSTNode();
          (*start)->data = number;
          cout << number << " added at the root!!" << endl;

      }else if( number < temp->data )
      {

            cout << "go to left from the root!" << endl;


            BSTNode *a = temp->left;
            BSTNode *b  = temp;
            int check = 0;

                 while( a != NULL ){

                       if( number < a->data  ){
                          b = a;
                          a = a->left;
                          check = 0;
                          cout << "go to left!" << endl;
                       }else{
                          b = a;
                          a = a->right;
                          check = 1;
                          cout << "go to right!" << endl;
                       }
                 }

                if(check == 0){

                     b->left = newBSTNode();
                     b->left->data = number;
                }else{
                    b->right = newBSTNode();
                     b->right->data = number;
                }

                cout << number << " added!!" << endl;

        }else{
           cout << "go to right from the root!" << endl;
           BSTNode *a = temp->right;
            BSTNode *b = temp;
            int check = 1;

                 while( a != NULL ){

                       if( number < a->data  ){
                          b = a;
                          a = a->left;
                          check = 0;
                          cout << "go to left!" << endl;
                       }else{
                          b = a;
                          a = a->right;
                          check = 1;
                          cout << "go to right!" << endl;
                       }
                 }

                if(check == 0){

                     b->left = newBSTNode();
                     b->left->data = number;
                }else{
                    b->right = newBSTNode();
                     b->right->data = number;
                }
                cout << number << " added!!" << endl;

      }

           }


      }


// searching

int searching(BSTNode *temp, int number){

    if( temp == NULL ) return 2;

    int counter = 0;

    if( temp->data == number ){
        counter = 1;
        return counter;
    }else if( number < temp->data ){

            BSTNode *a = temp->left;
            int check = 0;

                 while( a != NULL  ){

                       if( number < a->data  ){
                          a = a->left;
                         // counter = 1;
                       }else if( number > a->data ){
                          a = a->right;
                         // counter = 1;

                       }else if( number == a->data ){
                          counter = 1;
                          break;
                       }
                 }
              return counter;
          }else{

              BSTNode *a = temp->right;
            int check = 0;

                 while( a != NULL ){

                       if( number < a->data  ){
                          a = a->left;
                          //counter = 1;
                       }else if( number > a->data){
                          a = a->right;
                          //counter = 1;
                        }else if( number ==  a->data ){
                           counter = 1;
                           break;
                        }
                 }
              return counter;
          }
}

//get data

int data(){
   int n;

   cout << "Enter data: ";
   cin >> n;

   return n;
}

// getNewnode address

BSTNode* newBSTNode(){

      BSTNode *temp = new BSTNode;
     // temp->data = data();
      temp->left = temp->right = NULL;

    return temp;
}
