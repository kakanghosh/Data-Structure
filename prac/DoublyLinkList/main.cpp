#include <iostream>

using namespace std;

class node{

 public:
   node *preLink;
   int data;
   node *postLink;

   node(){
   }

};

int main()
{

   node *start, *var;

   node *a = new node();

   a->preLink = start;
   a->postLink = NULL;
   start =  a;

   char choice;

   while( true ){

      cin >> a->data;
      cout << "Create new node? Y /N ";
      cin >> choice;

      if( choice == 'Y' || choice == 'y'){

            var = a;
            a->postLink = new node();
            a = a->postLink;
            a ->preLink = var;

      }else if( choice == 'N' || choice == 'n'){

          a->postLink = NULL;
          break;

      }

   }

   a = start;

     int no , counter = 1 ;
     node *del;

     while( true ){

        cout << "Delete node? ";
        cin >> no;

        while( a != NULL ){

           if( counter == no-1 ){

              del =  a;
              a = a ->postLink;
             // a = a ->postLink;
              del->postLink = a ->postLink;

              break;

           }

           counter++;
           a = a->postLink;

        }
        break;

     }

     a = start;

   while( a!= NULL ){

       cout << "Memory Location:" << a << " -> " << a->data << endl;
       a = a->postLink;

   }

   cout << "NULL" << endl;



    return 0;
}
