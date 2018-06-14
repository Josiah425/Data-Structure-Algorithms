#include "Hello_Class.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
   Hello_Class *my_hello_ptr = new Hello_Class(0);

   my_hello_ptr->print_hello();
   delete(my_hello_ptr);

   Hello_Class my_hello(1);
   my_hello.print_hello();
}


