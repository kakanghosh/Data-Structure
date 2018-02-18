#include <stdio.h>
#include <stdlib.h>

struct hello{


    int a;

    int pr(){
      return a;
    }

};

int main()
{
    struct hello ob;

    printf("%d",ob.a);





    return 0;
}
