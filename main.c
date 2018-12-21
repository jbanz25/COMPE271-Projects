/** Code by Jacob Bananal, Red ID# 820416396, 11/26/18 **/

#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>

unsigned long uLongLFSR32 (unsigned long seedValue);

int main()
{
   int period = 0;
   unsigned long starting_state = 0x5AA5FF00;// This is where the seed will be starting at, given the 0x5AA5FF0


   for(period = 0; period <= 32; period++) // uses a FOR loop to display the 32 sequences when calling x86 function
   {
       starting_state = uLongLFSR32(starting_state); // calls the x86 assembly function below
       printf("%x\n", starting_state); //prints the 32 sequences once the x86 is called from this function above
   }
    return 0;
}

/** Assembly Code by Jacob Bananal, RED ID 820416396**/

asm (
     "_uLongLFSR32:;"               //According to the codeblock, this was how you mix c and assembly x86 together
     " pushl %ebp;"
     " movl %esp, %ebp;" //setup of the code

     " movl 8(%ebp), %edx;" // index 1 = edx and edx = starting_state
     " popl %ebp;" // moves the ebp from the stack
     " movl %edx, %eax;" //eax = starting_state above
     " andl $1, %eax;" // puts at index 0
     " negl %eax;" //turns the eax to neg
     " andl $9, %eax;" // puts it at index 1
     " shrl $1, %edx;" // makes both of the indexes align with each other
     " xorl %edx, %eax;" //edx ^ eax which will make the result
     " ret"
     );
