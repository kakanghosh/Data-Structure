#include <iostream>

using namespace std;

class node{

  public:
  int datas;
  node *add;

  public:
  node(){
  }

  int data(){
    return datas;
  }

  node* next(){
     return add;
  }

};

int main()
{
    node *head = NULL;

    node *a = new node();
    a->add = new node();
    a->add->add = new node();

    a->add->add->add = NULL;

    cout << "? ";
    cin >> a->datas;
    cout << "? ";
    cin >> a->add->datas;
    cout << "? ";
    cin >> a->add->add->datas;

    head = a;

    while( head!=NULL){

       cout << head->datas << endl;
       head = head->add;
    }


    return 0;
}
