/**
    FINAL ASSEMBLY PROJECT (Sorting an Array)
    by JACOB BANANAL.
    RED ID #820416396.
    Professor Ken Arnold (COMPE271) **/

#include <stdio.h>
#include <stdlib.h>

const int ARRAY_MAXSIZE = 20; // maximum size of the array
void sortArray(int [],int); // assembly function that will be called

void main()
{
    int arrayList[ARRAY_MAXSIZE];
    int i, arraySize;

    printf("\nEnter the size of the array: "); // User inputs array size
    scanf("%d", &arraySize);

    printf("\nEnter %d elements in the array: \n", arraySize); // user inputs the integers in the array
    for(i = 0; i < arraySize; i++)
    {
        scanf("%d", &arrayList[i]);
    }

    sortArray(arrayList,arraySize); // calling the assembly function

    printf("\nThe array of integers in Ascending order are: \n");
    for (i = 0; i < arraySize; ++i)
    {
        printf("Element at Array[%d] = %d \n", i, arrayList[i]); // will print all the elements in ascending order
    }
}

/**
    Sorting an Array Assembly Code
    by Jacob Bananal
    Red ID# 820416396
  **/

asm(
    "_sortArray:;"
".SETUP:;"  // start up
	"pushl	%ebp;" // set up
	"movl	%esp, %ebp;" // sets the current %ebp to the %esp
	"subl	$16, %esp;" // allocates 4 local variables
	"movl	$0, -4(%ebp);"
	"jmp	.IF2;" //  directs jumps to the second if statement
".OUTERLOOP:;" // OUTERLOOP 1
	"movl	-4(%ebp), %eax;" // i
	"leal	0(,%eax,4), %edx;"  // assigns the address 0(,%eax,4) into %edx
	"movl	8(%ebp), %eax;" // first parameter argument (integerList)
	"addl	%edx, %eax;" // adds both registers
	"movl	(%eax), %eax;" // loads results into the %eax
	"movl	%eax, -12(%ebp);"
	"movl	-4(%ebp), %eax;" //loads the argument into the %eax
	"movl	%eax, -16(%ebp);"
	"movl	-4(%ebp), %eax;"
	"addl	$1, %eax;" // increments ++1
	"movl	%eax, -8(%ebp);"
	"jmp	.IF1;" //  directs jumps to the first if statement
".INNERLOOP:;" //INNER LOOP
	"movl	-8(%ebp), %eax;" // moves the i to -8(%ebp)
	"leal	0(,%eax,4), %edx;" // assigns the address 0(,%eax,4) into %edx
	"movl	8(%ebp), %eax;" // j
	"addl	%edx, %eax;" // j = i + 1
	"movl	(%eax), %eax;"
	"cmpl	-12(%ebp), %eax;" // compares j and the size of the array
	"jge	.CONTINUEINNER;" // CONTINUEs if the greater than or equal condition is true
	"movl	-8(%ebp), %eax;"
	"leal	0(,%eax,4), %edx;" // assigns the address 0(,%eax,4) into %edx
	"movl	8(%ebp), %eax;"
	"addl	%edx, %eax;" // adds both %edx and %eax together
	"movl	(%eax), %eax;"
	"movl	%eax, -12(%ebp);"
	"movl	-8(%ebp), %eax;"
	"movl	%eax, -16(%ebp);"
".CONTINUEINNER:;"
	"addl	$1, -8(%ebp);" // increments ++j
".IF1:;" //IF #1 statement
	"movl	-8(%ebp), %eax;"
	"cmpl	12(%ebp), %eax;" // compares currentMIn and numbers[j]. Also sets flags based on the comparison
	"jl	.INNERLOOP;" // If the less than statement is true, move on
	"movl	-16(%ebp), %eax;"
	"cmpl	-4(%ebp), %eax;"
	"je	.CONTINUEIF1;"  // if the condition is 0, continue
	"movl	-16(%ebp), %eax;" // line 88 to 103 is when it starts to swap
	"leal	0(,%eax,4), %edx;"
	"movl	8(%ebp), %eax;"
	"addl	%eax, %edx;" // adds both register together
	"movl	-4(%ebp), %eax;"
	"leal	0(,%eax,4), %ecx;" // assigns the address 0(,%eax,4) into %ecx
	"movl	8(%ebp), %eax;"
	"addl	%ecx, %eax;" // adds both registers together
	"movl	(%eax), %eax;" // loads the result into the eax
	"movl	%eax, (%edx);" // then loads into the pointer %edx
	"movl	-4(%ebp), %eax;"
	"leal	0(,%eax,4), %edx;" // assigns the address 0(,%eax,4) into %edx
	"movl	8(%ebp), %eax;"
	"addl	%eax, %edx;" // adds both registers
	"movl	-12(%ebp), %eax;"
	"movl	%eax, (%edx);"
".CONTINUEIF1:;" // CONTINUES IF #1
	"addl	$1, -4(%ebp);"
".IF2:;" // IF #2 statement
	"movl	12(%ebp), %eax;"
	"subl	$1, %eax;"
	"cmpl	-4(%ebp), %eax;" // compares the currentMinimumIndex
	"jg	.OUTERLOOP;"
	"leave;" // restores %ebp and %esp
	" ret"
    );
