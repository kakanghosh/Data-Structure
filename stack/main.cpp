#include <iostream>

using namespace std;

class stacks
{
    int length;
    int top = -1;
    int Stack[];


  public:
   //Constructor ---------------------
    stacks(){
       length = 1024;
     //  Stack[length];
    }

    stacks(int s){
       length = s;
     //  Stack[length];
    }

    //-----------PUSH---------------------

    void Push(int value){

        if( ++top < length ){
            Stack[top] = value;
        }else{

           cout << "Stack Overflow" << endl;
        }
    }

    //----POP---------------

    int Pop(){

       if( top < 0){

          cout << "Stack is Empty" << endl;
       }else{
          int m = Stack[top];
           Stack[top--] = NULL ;

           return m;
       }

    }

    //--------TOP------

    int Top(){

          return top+1;


    }

    //-------isEmpty---------

    bool isEmpty(){

        return ( top < 0 ) ? true : false;

    }

    //---- Size --------\

    int sizeOfStack(){

       return top+1;
    }

};



int main()
{

   stacks *st = new stacks(3);
  // stacks st(3);
   int n , i = 0;

   //stack1.Push(5);

   while(i < 5){

      cin >> n;

      st->Push(n);

      i++;
   }


   delete(st);



    return 0;
}
