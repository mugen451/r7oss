/*
 * Written by J.T. Conklin <jtc@netbsd.org>.
 * Public domain.
 *
 * Adapted for `long double' by Ulrich Drepper <drepper@cygnus.com>.
 * Adapted for x86-64 by Andreas Jaeger <aj@suse.de>.
 * Fixed errno handling by Ulrich Drepper <drepper@redhat.com>.
 */

#define __need_Emath
#include <bits/errno.h>
#include <machine/asm.h>

ENTRY(__cosl)
	fldt	8(%rsp)
	fxam
	fstsw	%ax
	movb	$0x45, %dh
	andb	%ah, %dh
	cmpb	$0x05, %dh
	je	3f
4:	fcos
	fnstsw	%ax
	testl	$0x400,%eax
	jnz	1f
	ret
	.align ALIGNARG(4)
1:	fldpi
	fadd	%st(0)
	fxch	%st(1)
2:	fprem1
	fnstsw	%ax
	testl	$0x400,%eax
	jnz	2b
	fstp	%st(1)
	fcos
	ret
3:	call	__errno_location@PLT
	movl	$EDOM, (%rax)
	jmp	4b
END (__cosl)
weak_alias (__cosl, cosl)
