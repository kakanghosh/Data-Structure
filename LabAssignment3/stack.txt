#include <iostream>

using namespace std;

#define stack_size 5


class stacks{

       int stackss[stack_size];
       int top;

   public:

       stacks(){
          top = -1;
       }

        void push(){

           if( top == stack_size - 1 ){
              cout << "\nStack overflow" << endl;
           }else{
              int item;
              cout << "\nEnter number: ";
              cin >> item;
              stackss[++top] = item;
              cout << item << " pushed in the stack." << endl;
           }
        }

                void pop(){

                    if( top == -1 ){
                        cout << "\nStack underflow." << endl;
                    }else{

                      int item = stackss[top--];

                      cout << item << " popped from the stack." << endl;
                    }
                }


            void display(){

               if( top == -1 ){
                            cout << "\nStack is empty " << endl;
                          }else{

                             int display = top;

                         cout << "\nStacks item -- " << endl;

                         while( display >= 0 ){

                             cout << stackss[display] << endl;
                             display--;
                         }

                          }

            }

};


int main()
{
   stacks st;
   bool flag = true;
   int choice;


   while( flag ){

     cout << "Press 1 to PUSH in the stack." << endl;
     cout << "Press 2 to POP from the stack." << endl;
     cout <<  "Press 3 to Display the stack." << endl;
     cout << "Press 4 to exit" << endl << endl;

     cout << "Enter your choice: ";
     cin >> choice;

     switch(choice){

        case 1:

               st.push();

            break;


        case 2:

              st.pop();

            break;


        case 3:

               st.display();
            break;


        case 4:

            cout << "Exit...." << endl;
            flag = false;
            break;


        default:
            cout << "Incorrect choice!!! Try again" << endl;
            break;
     }

     cout << endl << endl;
   }



    return 0;
}



