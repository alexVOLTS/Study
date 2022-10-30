	.file	"event_schedule.c"
	.text
	.globl	_event_time_check_start
	.def	_event_time_check_start;	.scl	2;	.type	32;	.endef
_event_time_check_start:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	16(%ebp), %eax
	cmpl	$24, %eax
	jg	L2
	movl	20(%ebp), %eax
	cmpl	$60, %eax
	jg	L2
	movl	$1, %eax
	jmp	L3
L2:
	movl	$0, %eax
L3:
	andl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.globl	_event_time_check_end
	.def	_event_time_check_end;	.scl	2;	.type	32;	.endef
_event_time_check_end:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	24(%ebp), %eax
	cmpl	$24, %eax
	jg	L6
	movl	28(%ebp), %eax
	cmpl	$60, %eax
	jg	L6
	movl	$1, %eax
	jmp	L7
L6:
	movl	$0, %eax
L7:
	andl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.globl	_event_triggered_transition
	.def	_event_triggered_transition;	.scl	2;	.type	32;	.endef
_event_triggered_transition:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	(%edx,%eax), %ecx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	addl	%edx, %eax
	cmpl	%eax, %ecx
	jg	L10
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	(%edx,%eax), %ecx
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	addl	%edx, %eax
	cmpl	%eax, %ecx
	jle	L11
L10:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	(%edx,%eax), %ecx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	addl	%edx, %eax
	cmpl	%eax, %ecx
	jl	L12
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	(%edx,%eax), %ecx
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	addl	%edx, %eax
	cmpl	%eax, %ecx
	jl	L12
L11:
	movl	$1, %eax
	jmp	L13
L12:
	movl	$0, %eax
L13:
	andl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.globl	_event_triggered_transitionless
	.def	_event_triggered_transitionless;	.scl	2;	.type	32;	.endef
_event_triggered_transitionless:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	(%edx,%eax), %ecx
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	addl	%edx, %eax
	cmpl	%eax, %ecx
	jl	L16
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	leal	(%edx,%eax), %ecx
	movl	8(%ebp), %eax
	movl	16(%eax), %eax
	imull	$60, %eax, %edx
	movl	8(%ebp), %eax
	movl	20(%eax), %eax
	addl	%edx, %eax
	cmpl	%eax, %ecx
	jg	L16
	movl	$1, %eax
	jmp	L17
L16:
	movl	$0, %eax
L17:
	andl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.globl	_event_zero_point
	.def	_event_zero_point;	.scl	2;	.type	32;	.endef
_event_zero_point:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L20
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	L20
	movl	$1, %eax
	jmp	L21
L20:
	movl	$0, %eax
L21:
	andl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
