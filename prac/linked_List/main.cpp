#include <iostream>

using namespace std;

   class node{
   public:
   int data;
   node *link;

};

int main()
{



    node *new_node = new node;
    node *start = new_node;
    new_node->link = NULL;

    char choice;

    while( true ){

          cout << "Enter data: ";
          cin >> new_node->data;

          cout << "Create new node? Y / N " ;
          cin >> choice;

          if( choice == 'Y' || choice == 'y' ){

              new_node = new_node->link = new node;

           }else if ( choice == 'N' || choice == 'n' ) {
              new_node->link = NULL;
              break;
          }
    }

    new_node = start;

    while( new_node != NULL ){

        cout << new_node->data << " -> ";
        new_node = new_node->link;
    }

    cout << "NULL" << endl;




    node *b = new node;
    node *c = new node;

    start = a;
    a->link = b;
    b->link = c;
    c->link = NULL;

    cin >> a->data;
    cin >> b->data;
    cin >> c->data;

    cout << a->data << " " << b->data << " " << c->data << endl;

    a->link = new node;
    a->link->link = new node;
    a->link->link->link = NULL;

    cin >> a->data;
    cin >> a->link->data;
    cin >> a->link->link->data;

     start = a;

    while( start != NULL ){

        cout << start->data << " -> ";

        start = start->link;
    }

    cout << "NULL" << endl;




    return 0;
}

/// ///////////////////////////////////////////////////////////////
/// /////////////Funtions are define here/////////////////////
/// ///////////////////////////////////////////////////////////////


node *newNode(){

}

