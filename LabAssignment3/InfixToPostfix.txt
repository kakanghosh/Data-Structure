#include <iostream>

using namespace std;


#define stack_size 20
int charlength(char *a);

class stacks{

      char stackss[stack_size];
       int top;

   public:

       stacks(){
          top = -1;
       }

        void push(char item){

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

      int getTop(){
        return top;
      }

};

int main()
{
   stacks st;
   char infix[20]; //"A+(B*C-(D/E^F)*G)*H)";
   char postfix[50];
   int i = 0;
   int postfix_counter = 0;
   char pop_item;

   cout << "Input Infix Expression: ";
   cin >> infix;

   int length = charlength(infix);

   infix[length] = ')';

     st.push('(');

   while( st.getTop() != -1){

        if( infix[i] >= 65 && infix[i] <= 90 ){

            postfix[postfix_counter++] = infix[i];

        }else if( infix[i] == '(' ){

            st.push(infix[i]);

         }else if( infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '*' || infix[i] == '^' ){


                        if( infix[i] == '^'){

                            st.push( infix[i] );

                        }else{

                            pop_item = st.pop();

                                    if( pop_item == '+' || pop_item == '-' || pop_item == '*' ||   pop_item == '/'  ){

                                         if( (pop_item == '*' || pop_item == '/') && ( infix[i] == '-' || infix[i] == '+' ) ){

                                               postfix[postfix_counter++] = pop_item;
                                               st.push(infix[i]);

                                         }else if( (pop_item == '+' || pop_item == '-') && ( infix[i] == '/' || infix[i] == '*' ) ){

                                             st.push(pop_item);
                                             st.push(infix[i]);

                                         }else{

                                             st.push(pop_item);
                                             st.push(infix[i]);

                                         }


                                    }else{

                                      st.push(pop_item);
                                      st.push(infix[i]);
                                    }

                        }



         }else if( infix[i] == ')' ){
                 char a ;//= st.pop();

                    while( (a =st.pop()) != '('  ){

                          postfix[postfix_counter++] = a;

                      }

         }

         i++;
    }

      postfix[postfix_counter] = NULL;

    cout << "Infix to Postfix : " << postfix  << endl;


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

