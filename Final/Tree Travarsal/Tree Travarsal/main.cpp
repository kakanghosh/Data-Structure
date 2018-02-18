#include <iostream>
#include <stdlib.h>

using namespace std;

struct BinaryNode{

    int data;
    BinaryNode *left;
    BinaryNode *right;


};



class binaryStack
{

    int top;
    BinaryNode *start[50];
    int a[50];
    int i ;

public:
    binaryStack(){
      top = 0;
      i = 0;
    }

    void Push( BinaryNode *root )
    {

       start[++top] = root;

    }

     void Push( BinaryNode *root , int n )
    {

       start[++top] = root;
       a[i++] = n;

    }

    bool ifRightchild(  )
    {

        int counter = 0;

        for( int j = 0; j < i; j++){
            if( a[j] == top ){
                a[j] = -1;   // making this index node invisible
                counter++;
                break;
            }
        }

        if( counter == 0){
            return false;
        }else{
          return true;
        }
    }

    int topValue(){
      return top+1;
    }

    BinaryNode* Top(){


       return start[top];
    }

    BinaryNode* Pop()
    {
       return start[top--];
    }

    bool isEmpty(){
       if( top == 0){
          return true;
       }else{
         return false;
       }
    }


};



BinaryNode* getNewNode();
int getData();
void addDataOnTree( BinaryNode **root , int data, int check );
void preOrderTravarsal( BinaryNode *root);
void inOrderTravarsal( BinaryNode *root);
void postOrderTravarsal( BinaryNode *root);

int main()
{
    BinaryNode *root = NULL;

   bool flag = true;
   int choice;

    int arr[9] = {15, 10, 13 , 8 , 11 , 27 , 24 , 26 , 35};

    for ( int i = 0; i < 9; i++){
            addDataOnTree(&root, arr[i], 0);
        }

        system("cls");


   while(flag){

       cout << "\n1. Create new node." << endl;
       cout << "2. Pre Order " << endl;
       cout << "3. In Order " << endl;
       cout << "4. Post Order " << endl;


       cout << "\nEnter your your choice: ";
       cin >> choice;

       system("cls");

       switch( choice ){

       case 1:

        addDataOnTree(&root, getData() , 0);



        break;

       case 2:

            preOrderTravarsal(root);

        break;

       case 3:
        inOrderTravarsal(root);
        break;

       case 4:
        postOrderTravarsal(root);
        break;

       }


   }

    return 0;
}

//pre order traversal

void preOrderTravarsal( BinaryNode *root)
{


     if ( root != NULL ){   // checking tree is empty or not

         binaryStack *st = new binaryStack;


         st->Push(NULL);

         BinaryNode *rootPtr = root;

         cout << "Pre order of tree: " ;

        while( rootPtr != NULL ){

             cout << rootPtr->data << " ";

               if( rootPtr->right != NULL ){

                  st->Push(rootPtr->right);
               }

               if( rootPtr->left != NULL ){
                  rootPtr = rootPtr->left;
               }else{
                  rootPtr = st->Pop();
               }

        }

     }



}

// In Order traversal

void inOrderTravarsal( BinaryNode *root)
{


     if ( root != NULL ){   // checking tree is empty or not

         binaryStack *st = new binaryStack;


         st->Push(NULL);

         BinaryNode *rootPtr = root;

         cout << "In order of tree: " ;

        while( rootPtr != NULL ){

             st->Push(rootPtr);

             if( rootPtr->left != NULL ){
                rootPtr = rootPtr->left;
                continue;
             }else{

                 do{

                    if( st->Top() != NULL ){

                          rootPtr = st->Pop();
                          cout << rootPtr->data << " ";
                    }else{
                       rootPtr = NULL;
                       break;
                    }

                 }

                 while( rootPtr->right == NULL );

                 if( rootPtr != NULL){
                    rootPtr = rootPtr->right;
                 }

             }

        }

     }



}

// Post Order Traversal

void postOrderTravarsal( BinaryNode *root)
{


     if ( root != NULL ){   // checking tree is empty or not

         binaryStack *st = new binaryStack;


         st->Push(NULL);

         BinaryNode *rootPtr = root;

         cout << "Pre order of tree: " ;

        while( rootPtr != NULL ){

              // code will goes here

              st->Push(rootPtr);

              if( rootPtr->right != NULL ){
                 st->Push(rootPtr->right, st->topValue() );
              }
              if( rootPtr->left != NULL ){

                 rootPtr = rootPtr->left;
                 continue;
              }else{

                 while( st->Top() != NULL ){

                       if( !st->ifRightchild() ){
                           rootPtr = st->Pop();

                           cout << rootPtr->data << " ";
                       }else{

                          rootPtr = st->Pop();
                          break;
                       }

                 }

                 if( st->Top()  == NULL ){
                    rootPtr = NULL;
                 }

              }


         }

     }
}



// add data on tree
void addDataOnTree( BinaryNode **root , int data , int check ){

     if( *root == NULL ){

         BinaryNode *a = getNewNode();
         a->data = data;

         *root = a;

         if( check == 0){
            cout << data << " added on the root!" << endl;
         }else{
            cout << data << " added on the tree!" << endl;
         }

     }else if( (*root)->data < data ){
           cout << "Go to right " << endl;
          addDataOnTree( &(*root)->right , data, check+1 );
     }else if( (*root)->data > data ){
         cout << "Go to left " << endl;
         addDataOnTree( &(*root)->left, data , check+1 );
     }

}


// get data from the user
int getData(){

     int data;

     cout << "Enter data: ";
     cin >> data;

     return data;
}

//Get New Node address

BinaryNode* getNewNode(){

    BinaryNode *a = new BinaryNode;
    a->data = 0;
    a->left = a->right = NULL;

    return a;

}
