	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2                               ## -- Begin function fpWeirdness
LCPI0_0:
	.long	0x3f800000                      ## float 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_fpWeirdness
	.p2align	4, 0x90
_fpWeirdness:                           ## @fpWeirdness
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorps	%xmm0, %xmm0
	movss	%xmm0, -4(%rbp)
	movss	LCPI0_0(%rip), %xmm0            ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -8(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movss	-4(%rbp), %xmm1                 ## xmm1 = mem[0],zero,zero,zero
	movss	-8(%rbp), %xmm0                 ## xmm0 = mem[0],zero,zero,zero
	ucomiss	%xmm1, %xmm0
	jbe	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movss	LCPI0_0(%rip), %xmm0            ## xmm0 = mem[0],zero,zero,zero
	addss	-4(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
	movss	LCPI0_0(%rip), %xmm0            ## xmm0 = mem[0],zero,zero,zero
	addss	-4(%rbp), %xmm0
	movss	%xmm0, -8(%rbp)
	jmp	LBB0_1
LBB0_3:
	movss	-4(%rbp), %xmm0                 ## xmm0 = mem[0],zero,zero,zero
	cvtss2sd	%xmm0, %xmm0
	leaq	L_.str(%rip), %rdi
	movb	$1, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_intWeirdness                   ## -- Begin function intWeirdness
	.p2align	4, 0x90
_intWeirdness:                          ## @intWeirdness
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$1, -4(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -4(%rbp)
	jle	LBB1_3
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB1_1
LBB1_3:
	movl	-4(%rbp), %esi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3                               ## -- Begin function fractionalWeirdness
LCPI2_0:
	.quad	0x3fb999999999999a              ## double 0.10000000000000001
LCPI2_1:
	.quad	0x3fefae147ae147ae              ## double 0.98999999999999999
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_fractionalWeirdness
	.p2align	4, 0x90
_fractionalWeirdness:                   ## @fractionalWeirdness
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movsd	LCPI2_0(%rip), %xmm0            ## xmm0 = mem[0],zero
	movsd	%xmm0, -8(%rbp)
	movl	$0, -12(%rbp)
	xorps	%xmm0, %xmm0
	movsd	%xmm0, -24(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movsd	LCPI2_1(%rip), %xmm0            ## xmm0 = mem[0],zero
	ucomisd	-24(%rbp), %xmm0
	jbe	LBB2_3
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movsd	-24(%rbp), %xmm0                ## xmm0 = mem[0],zero
	addsd	-8(%rbp), %xmm0
	movsd	%xmm0, -24(%rbp)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB2_1
LBB2_3:
	movl	-12(%rbp), %esi
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	callq	_fpWeirdness
	callq	_intWeirdness
	callq	_fractionalWeirdness
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	jmp	LBB3_1
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"The largest number in the universe is %f\n"

L_.str.1:                               ## @.str.1
	.asciz	"The largest integer in the universe is %d\n"

L_.str.2:                               ## @.str.2
	.asciz	"it takes %d tenths to equal a whole\n"

L_.str.3:                               ## @.str.3
	.asciz	"all done, hit ctrl-c to stop this program\n"

.subsections_via_symbols
