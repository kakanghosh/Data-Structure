#include <iostream>

using namespace std;

#define stack_size 15
int charlength(char *a);

class stacks{

       int stackss[stack_size];
       int top;

   public:

       stacks(){
          top = -1;
       }

        void push(int item){

           if( top == stack_size - 1 ){
              cout << "\nStack overflow" << endl;
           }else{

              stackss[++top] = item;

           }
        }

                int pop(){

                    if( top == -1 ){
                        cout << "\nStack underflow." << endl;
                    }else{

                      return stackss[top--];
                    }
                }


};



int main()
{

   stacks st;
   char postfix[20]; //"31-2+62+2-*)";
   int first,second;
   int i = 0;

   cout << "Input postfix expression: ";
   cin >> postfix;

   int length = charlength(postfix);

   postfix[ length ] = ')';


   while( postfix[i] != ')' ){

       if( postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' ){

           second =  st.pop();
           first =  st.pop();

           if( postfix[i] == '+' ){
               st.push(second+first);
           }else if( postfix[i] == '-' ){
              st.push(first - second);
           }else if( postfix[i] == '*' ){
              st.push(first * second);
           }else if( postfix[i] == '/' ){
              st.push(first / second);
           }

       }else{
           st.push((int) postfix[i] - 48);
       }

       i++;
   }

   cout << "Postfix result: " << st.pop() << endl;



    return 0;
}

int charlength(char *a){
   int i = 0 , counter = 0;

   while( a[i]!=NULL ){
      counter++;
      i++;
   }
   return counter;
}


