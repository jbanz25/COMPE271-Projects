	.file	"main.c"
	.globl	ARRAY_MAXSIZE
	.section	.rodata
	.align 4
	.type	ARRAY_MAXSIZE, @object
	.size	ARRAY_MAXSIZE, 4
ARRAY_MAXSIZE:
	.long	20
	.align 4
.LC0:
	.string	"\nEnter the size of the array: "
.LC1:
	.string	"%d"
	.align 4
.LC2:
	.string	"\nEnter %d elements in the array: \n"
	.align 4
.LC3:
	.string	"\nThe array of integers in Ascending order are: "
.LC4:
	.string	"Element at Array[%d] = %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$32, %esp
	movl	%esp, %eax
	movl	%eax, %ebx
	movl	$20, %eax
	subl	$1, %eax
	movl	%eax, -16(%ebp)
	movl	$20, %eax
	sall	$2, %eax
	leal	3(%eax), %edx
	movl	$16, %eax
	subl	$1, %eax
	addl	%edx, %eax
	movl	$16, %ecx
	movl	$0, %edx
	divl	%ecx
	imull	$16, %eax, %eax
	subl	%eax, %esp
	leal	12(%esp), %eax
	addl	$3, %eax
	shrl	$2, %eax
	sall	$2, %eax
	movl	%eax, -20(%ebp)
	movl	$.LC0, (%esp)
	call	printf
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	__isoc99_scanf
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$0, -12(%ebp)
	jmp	.L2
.L3:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	__isoc99_scanf
	addl	$1, -12(%ebp)
.L2:
	movl	-24(%ebp), %eax
	cmpl	%eax, -12(%ebp)
	jl	.L3
	movl	-24(%ebp), %edx
	movl	-20(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	sortArray
	movl	$.LC3, (%esp)
	call	puts
	movl	$0, -12(%ebp)
	jmp	.L4
.L5:
	movl	-20(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	addl	$1, -12(%ebp)
.L4:
	movl	-24(%ebp), %eax
	cmpl	%eax, -12(%ebp)
	jl	.L5
	movl	%ebx, %esp
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.globl	sortArray
	.type	sortArray, @function
sortArray:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	.L7
.L12:
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -8(%ebp)
	jmp	.L8
.L10:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	-12(%ebp), %eax
	jge	.L9
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -16(%ebp)
.L9:
	addl	$1, -8(%ebp)
.L8:
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	.L10
	movl	-16(%ebp), %eax
	cmpl	-4(%ebp), %eax
	je	.L11
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%edx)
.L11:
	addl	$1, -4(%ebp)
.L7:
	movl	12(%ebp), %eax
	subl	$1, %eax
	cmpl	-4(%ebp), %eax
	jg	.L12
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	sortArray, .-sortArray
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-36)"
	.section	.note.GNU-stack,"",@progbits
