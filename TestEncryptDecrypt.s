	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
	.eabi_attribute 18, 4
	.file	"TestEncryptDecrypt.c"
	.text
	.align	2
	.global	lessThanEqual
	.type	lessThanEqual, %function
lessThanEqual:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	str	r4, [sp, #-4]!
	mov	r4, r0
	mov	r0, r1
	ldrb	ip, [r0, #0]	@ zero_extendqisi2
	ldrb	r1, [r4, #0]	@ zero_extendqisi2
	mov	r3, #128
	mov	r2, #0
.L10:
	tst	r1, r3
	bne	.L12
	tst	ip, r3
	beq	.L4
	mov	r0, #1
.L5:
	ldmfd	sp!, {r4}
	bx	lr
.L12:
	tst	ip, r3
	beq	.L13
.L4:
	cmp	r2, #4
	bhi	.L14
	movs	r3, r3, lsr #1
	addeq	r2, r2, #1
	ldreqb	r1, [r4, r2]	@ zero_extendqisi2
	ldreqb	ip, [r0, r2]	@ zero_extendqisi2
	moveq	r3, #128
	b	.L10
.L14:
	mov	r0, #0
	b	.L5
.L13:
	mvn	r0, #0
	b	.L5
	.size	lessThanEqual, .-lessThanEqual
	.align	2
	.global	shiftRight
	.type	shiftRight, %function
shiftRight:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	stmfd	sp!, {r4, r5, r6, r7, r8}
	ldrb	r4, [r0, #0]	@ zero_extendqisi2
	ldrb	r2, [r0, #1]	@ zero_extendqisi2
	ldrb	r1, [r0, #2]	@ zero_extendqisi2
	ldrb	ip, [r0, #3]	@ zero_extendqisi2
	ldrb	r3, [r0, #4]	@ zero_extendqisi2
	and	r5, r4, #1
	and	r6, r2, #1
	and	r7, r1, #1
	and	r8, ip, #1
	mov	r3, r3, lsr #1
	mov	r2, r2, lsr #1
	mov	r1, r1, lsr #1
	mov	ip, ip, lsr #1
	orr	r2, r2, r5, asl #7
	orr	r1, r1, r6, asl #7
	orr	ip, ip, r7, asl #7
	orr	r3, r3, r8, asl #7
	mov	r4, r4, lsr #1
	strb	r3, [r0, #4]
	strb	r4, [r0, #0]
	strb	r2, [r0, #1]
	strb	r1, [r0, #2]
	strb	ip, [r0, #3]
	mov	r0, #1
	ldmfd	sp!, {r4, r5, r6, r7, r8}
	bx	lr
	.size	shiftRight, .-shiftRight
	.align	2
	.global	bitOffset
	.type	bitOffset, %function
bitOffset:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	r2, #0
	mov	r1, r0
	ldrb	r3, [r1, r2]	@ zero_extendqisi2
	cmp	r3, #0
	mov	r0, r2
	beq	.L18
	tst	r3, #128
	bxne	lr
.L23:
	tst	r3, #64
	add	r0, r0, #1
	bxne	lr
	tst	r3, #32
	add	r0, r0, #1
	bxne	lr
	tst	r3, #16
	add	r0, r0, #1
	bxne	lr
	tst	r3, #8
	add	r0, r0, #1
	bxne	lr
	tst	r3, #4
	add	r0, r0, #1
	bxne	lr
	tst	r3, #2
	add	r0, r0, #1
	bxne	lr
	tst	r3, #1
	add	r0, r0, #1
	bxne	lr
	add	r0, r0, #1
.L18:
	add	r2, r2, #1
	cmp	r2, #5
	beq	.L20
	ldrb	r3, [r1, r2]	@ zero_extendqisi2
	cmp	r3, #0
	add	r0, r0, #8
	beq	.L18
	tst	r3, #128
	beq	.L23
	bx	lr
.L20:
	mov	r0, #40
	bx	lr
	.size	bitOffset, .-bitOffset
	.align	2
	.global	subtraction
	.type	subtraction, %function
subtraction:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	stmfd	sp!, {r4, r5}
	mov	r4, r2
	mov	r3, r4
	mov	r2, #0
	strb	r2, [r3], #1
	add	r3, r3, #1
	strb	r2, [r4, #1]
	strb	r2, [r3], #1
	strb	r2, [r3], #1
	mov	r5, r1
	strb	r2, [r3, #0]
	mov	r1, r2
	mov	ip, #1
	add	r2, r2, #4
	b	.L35
.L26:
	ldrb	r3, [r5, r2]	@ zero_extendqisi2
	tst	r3, ip
	beq	.L30
	cmp	r1, #0
	ldreqb	r3, [r4, r2]	@ zero_extendqisi2
	orreq	r3, r3, ip
	streqb	r3, [r4, r2]
	addeq	r1, r1, #1
.L28:
	cmp	r2, #0
	beq	.L38
.L31:
	mov	ip, ip, asl #1
	cmp	ip, #128
	subhi	r2, r2, #1
	movhi	ip, #1
.L35:
	ldrb	r3, [r0, r2]	@ zero_extendqisi2
	tst	r3, ip
	beq	.L26
	ldrb	r3, [r5, r2]	@ zero_extendqisi2
	ands	r3, r3, ip
	bne	.L30
	cmp	r1, #0
	movne	r1, r3
	bne	.L28
.L36:
	ldrb	r3, [r4, r2]	@ zero_extendqisi2
	cmp	r2, #0
	orr	r3, r3, ip
	strb	r3, [r4, r2]
	bne	.L31
.L38:
	mov	r0, #1
	ldmfd	sp!, {r4, r5}
	bx	lr
.L30:
	cmp	r1, #0
	beq	.L28
	b	.L36
	.size	subtraction, .-subtraction
	.align	2
	.global	addition
	.type	addition, %function
addition:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	r3, #0
	stmfd	sp!, {r4, r5, r6, r7}
	mov	r4, r2
	strb	r3, [r2], #1
	add	ip, r2, #2
	strb	r3, [r4, #1]
	strb	r3, [r2, #1]
	strb	r3, [ip], #1
	strb	r3, [ip, #0]
	ldrb	r3, [r0, #4]	@ zero_extendqisi2
	cmp	r3, #255
	mov	r6, r0
	mov	r0, r1
	beq	.L70
	ldrb	r1, [r4, #4]	@ zero_extendqisi2
	ldrb	r2, [r0, #4]	@ zero_extendqisi2
	add	r7, r0, #4
	add	r5, r4, #4
.L68:
	add	ip, r4, #3
.L42:
	add	r3, r3, r2
	add	r3, r1, r3
	and	r2, r3, #255
	strb	r2, [r5, #0]
	ldrb	r3, [r6, #4]	@ zero_extendqisi2
	cmp	r3, r2
	bhi	.L45
	ldrb	r3, [r7, #0]	@ zero_extendqisi2
	cmp	r3, r2
	bhi	.L45
	ldrb	r3, [r6, #3]	@ zero_extendqisi2
	cmp	r3, #255
	beq	.L71
.L46:
	ldrb	r5, [ip, #0]	@ zero_extendqisi2
	ldrb	r2, [r0, #3]	@ zero_extendqisi2
	add	r7, r0, #3
.L69:
	add	r1, r4, #2
.L48:
	add	r3, r3, r2
	add	r3, r5, r3
	and	r2, r3, #255
	strb	r2, [ip, #0]
	ldrb	r3, [r6, #3]	@ zero_extendqisi2
	cmp	r3, r2
	bhi	.L51
	ldrb	r3, [r7, #0]	@ zero_extendqisi2
	cmp	r3, r2
	bhi	.L51
	ldrb	r2, [r6, #2]	@ zero_extendqisi2
	cmp	r2, #255
	beq	.L72
.L52:
	ldrb	ip, [r1, #0]	@ zero_extendqisi2
	ldrb	r3, [r0, #2]	@ zero_extendqisi2
	add	r5, r0, #2
.L54:
	add	r3, r2, r3
	add	r3, ip, r3
	and	r2, r3, #255
	strb	r2, [r1, #0]
	ldrb	r3, [r6, #2]	@ zero_extendqisi2
	cmp	r3, r2
	bhi	.L57
	ldrb	r3, [r5, #0]	@ zero_extendqisi2
	cmp	r3, r2
	bhi	.L57
	ldrb	ip, [r6, #1]	@ zero_extendqisi2
	cmp	ip, #255
	beq	.L58
.L73:
	ldrb	r3, [r4, #1]	@ zero_extendqisi2
	ldrb	r2, [r0, #1]	@ zero_extendqisi2
	add	r1, r0, #1
.L59:
	add	r3, ip, r3
	add	r3, r2, r3
	and	r2, r3, #255
	strb	r2, [r4, #1]
	ldrb	r3, [r6, #1]	@ zero_extendqisi2
	cmp	r3, r2
	bhi	.L61
	ldrb	r3, [r1, #0]	@ zero_extendqisi2
	cmp	r3, r2
	bls	.L62
.L61:
	ldrb	r3, [r4, #0]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [r4, #0]
.L62:
	ldrb	r3, [r0, #0]	@ zero_extendqisi2
	ldrb	r2, [r6, #0]	@ zero_extendqisi2
	add	r3, r3, r2
	strb	r3, [r4, #0]
	mov	r0, #1
	ldmfd	sp!, {r4, r5, r6, r7}
	bx	lr
.L57:
	ldrb	r3, [r4, #1]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [r4, #1]
	ldrb	ip, [r6, #1]	@ zero_extendqisi2
	cmp	ip, #255
	bne	.L73
.L58:
	ldrb	r2, [r0, #1]	@ zero_extendqisi2
	cmp	r2, #255
	add	r1, r0, #1
	ldrneb	r3, [r4, #1]	@ zero_extendqisi2
	bne	.L59
	ldrb	r3, [r4, #1]	@ zero_extendqisi2
	cmp	r3, #1
	bne	.L59
	ldrb	r3, [r4, #0]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [r4, #0]
	ldrb	r3, [r4, #1]	@ zero_extendqisi2
	ldrb	ip, [r6, #1]	@ zero_extendqisi2
	ldrb	r2, [r0, #1]	@ zero_extendqisi2
	b	.L59
.L51:
	ldrb	r3, [r1, #0]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [r1, #0]
	ldrb	r2, [r6, #2]	@ zero_extendqisi2
	cmp	r2, #255
	bne	.L52
.L72:
	ldrb	r3, [r0, #2]	@ zero_extendqisi2
	cmp	r3, #255
	add	r5, r0, #2
	ldrneb	ip, [r1, #0]	@ zero_extendqisi2
	bne	.L54
	ldrb	ip, [r1, #0]	@ zero_extendqisi2
	cmp	ip, #1
	bne	.L54
	ldrb	r3, [r4, #1]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [r4, #1]
	ldrb	ip, [r1, #0]	@ zero_extendqisi2
	ldrb	r2, [r6, #2]	@ zero_extendqisi2
	ldrb	r3, [r0, #2]	@ zero_extendqisi2
	b	.L54
.L45:
	ldrb	r3, [ip, #0]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [ip, #0]
	ldrb	r3, [r6, #3]	@ zero_extendqisi2
	cmp	r3, #255
	bne	.L46
.L71:
	ldrb	r2, [r0, #3]	@ zero_extendqisi2
	cmp	r2, #255
	add	r7, r0, #3
	ldrneb	r5, [ip, #0]	@ zero_extendqisi2
	addne	r1, r4, #2
	bne	.L48
	ldrb	r5, [ip, #0]	@ zero_extendqisi2
	cmp	r5, #1
	bne	.L69
	ldrb	r3, [r4, #2]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [r4, #2]
	add	r1, r4, #2
	ldrb	r5, [ip, #0]	@ zero_extendqisi2
	ldrb	r3, [r6, #3]	@ zero_extendqisi2
	ldrb	r2, [r0, #3]	@ zero_extendqisi2
	b	.L48
.L70:
	ldrb	r2, [r1, #4]	@ zero_extendqisi2
	cmp	r2, #255
	add	r7, r1, #4
	addne	r5, r4, #4
	ldrneb	r1, [r4, #4]	@ zero_extendqisi2
	addne	ip, r4, #3
	bne	.L42
	ldrb	r1, [r4, #4]	@ zero_extendqisi2
	cmp	r1, #1
	add	r5, r4, #4
	bne	.L68
	ldrb	r3, [r4, #3]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [r4, #3]
	add	ip, r4, #3
	ldrb	r1, [r4, #4]	@ zero_extendqisi2
	ldrb	r3, [r6, #4]	@ zero_extendqisi2
	ldrb	r2, [r0, #4]	@ zero_extendqisi2
	b	.L42
	.size	addition, .-addition
	.align	2
	.global	binaryToDecimal
	.type	binaryToDecimal, %function
binaryToDecimal:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	mov	r4, r0
	sub	sp, sp, #8
	mov	r3, #0
	mov	r1, r4
	mov	r0, sp
	mov	r2, #5
	strb	r3, [sp, #4]
	str	r3, [sp, #0]
	bl	memcpy
	ldrb	r0, [r4, #1]	@ zero_extendqisi2
	ldrb	r1, [r4, #2]	@ zero_extendqisi2
	ldrb	r3, [r4, #4]	@ zero_extendqisi2
	ldrb	r2, [r4, #3]	@ zero_extendqisi2
	strb	r3, [sp, #0]
	strb	r1, [sp, #2]
	strb	r2, [sp, #1]
	strb	r0, [sp, #3]
	ldr	r0, [sp, #0]
	add	sp, sp, #8
	ldmfd	sp!, {r4, lr}
	bx	lr
	.size	binaryToDecimal, .-binaryToDecimal
	.align	2
	.global	divStringByTwo
	.type	divStringByTwo, %function
divStringByTwo:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, lr}
	ldrb	r1, [r0, #0]	@ zero_extendqisi2
	cmp	r1, #0
	mov	r4, r0
	beq	.L77
	mov	ip, #0
	mov	lr, #1
.L82:
	sub	r3, r1, #49
	mov	r2, r3, asl #24
	and	r3, r3, #255
	cmp	r3, #8
	mov	r2, r2, asr #24
	bhi	.L78
	mov	r3, lr, asl r2
	bic	r3, r3, #170
	mov	r3, r3, asl #23
	mov	r3, r3, lsr #23
	cmp	r3, #0
	movne	r2, #5
	beq	.L78
.L80:
	sub	r3, r1, #48
	add	r3, r3, r3, lsr #31
	add	r3, ip, r3, asr #1
	add	r3, r3, #48
	strb	r3, [r0, #0]
	ldrb	r1, [r0, #1]!	@ zero_extendqisi2
	cmp	r1, #0
	mov	ip, r2
	bne	.L82
	ldrb	r3, [r4, #0]	@ zero_extendqisi2
	cmp	r3, #48
	bne	.L77
	mov	r2, r1
.L83:
	add	r2, r2, #1
	ldrb	r3, [r4, r2]	@ zero_extendqisi2
	cmp	r3, #48
	beq	.L83
	mov	r5, r2
.L84:
	mov	r0, r4
	bl	strlen
	add	r2, r0, #1
	rsb	r2, r5, r2
	mov	r0, r4
	add	r1, r4, r5
	bl	memmove
	ldmfd	sp!, {r4, r5, r6, lr}
	bx	lr
.L78:
	mov	r2, #0
	b	.L80
.L77:
	mov	r5, #0
	b	.L84
	.size	divStringByTwo, .-divStringByTwo
	.align	2
	.global	printArr
	.type	printArr, %function
printArr:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, lr}
	ldr	r4, .L89
	mov	r5, r0
	ldrb	r1, [r0, #0]	@ zero_extendqisi2
	mov	r0, r4
	bl	printf
	ldrb	r1, [r5, #1]	@ zero_extendqisi2
	mov	r0, r4
	bl	printf
	ldrb	r1, [r5, #2]	@ zero_extendqisi2
	mov	r0, r4
	bl	printf
	ldrb	r1, [r5, #3]	@ zero_extendqisi2
	mov	r0, r4
	bl	printf
	mov	r0, r4
	ldrb	r1, [r5, #4]	@ zero_extendqisi2
	bl	printf
	mov	r0, #10
	bl	putchar
	ldmfd	sp!, {r4, r5, r6, lr}
	bx	lr
.L90:
	.align	2
.L89:
	.word	.LC0
	.size	printArr, .-printArr
	.align	2
	.global	shiftLeft
	.type	shiftLeft, %function
shiftLeft:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	r1, #0
	ldrb	r2, [r0, r1]	@ zero_extendqisi2
	cmp	r2, #0
	mov	r3, r1
	beq	.L92
.L100:
	tst	r2, #128
	bne	.L93
	tst	r2, #64
	add	r3, r3, #1
	bne	.L93
	tst	r2, #32
	add	r3, r3, #1
	bne	.L93
	tst	r2, #16
	add	r3, r3, #1
	bne	.L93
	tst	r2, #8
	add	r3, r3, #1
	bne	.L93
	tst	r2, #4
	add	r3, r3, #1
	bne	.L93
	tst	r2, #2
	add	r3, r3, #1
	bne	.L93
	tst	r2, #1
	add	r3, r3, #1
	bne	.L93
	add	r3, r3, #1
.L92:
	add	r1, r1, #1
	cmp	r1, #5
	beq	.L94
.L101:
	ldrb	r2, [r0, r1]	@ zero_extendqisi2
	cmp	r2, #0
	add	r3, r3, #8
	bne	.L100
	add	r1, r1, #1
	cmp	r1, #5
	bne	.L101
.L94:
	ldrb	r3, [r0, #4]	@ zero_extendqisi2
	mov	r3, r3, asl #1
	strb	r3, [r0, #4]
	mov	r0, #1
	bx	lr
.L93:
	mov	ip, r3, lsr #3
	sub	r3, ip, #1
	cmp	r3, #3
	bhi	.L94
	add	r3, r0, ip
	ldrb	r1, [r3, #-1]	@ zero_extendqisi2
	mov	r2, r3
.L96:
	mov	r3, r1, asl #1
	ldrb	r1, [r2, #0]	@ zero_extendqisi2
	and	r3, r3, #255
	add	ip, ip, #1
	orr	r3, r3, r1, lsr #7
	cmp	ip, #5
	strb	r3, [r2, #-1]
	add	r2, r2, #1
	bne	.L96
	ldrb	r3, [r0, #4]	@ zero_extendqisi2
	mov	r3, r3, asl #1
	strb	r3, [r0, #4]
	mov	r0, #1
	bx	lr
	.size	shiftLeft, .-shiftLeft
	.align	2
	.global	stringToBinary
	.type	stringToBinary, %function
stringToBinary:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 200
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	mov	r9, r1
	mov	r3, r9
	mov	r1, #0
	strb	r1, [r3], #1
	add	r3, r3, #1
	strb	r1, [r9, #1]
	strb	r1, [r3], #1
	strb	r1, [r3], #1
	sub	sp, sp, #204
	strb	r1, [r3, #0]
	mov	r4, r0
	mov	r2, #200
	mov	r0, sp
	bl	memset
	mov	r0, sp
	mov	r1, r4
	bl	strcpy
	mov	r8, #1
	mov	r5, sp
	mov	sl, #4
	add	fp, sp, r8
.L103:
	mov	r7, #1
	mov	r6, #0
.L114:
	ldrb	r4, [sp, #0]	@ zero_extendqisi2
	cmp	r4, #0
	beq	.L119
	mov	r0, sp
	bl	strlen
	add	r3, sp, #200
	add	r0, r3, r0
	ldrb	r3, [r0, #-201]	@ zero_extendqisi2
	sub	r3, r3, #49
	and	r2, r3, #255
	cmp	r2, #8
	bhi	.L104
	mov	r3, r3, asl #24
	mov	r3, r3, asr #24
	mov	r3, r8, asl r3
	bic	r3, r3, #170
	mov	r3, r3, asl #23
	mov	r3, r3, lsr #23
	cmp	r3, #0
	ldrneb	r3, [r9, sl]	@ zero_extendqisi2
	orrne	r3, r7, r3
	strneb	r3, [r9, sl]
.L104:
	mov	r1, fp
	mov	r0, #0
.L111:
	sub	r3, r4, #49
	mov	r2, r3, asl #24
	and	r3, r3, #255
	cmp	r3, #8
	mov	r2, r2, asr #24
	bhi	.L107
	mov	r3, r8, asl r2
	bic	r3, r3, #170
	mov	r3, r3, asl #23
	mov	r3, r3, lsr #23
	cmp	r3, #0
	movne	r2, #5
	beq	.L107
.L109:
	sub	r3, r4, #48
	add	r3, r3, r3, lsr #31
	add	r3, r0, r3, asr #1
	add	r3, r3, #48
	strb	r3, [r1, #-1]
	ldrb	r4, [r1], #1	@ zero_extendqisi2
	cmp	r4, #0
	mov	r0, r2
	bne	.L111
	ldrb	r3, [sp, #0]	@ zero_extendqisi2
	cmp	r3, #48
	bne	.L113
	mov	r2, r4
.L112:
	add	r2, r2, #1
	ldrb	r3, [r5, r2]	@ zero_extendqisi2
	cmp	r3, #48
	beq	.L112
	mov	r4, r2
.L113:
	mov	r0, sp
	bl	strlen
	add	r2, r0, #1
	rsb	r2, r4, r2
	add	r6, r6, #1
	mov	r0, sp
	add	r1, r5, r4
	bl	memmove
	cmp	r6, #8
	mov	r7, r7, asl #1
	bne	.L114
	sub	sl, sl, #1
	b	.L103
.L107:
	mov	r2, #0
	b	.L109
.L119:
	mov	r0, #1
	add	sp, sp, #204
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	bx	lr
	.size	stringToBinary, .-stringToBinary
	.align	2
	.global	multiplication
	.type	multiplication, %function
multiplication:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	mov	r3, #0
	mov	r9, r2
	strb	r3, [r9], #1
	mov	r8, r2
	add	r2, r9, #2
	strb	r3, [r8, #1]
	strb	r3, [r9, #1]
	strb	r3, [r2], #1
	sub	sp, sp, #36
	mov	r7, #4
	strb	r3, [r2, #0]
	mov	r4, r3
	strb	r3, [sp, #27]
	strb	r3, [sp, #28]
	strb	r3, [sp, #29]
	strb	r3, [sp, #30]
	strb	r3, [sp, #31]
	strh	r3, [sp, #22]	@ movhi
	strh	r3, [sp, #24]	@ movhi
	strb	r3, [sp, #26]
	add	r3, r8, r7
	str	r3, [sp, #12]
	add	r3, r8, #3
	str	r3, [sp, #8]
	add	r3, r8, #2
	mov	fp, r0
	mov	sl, r1
	add	r5, sp, #27
	mov	r6, #1
	str	r3, [sp, #4]
	b	.L121
.L123:
	cmp	r7, #0
	beq	.L161
.L154:
	mov	r3, r6, asl #17
	mov	r6, r3, lsr #16
	cmp	r6, #128
	subhi	r7, r7, #1
	movhi	r6, #1
	add	r4, r4, #1
.L121:
	ldrb	r3, [sl, r7]	@ zero_extendqisi2
	tst	r3, r6
	beq	.L123
	mov	r0, r5
	mov	r1, fp
	mov	r2, #5
	bl	memcpy
	cmp	r4, #0
	beq	.L124
	mov	r0, #0
.L130:
	mov	r1, #0
	ldrb	r2, [r5, r1]	@ zero_extendqisi2
	cmp	r2, #0
	mov	r3, r1
	beq	.L125
	tst	r2, #128
	bne	.L126
.L162:
	tst	r2, #64
	add	r3, r3, #1
	bne	.L126
	tst	r2, #32
	add	r3, r3, #1
	bne	.L126
	tst	r2, #16
	add	r3, r3, #1
	bne	.L126
	tst	r2, #8
	add	r3, r3, #1
	bne	.L126
	tst	r2, #4
	add	r3, r3, #1
	bne	.L126
	tst	r2, #2
	add	r3, r3, #1
	bne	.L126
	tst	r2, #1
	add	r3, r3, #1
	bne	.L126
	add	r3, r3, #1
.L125:
	add	r1, r1, #1
	cmp	r1, #5
	beq	.L127
	ldrb	r2, [r5, r1]	@ zero_extendqisi2
	cmp	r2, #0
	add	r3, r3, #8
	beq	.L125
	tst	r2, #128
	beq	.L162
.L126:
	mov	r2, r3, lsr #3
	sub	r3, r2, #1
	cmp	r3, #3
	bhi	.L127
	add	r3, r5, r2
	ldrb	r1, [r3, #-1]	@ zero_extendqisi2
	mov	r2, r3
.L129:
	mov	r3, r1, asl #1
	ldrb	r1, [r2, #0]	@ zero_extendqisi2
	and	r3, r3, #255
	orr	r3, r3, r1, lsr #7
	strb	r3, [r2, #-1]
	add	r2, r2, #1
	add	r3, sp, #32
	cmp	r2, r3
	bne	.L129
.L127:
	ldrb	r3, [sp, #31]	@ zero_extendqisi2
	add	r0, r0, #1
	mov	r3, r3, asl #1
	cmp	r0, r4
	strb	r3, [sp, #31]
	bcc	.L130
.L124:
	ldr	r3, [sp, #12]
	ldrb	r1, [r3, #0]	@ zero_extendqisi2
	mov	r3, #0	@ movhi
	cmp	r1, #255
	strh	r3, [sp, #22]	@ movhi
	strh	r3, [sp, #24]	@ movhi
	strb	r3, [sp, #26]
	ldrneb	r0, [sp, #31]	@ zero_extendqisi2
	mov	r3, r1
	beq	.L163
.L158:
	ldrb	r2, [sp, #26]	@ zero_extendqisi2
.L133:
	add	r3, r2, r3
	add	r3, r0, r3
	and	r3, r3, #255
	cmp	r1, r3
	strb	r3, [sp, #26]
	bhi	.L136
	cmp	r0, r3
	bls	.L135
.L136:
	ldrb	r3, [sp, #25]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [sp, #25]
.L135:
	ldr	r3, [sp, #8]
	ldrb	r1, [r3, #0]	@ zero_extendqisi2
	cmp	r1, #255
	mov	r3, r1
	ldrneb	r0, [sp, #30]	@ zero_extendqisi2
	beq	.L164
.L159:
	ldrb	r2, [sp, #25]	@ zero_extendqisi2
.L139:
	add	r3, r2, r3
	add	r3, r0, r3
	and	r3, r3, #255
	cmp	r1, r3
	strb	r3, [sp, #25]
	bhi	.L142
	cmp	r0, r3
	bls	.L141
.L142:
	ldrb	r3, [sp, #24]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [sp, #24]
.L141:
	ldr	r3, [sp, #4]
	ldrb	r1, [r3, #0]	@ zero_extendqisi2
	cmp	r1, #255
	mov	r3, r1
	ldrneb	r0, [sp, #29]	@ zero_extendqisi2
	beq	.L165
.L160:
	ldrb	r2, [sp, #24]	@ zero_extendqisi2
.L145:
	add	r3, r2, r3
	add	r3, r0, r3
	and	r3, r3, #255
	cmp	r1, r3
	strb	r3, [sp, #24]
	bhi	.L148
	cmp	r0, r3
	bls	.L147
.L148:
	ldrb	r3, [sp, #23]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [sp, #23]
.L147:
	ldrb	r1, [r9, #0]	@ zero_extendqisi2
	cmp	r1, #255
	mov	ip, r1
	beq	.L149
	ldrb	r0, [sp, #28]	@ zero_extendqisi2
	ldrb	r2, [sp, #23]	@ zero_extendqisi2
.L150:
	add	r3, r2, r0
	add	r3, ip, r3
	and	r3, r3, #255
	cmp	r1, r3
	strb	r3, [sp, #23]
	bhi	.L152
	cmp	r0, r3
	bls	.L153
.L152:
	ldrb	r3, [sp, #22]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [sp, #22]
.L153:
	ldrb	ip, [r8, #0]	@ zero_extendqisi2
	ldrb	r3, [sp, #27]	@ zero_extendqisi2
	mov	r0, r8
	add	ip, ip, r3
	add	r1, sp, #22
	mov	r2, #5
	strb	ip, [sp, #22]
	bl	memcpy
	cmp	r7, #0
	bne	.L154
.L161:
	add	sp, sp, #36
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	bx	lr
.L165:
	ldrb	r0, [sp, #29]	@ zero_extendqisi2
	cmp	r0, #255
	bne	.L160
	ldrb	r2, [sp, #24]	@ zero_extendqisi2
	cmp	r2, #1
	ldreqb	r3, [sp, #23]	@ zero_extendqisi2
	addeq	r3, r3, #1
	streqb	r3, [sp, #23]
	moveq	r3, r0
	b	.L145
.L163:
	ldrb	r0, [sp, #31]	@ zero_extendqisi2
	cmp	r0, #255
	bne	.L158
	ldrb	r2, [sp, #26]	@ zero_extendqisi2
	cmp	r2, #1
	ldreqb	r3, [sp, #25]	@ zero_extendqisi2
	addeq	r3, r3, #1
	streqb	r3, [sp, #25]
	moveq	r3, r0
	b	.L133
.L164:
	ldrb	r0, [sp, #30]	@ zero_extendqisi2
	cmp	r0, #255
	bne	.L159
	ldrb	r2, [sp, #25]	@ zero_extendqisi2
	cmp	r2, #1
	ldreqb	r3, [sp, #24]	@ zero_extendqisi2
	addeq	r3, r3, #1
	streqb	r3, [sp, #24]
	moveq	r3, r0
	b	.L139
.L149:
	ldrb	r0, [sp, #28]	@ zero_extendqisi2
	cmp	r0, #255
	ldrneb	r2, [sp, #23]	@ zero_extendqisi2
	bne	.L150
	ldrb	r2, [sp, #23]	@ zero_extendqisi2
	cmp	r2, #1
	ldreqb	r3, [sp, #22]	@ zero_extendqisi2
	addeq	r3, r3, #1
	streqb	r3, [sp, #22]
	moveq	ip, r0
	b	.L150
	.size	multiplication, .-multiplication
	.align	2
	.global	division
	.type	division, %function
division:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	mov	r3, r2
	sub	sp, sp, #44
	mov	r4, #0
	str	r2, [sp, #8]
	strb	r4, [r3], #1
	add	r3, r3, #1
	strb	r4, [r2, #1]
	strb	r4, [r3], #1
	strb	r4, [r3], #1
	add	r2, sp, #35
	str	r2, [sp, #4]
	mov	r9, r1
	strb	r4, [r3, #0]
	mov	r1, r0
	mov	r2, #5
	add	r0, sp, #35
	str	r4, [sp, #16]
	strb	r4, [sp, #35]
	strb	r4, [sp, #36]
	strb	r4, [sp, #37]
	strb	r4, [sp, #38]
	strb	r4, [sp, #39]
	bl	memcpy
	ldr	sl, [sp, #16]
	mov	r3, #128
	strh	r4, [sp, #30]	@ movhi
	strh	r4, [sp, #32]	@ movhi
	strb	r4, [sp, #34]
	strb	r4, [sp, #25]
	strb	r4, [sp, #26]
	strb	r4, [sp, #27]
	strb	r4, [sp, #28]
	strb	r4, [sp, #29]
	str	r3, [sp, #20]
	str	sl, [sp, #12]
	add	r8, sp, #30
.L167:
	cmp	r3, #0
	ldrne	lr, [sp, #12]
	rsbne	r3, lr, #5
	movne	r3, r3, asl #3
	ldreqb	ip, [r9, #0]	@ zero_extendqisi2
	subne	fp, r3, #1
	beq	.L174
.L176:
	mov	r0, r8
	add	r1, sp, #35
	mov	r2, #5
	bl	memcpy
	ldr	lr, [sp, #16]
	subs	sl, fp, lr
	beq	.L168
	mov	lr, #0
.L169:
	ldrb	ip, [sp, #30]	@ zero_extendqisi2
	ldrb	r3, [sp, #31]	@ zero_extendqisi2
	ldrb	r2, [sp, #32]	@ zero_extendqisi2
	ldrb	r1, [sp, #33]	@ zero_extendqisi2
	ldrb	r0, [sp, #34]	@ zero_extendqisi2
	and	r4, ip, #1
	and	r5, r3, #1
	and	r6, r2, #1
	and	r7, r1, #1
	mov	r0, r0, lsr #1
	add	lr, lr, #1
	mov	r3, r3, lsr #1
	mov	r2, r2, lsr #1
	mov	r1, r1, lsr #1
	orr	r3, r3, r4, asl #7
	orr	r2, r2, r5, asl #7
	orr	r1, r1, r6, asl #7
	orr	r0, r0, r7, asl #7
	mov	ip, ip, lsr #1
	cmp	sl, lr
	strb	ip, [sp, #30]
	strb	r3, [sp, #31]
	strb	r2, [sp, #32]
	strb	r1, [sp, #33]
	strb	r0, [sp, #34]
	bhi	.L169
.L168:
	ldrb	ip, [r9, #0]	@ zero_extendqisi2
	mov	r2, #128
	mov	r0, ip
	mov	r1, #0
.L212:
	tst	r0, r2
	bne	.L219
	ldrb	r3, [r8, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L172
.L174:
	ldr	r4, [sp, #20]
	mov	r0, ip
	mov	r2, #128
	mov	r1, #0
.L213:
	tst	r0, r2
	bne	.L220
	ldrb	r3, [r8, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L179
.L181:
	ldr	r1, [sp, #8]
	ldr	r0, [sp, #12]
	ldr	r2, [sp, #20]
	ldrb	r3, [r1, r0]	@ zero_extendqisi2
	orr	r3, r2, r3
	strb	r3, [r1, r0]
	mov	r2, #5
	mov	r0, r8
	mov	r1, r9
	bl	memcpy
	cmp	sl, #0
	movne	r0, #0
	beq	.L199
.L188:
	mov	r1, #0
	ldrb	r2, [r8, r1]	@ zero_extendqisi2
	cmp	r2, #0
	mov	r3, r1
	beq	.L183
	tst	r2, #128
	bne	.L184
.L221:
	tst	r2, #64
	add	r3, r3, #1
	bne	.L184
	tst	r2, #32
	add	r3, r3, #1
	bne	.L184
	tst	r2, #16
	add	r3, r3, #1
	bne	.L184
	tst	r2, #8
	add	r3, r3, #1
	bne	.L184
	tst	r2, #4
	add	r3, r3, #1
	bne	.L184
	tst	r2, #2
	add	r3, r3, #1
	bne	.L184
	tst	r2, #1
	add	r3, r3, #1
	bne	.L184
	add	r3, r3, #1
.L183:
	add	r1, r1, #1
	cmp	r1, #5
	beq	.L185
	ldrb	r2, [r8, r1]	@ zero_extendqisi2
	cmp	r2, #0
	add	r3, r3, #8
	beq	.L183
	tst	r2, #128
	beq	.L221
.L184:
	mov	r2, r3, lsr #3
	sub	r3, r2, #1
	cmp	r3, #3
	bhi	.L185
	add	r3, r8, r2
	ldrb	r1, [r3, #-1]	@ zero_extendqisi2
	mov	r2, r3
.L187:
	mov	r3, r1, asl #1
	ldrb	r1, [r2, #0]	@ zero_extendqisi2
	and	r3, r3, #255
	orr	r3, r3, r1, lsr #7
	strb	r3, [r2, #-1]
	ldr	r3, [sp, #4]
	add	r2, r2, #1
	cmp	r2, r3
	bne	.L187
.L185:
	ldrb	r3, [sp, #34]	@ zero_extendqisi2
	add	r0, r0, #1
	mov	r3, r3, asl #1
	cmp	sl, r0
	strb	r3, [sp, #34]
	bhi	.L188
.L199:
	mov	lr, #0
	strb	lr, [sp, #25]
	strb	lr, [sp, #26]
	strb	lr, [sp, #27]
	strb	lr, [sp, #28]
	strb	lr, [sp, #29]
	ldrb	ip, [sp, #39]	@ zero_extendqisi2
	mov	r1, #4
	mov	r2, #1
	mov	r0, #0
	b	.L214
.L190:
	ldrb	r3, [r8, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L194
	cmp	r0, #0
	bne	.L192
	add	r0, sp, #25
	ldrb	r3, [r0, r1]	@ zero_extendqisi2
	orr	r3, r3, r2
	strb	r3, [r0, r1]
	mov	r0, #1
.L192:
	cmp	r1, #0
	beq	.L222
.L195:
	mov	r2, r2, asl #1
	cmp	r2, #128
	addhi	r2, sp, #35
	subhi	r1, r1, #1
	ldrhib	ip, [r2, r1]	@ zero_extendqisi2
	movhi	r2, #1
.L214:
	tst	ip, r2
	beq	.L190
	ldrb	r3, [r8, r1]	@ zero_extendqisi2
	ands	r3, r3, r2
	bne	.L194
	cmp	r0, #0
	movne	r0, r3
	bne	.L192
.L217:
	add	lr, sp, #25
	ldrb	r3, [lr, r1]	@ zero_extendqisi2
	cmp	r1, #0
	orr	r3, r3, r2
	strb	r3, [lr, r1]
	bne	.L195
.L222:
	add	r0, sp, #35
	add	r1, sp, #25
	mov	r2, #5
	bl	memcpy
.L180:
	ldr	r0, [sp, #20]
	cmp	r0, #0
	ldreq	r1, [sp, #12]
	addeq	r1, r1, #1
	streq	r1, [sp, #12]
	ldr	r2, [sp, #12]
	streq	r0, [sp, #16]
	moveq	r4, #128
	cmp	r2, #4
	bhi	.L200
	str	r4, [sp, #20]
	mov	r3, r4
	b	.L167
.L219:
	ldrb	r3, [r8, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L223
.L172:
	cmp	r1, #4
	bhi	.L174
	movs	r2, r2, lsr #1
	addeq	r1, r1, #1
	ldreqb	r0, [r9, r1]	@ zero_extendqisi2
	moveq	r2, #128
	b	.L212
.L220:
	ldrb	r3, [r8, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L180
.L179:
	cmp	r1, #4
	bhi	.L181
	movs	r2, r2, lsr #1
	addeq	r1, r1, #1
	ldreqb	r0, [r9, r1]	@ zero_extendqisi2
	moveq	r2, #128
	b	.L213
.L223:
	add	r0, sp, #16
	ldmia	r0, {r0, r1}	@ phole ldm
	add	r3, r0, #1
	mov	r2, r1, asl #15
	mov	r3, r3, asl #16
	movs	r2, r2, lsr #16
	mov	r3, r3, lsr #16
	str	r2, [sp, #20]
	str	r3, [sp, #16]
	bne	.L176
	b	.L174
.L194:
	cmp	r0, #0
	beq	.L192
	b	.L217
.L200:
	add	sp, sp, #44
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	bx	lr
	.size	division, .-division
	.align	2
	.global	encrypt_decrypt
	.type	encrypt_decrypt, %function
encrypt_decrypt:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 120
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	mov	r4, #0
	sub	sp, sp, #124
	str	r3, [sp, #20]
	strb	r4, [r3], #1
	ldr	ip, [sp, #20]
	str	r3, [sp, #16]
	strb	r4, [ip, #1]
	ldr	ip, [sp, #16]
	add	r3, r3, #2
	strb	r4, [ip, #1]
	strb	r4, [r3], #1
	str	r2, [sp, #24]
	strb	r4, [r3, #0]
	mov	sl, r0
	str	r1, [sp, #28]
	mov	r2, #5
	ldr	r1, [sp, #24]
	add	r0, sp, #115
	strb	r4, [sp, #115]
	strb	r4, [sp, #116]
	strb	r4, [sp, #117]
	strb	r4, [sp, #118]
	strb	r4, [sp, #119]
	bl	memcpy
	ldrb	r5, [sp, #115]	@ zero_extendqisi2
	ldrb	r3, [sp, #116]	@ zero_extendqisi2
	ldrb	r2, [sp, #117]	@ zero_extendqisi2
	ldrb	ip, [sp, #118]	@ zero_extendqisi2
	ldrb	r6, [sp, #119]	@ zero_extendqisi2
	and	r1, r5, #1
	and	r0, r3, #1
	and	r7, r2, #1
	and	r8, ip, #1
	mov	r6, r6, lsr #1
	mov	r3, r3, lsr #1
	mov	r2, r2, lsr #1
	mov	ip, ip, lsr #1
	orr	ip, ip, r7, asl #7
	orr	r3, r3, r1, asl #7
	orr	r2, r2, r0, asl #7
	orr	r6, r6, r8, asl #7
	mov	r5, r5, lsr #1
	ldr	r1, .L340
	ldr	r0, .L340+4
	strb	ip, [sp, #118]
	strb	r3, [sp, #116]
	strb	r5, [sp, #115]
	strb	r2, [sp, #117]
	strb	r6, [sp, #119]
	bl	fopen
	add	r7, sp, #54
	mov	r1, r4
	mov	r2, #30
	mov	r9, r0
	mov	r0, r7
	bl	memset
	add	r6, sp, #110
	mvn	r3, #0
	ldr	r2, .L340+8
	mov	r0, r7
	mov	r1, #30
	bl	snprintf
	add	r5, sp, #105
	mov	r0, r7
	mov	r1, r6
	strh	r4, [sp, #110]	@ movhi
	strh	r4, [sp, #112]	@ movhi
	strb	r4, [sp, #114]
	add	r7, sp, #100
	bl	stringToBinary
	mov	r1, sl
	mov	r2, #5
	mov	r0, r5
	strb	r4, [sp, #105]
	strb	r4, [sp, #106]
	strb	r4, [sp, #107]
	strb	r4, [sp, #108]
	strb	r4, [sp, #109]
	bl	memcpy
	ldr	r0, .L340+12
	mov	r1, r7
	str	r4, [sp, #100]
	strb	r4, [sp, #104]
	bl	stringToBinary
	mov	r3, r4
.L228:
	ldr	r0, [sp, #28]
	ldrb	r2, [r0, r4]	@ zero_extendqisi2
	cmp	r2, #0
	beq	.L225
	tst	r2, #128
	bne	.L226
	tst	r2, #64
	add	r3, r3, #1
	bne	.L226
	tst	r2, #32
	add	r3, r3, #1
	bne	.L226
	tst	r2, #16
	add	r3, r3, #1
	bne	.L226
	tst	r2, #8
	add	r3, r3, #1
	bne	.L226
	tst	r2, #4
	add	r3, r3, #1
	bne	.L226
	tst	r2, #2
	add	r3, r3, #1
	bne	.L226
	tst	r2, #1
	add	r3, r3, #1
	bne	.L226
	add	r3, r3, #1
.L225:
	add	r4, r4, #1
	cmp	r4, #5
	addne	r3, r3, #8
	bne	.L228
.L227:
	mov	r0, r9
	bl	fclose
	add	sp, sp, #124
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	bx	lr
.L226:
	rsbs	r3, r3, #40
	str	r3, [sp, #40]
	beq	.L227
	ldr	r1, [sp, #16]
	add	r1, r1, #1
	add	r3, r1, #1
	mov	ip, #1
	mov	r4, #4
	add	r0, r3, ip
	mov	r2, #0
	str	r4, [sp, #32]
	str	ip, [sp, #36]
	str	r0, [sp, #4]
	str	r1, [sp, #12]
	str	r2, [sp, #44]
	str	r3, [sp, #8]
	ldr	ip, [sp, #28]
	ldr	r4, [sp, #32]
	ldr	r0, [sp, #36]
	ldrb	r3, [ip, r4]	@ zero_extendqisi2
	tst	r3, r0
	add	sl, sp, #84
	mov	r8, r2
	bne	.L329
.L230:
	ldrb	r0, [sp, #105]	@ zero_extendqisi2
	mov	r2, #128
	mov	r1, #0
.L312:
	tst	r0, r2
	bne	.L330
	add	r4, sp, #115
	ldrb	r3, [r4, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L240
.L242:
	mov	r1, #0
	mov	r2, r1
	mov	r0, r9
	bl	fseek
	mov	r2, #128
	mov	r1, #0
.L316:
	cmp	r1, #4
	bhi	.L293
	cmp	r2, #0
	addeq	r1, r1, #1
	ldrb	r3, [r6, r1]	@ zero_extendqisi2
	addeq	r2, r2, #128
	tst	r3, r2
	bne	.L331
.L290:
	ldrb	r3, [r5, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L291
.L293:
	str	r8, [r7, #0]
	strb	r8, [r7, #4]
	ldrb	r0, [sp, #109]	@ zero_extendqisi2
	mov	r4, #4
	mov	r2, #1
	mov	r1, r8
	b	.L315
.L283:
	ldrb	r3, [r6, r4]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L287
	cmp	r1, #0
	ldreqb	r3, [r7, r4]	@ zero_extendqisi2
	orreq	r3, r3, r2
	streqb	r3, [r7, r4]
	addeq	r1, r1, #1
.L285:
	cmp	r4, #0
	beq	.L332
.L288:
	mov	r2, r2, asl #1
	cmp	r2, #128
	subhi	r4, r4, #1
	ldrhib	r0, [r5, r4]	@ zero_extendqisi2
	movhi	r2, #1
.L315:
	tst	r0, r2
	beq	.L283
	ldrb	r3, [r6, r4]	@ zero_extendqisi2
	ands	r3, r3, r2
	bne	.L287
	cmp	r1, #0
	movne	r1, r3
	bne	.L285
.L324:
	ldrb	r3, [r7, r4]	@ zero_extendqisi2
	cmp	r4, #0
	orr	r3, r3, r2
	strb	r3, [r7, r4]
	bne	.L288
.L332:
	mov	r1, r7
	mov	r2, #5
	mov	r0, r5
	bl	memcpy
	mvn	r1, #0
	mov	r2, #1
	mov	r0, r9
	bl	fseek
	mvn	r1, #0
	mov	r2, #1
	mov	r0, r9
	bl	fseek
	mov	r1, r4
	ldrb	r3, [r6, r1]	@ zero_extendqisi2
	mov	r2, #128
	tst	r3, r2
	beq	.L290
.L331:
	ldrb	r3, [r5, r1]	@ zero_extendqisi2
	ands	r3, r3, r2
	beq	.L333
.L291:
	mov	r2, r2, lsr #1
	b	.L316
.L287:
	cmp	r1, #0
	beq	.L285
	b	.L324
.L330:
	add	ip, sp, #115
	ldrb	r3, [ip, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L241
.L240:
	cmp	r1, #4
	bhi	.L241
	movs	r2, r2, lsr #1
	addeq	r1, r1, #1
	ldreqb	r0, [r5, r1]	@ zero_extendqisi2
	moveq	r2, #128
	b	.L312
.L333:
	mov	r1, r5
	mov	r2, #5
	mov	r0, sl
	strb	r3, [sp, #88]
	str	r3, [sp, #84]
	bl	memcpy
	ldrb	r2, [sp, #109]	@ zero_extendqisi2
	ldrb	r1, [sp, #108]	@ zero_extendqisi2
	ldrb	r3, [sp, #107]	@ zero_extendqisi2
	ldrb	r0, [sp, #106]	@ zero_extendqisi2
	strb	r2, [sp, #84]
	strb	r3, [sp, #86]
	strb	r1, [sp, #85]
	strb	r0, [sp, #87]
	ldr	r3, .L340+16
	ldr	r1, [sl, #0]
	ldrb	r2, [sp, #105]	@ zero_extendqisi2
	cmp	r1, r3
	strb	r2, [sp, #88]
	movls	r1, r1, asl #1
	movls	r0, r9
	movls	r2, #1
	blls	fseek
.L295:
	ldr	r3, [sp, #44]
	add	r3, r3, #1
	str	r3, [sp, #44]
	add	r0, sp, #108
	mov	r1, #2
	mov	r2, #1
	mov	r3, r9
	bl	fread
	add	r4, sp, #40
	ldmia	r4, {r4, ip}	@ phole ldm
	ldr	r0, [sp, #32]
	cmp	r4, ip
	cmpne	r0, #0
	beq	.L227
	ldr	r1, [sp, #36]
	mov	r3, r1, asl #17
	mov	r3, r3, lsr #16
	cmp	r3, #128
	ldrhi	r2, [sp, #32]
	subhi	r2, r2, #1
	strhi	r2, [sp, #32]
	str	r3, [sp, #36]
	movhi	r3, #1
	strhi	r3, [sp, #36]
	ldr	ip, [sp, #28]
	ldr	r4, [sp, #32]
	ldr	r0, [sp, #36]
	ldrb	r3, [ip, r4]	@ zero_extendqisi2
	tst	r3, r0
	beq	.L230
.L329:
	add	r4, sp, #90
	mov	r0, r5
	mov	r1, r7
	mov	r2, sl
	str	r8, [sp, #84]
	strb	r8, [sp, #88]
	add	fp, sp, #95
	bl	multiplication
	mov	r2, r4
	mov	r0, sl
	ldr	r1, [sp, #24]
	strh	r8, [sp, #90]	@ movhi
	strh	r8, [sp, #92]	@ movhi
	strb	r8, [sp, #94]
	bl	division
	mov	r1, r4
	ldr	r0, [sp, #24]
	mov	r2, fp
	strb	r8, [sp, #95]
	strb	r8, [sp, #96]
	strb	r8, [sp, #97]
	strb	r8, [sp, #98]
	strb	r8, [sp, #99]
	bl	multiplication
	ldr	r1, [sp, #20]
	strb	r8, [r1, #0]
	ldr	r2, [sp, #16]
	strb	r8, [r2, #0]
	ldr	r3, [sp, #12]
	strb	r8, [r3, #0]
	ldr	r4, [sp, #8]
	strb	r8, [r4, #0]
	ldr	ip, [sp, #4]
	mov	r1, #4
	strb	r8, [ip, #0]
	mov	r2, #1
	mov	r0, r8
	b	.L311
.L232:
	ldrb	r3, [fp, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L236
	cmp	r0, #0
	bne	.L234
	ldr	r0, [sp, #20]
	ldrb	r3, [r0, r1]	@ zero_extendqisi2
	orr	r3, r3, r2
	strb	r3, [r0, r1]
	mov	r0, #1
.L234:
	cmp	r1, #0
	beq	.L334
.L237:
	mov	r2, r2, asl #1
	cmp	r2, #128
	subhi	r1, r1, #1
	movhi	r2, #1
.L311:
	ldrb	r3, [sl, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L232
	ldrb	r3, [fp, r1]	@ zero_extendqisi2
	ands	r3, r3, r2
	bne	.L236
	cmp	r0, #0
	ldreq	ip, [sp, #20]
	ldreqb	r3, [ip, r1]	@ zero_extendqisi2
	orreq	r3, r3, r2
	movne	r0, r3
	streqb	r3, [ip, r1]
	cmp	r1, #0
	bne	.L237
.L334:
	mov	r0, r7
	ldr	r1, [sp, #20]
	mov	r2, #5
	bl	memcpy
	b	.L230
.L236:
	cmp	r0, #0
	ldrne	r4, [sp, #20]
	ldrneb	r3, [r4, r1]	@ zero_extendqisi2
	orrne	r3, r3, r2
	strneb	r3, [r4, r1]
	b	.L234
.L241:
	mov	ip, #0	@ movhi
	add	r1, sp, #90
	ldr	r0, .L340+12
	strh	ip, [sp, #90]	@ movhi
	strh	ip, [sp, #92]	@ movhi
	strb	r8, [sp, #95]
	strb	r8, [sp, #96]
	strb	r8, [sp, #97]
	strb	r8, [sp, #98]
	strb	r8, [sp, #99]
	strb	r8, [sp, #94]
	str	r8, [sp, #84]
	strb	r8, [sp, #88]
	bl	stringToBinary
	strb	r8, [sp, #95]
	strb	r8, [sp, #96]
	strb	r8, [sp, #97]
	strb	r8, [sp, #98]
	strb	r8, [sp, #99]
	add	lr, sp, #95
	ldrb	ip, [sp, #109]	@ zero_extendqisi2
	mov	r1, #4
	mov	r2, #1
	mov	r0, r8
	b	.L313
.L245:
	add	r4, sp, #115
	ldrb	r3, [r4, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L249
	cmp	r0, #0
	ldreqb	r3, [lr, r1]	@ zero_extendqisi2
	orreq	r3, r3, r2
	streqb	r3, [lr, r1]
	addeq	r0, r0, #1
.L247:
	cmp	r1, #0
	beq	.L335
.L250:
	mov	r2, r2, asl #1
	cmp	r2, #128
	subhi	r1, r1, #1
	ldrhib	ip, [r5, r1]	@ zero_extendqisi2
	movhi	r2, #1
.L313:
	tst	ip, r2
	beq	.L245
	add	r4, sp, #115
	ldrb	r3, [r4, r1]	@ zero_extendqisi2
	ands	r3, r3, r2
	bne	.L249
	cmp	r0, #0
	movne	r0, r3
	bne	.L247
.L319:
	ldrb	r3, [lr, r1]	@ zero_extendqisi2
	cmp	r1, #0
	orr	r3, r3, r2
	strb	r3, [lr, r1]
	bne	.L250
.L335:
	str	r1, [sl, #0]
	strb	r1, [sl, #4]
	mov	r0, r1
	ldrb	ip, [sp, #119]	@ zero_extendqisi2
	add	r1, r1, #4
	mov	r2, #1
	b	.L314
.L252:
	ldrb	r3, [lr, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L256
	cmp	r0, #0
	ldreqb	r3, [sl, r1]	@ zero_extendqisi2
	orreq	r3, r3, r2
	streqb	r3, [sl, r1]
	addeq	r0, r0, #1
.L254:
	cmp	r1, #0
	beq	.L336
.L257:
	mov	r2, r2, asl #1
	cmp	r2, #128
	addhi	r2, sp, #115
	subhi	r1, r1, #1
	ldrhib	ip, [r2, r1]	@ zero_extendqisi2
	movhi	r2, #1
.L314:
	tst	ip, r2
	beq	.L252
	ldrb	r3, [lr, r1]	@ zero_extendqisi2
	ands	r3, r3, r2
	bne	.L256
	cmp	r0, #0
	movne	r0, r3
	bne	.L254
.L320:
	ldrb	r3, [sl, r1]	@ zero_extendqisi2
	cmp	r1, #0
	orr	r3, r3, r2
	strb	r3, [sl, r1]
	bne	.L257
.L336:
	ldrb	r0, [sp, #88]	@ zero_extendqisi2
	cmp	r0, #255
	strb	r1, [sp, #109]
	strb	r1, [r5, #0]
	strb	r1, [sp, #106]
	strb	r1, [sp, #107]
	strb	r1, [sp, #108]
	ldrneb	r1, [sp, #94]	@ zero_extendqisi2
	beq	.L337
.L321:
	ldrb	r2, [sp, #109]	@ zero_extendqisi2
.L260:
	add	r3, r2, r1
	add	r3, r0, r3
	and	r3, r3, #255
	cmp	r3, r0
	strb	r3, [sp, #109]
	bcc	.L263
	cmp	r1, r3
	bls	.L262
.L263:
	ldrb	r3, [sp, #108]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [sp, #108]
.L262:
	ldrb	r0, [sp, #87]	@ zero_extendqisi2
	cmp	r0, #255
	ldrneb	r1, [sp, #93]	@ zero_extendqisi2
	beq	.L338
.L322:
	ldrb	r2, [sp, #108]	@ zero_extendqisi2
.L266:
	add	r3, r1, r2
	add	r3, r0, r3
	and	r3, r3, #255
	cmp	r0, r3
	strb	r3, [sp, #108]
	bhi	.L269
	cmp	r1, r3
	bls	.L268
.L269:
	ldrb	r3, [sp, #107]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [sp, #107]
.L268:
	ldrb	r0, [sp, #86]	@ zero_extendqisi2
	cmp	r0, #255
	ldrneb	r1, [sp, #92]	@ zero_extendqisi2
	beq	.L339
.L323:
	ldrb	r2, [sp, #107]	@ zero_extendqisi2
.L272:
	add	r3, r1, r2
	add	r3, r0, r3
	and	r3, r3, #255
	cmp	r0, r3
	strb	r3, [sp, #107]
	bhi	.L275
	cmp	r1, r3
	bls	.L274
.L275:
	ldrb	r3, [sp, #106]	@ zero_extendqisi2
	add	r3, r3, #1
	strb	r3, [sp, #106]
.L274:
	ldrb	r0, [sp, #85]	@ zero_extendqisi2
	cmp	r0, #255
	beq	.L276
	ldrb	r1, [sp, #91]	@ zero_extendqisi2
	ldrb	r2, [sp, #106]	@ zero_extendqisi2
.L277:
	add	r3, r2, r1
	add	r3, r0, r3
	and	r3, r3, #255
	strb	r3, [sp, #106]
	ldrb	r2, [sp, #84]	@ zero_extendqisi2
	ldrb	r3, [sp, #90]	@ zero_extendqisi2
	add	r3, r3, r2
	strb	r3, [sp, #105]
	b	.L242
.L249:
	cmp	r0, #0
	beq	.L247
	b	.L319
.L256:
	cmp	r0, #0
	beq	.L254
	b	.L320
.L338:
	ldrb	r1, [sp, #93]	@ zero_extendqisi2
	cmp	r1, #255
	bne	.L322
	ldrb	r2, [sp, #108]	@ zero_extendqisi2
	cmp	r2, #1
	ldreqb	r3, [sp, #107]	@ zero_extendqisi2
	addeq	r3, r3, #1
	streqb	r3, [sp, #107]
	b	.L266
.L339:
	ldrb	r1, [sp, #92]	@ zero_extendqisi2
	cmp	r1, #255
	bne	.L323
	ldrb	r2, [sp, #107]	@ zero_extendqisi2
	cmp	r2, #1
	ldreqb	r3, [sp, #106]	@ zero_extendqisi2
	addeq	r3, r3, #1
	streqb	r3, [sp, #106]
	b	.L272
.L337:
	ldrb	r1, [sp, #94]	@ zero_extendqisi2
	cmp	r1, #255
	bne	.L321
	ldrb	r2, [sp, #109]	@ zero_extendqisi2
	cmp	r2, #1
	moveq	r3, r2
	addeq	r3, r3, #1
	streqb	r3, [sp, #108]
	b	.L260
.L276:
	ldrb	r1, [sp, #91]	@ zero_extendqisi2
	cmp	r1, #255
	ldrneb	r2, [sp, #106]	@ zero_extendqisi2
	bne	.L277
	ldrb	r2, [sp, #106]	@ zero_extendqisi2
	cmp	r2, #1
	ldreqb	r3, [sp, #105]	@ zero_extendqisi2
	addeq	r3, r3, #1
	streqb	r3, [sp, #105]
	b	.L277
.L341:
	.align	2
.L340:
	.word	.LC2
	.word	.LC1
	.word	.LC3
	.word	.LC4
	.word	858993458
	.size	encrypt_decrypt, .-encrypt_decrypt
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 1048
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	sub	sp, sp, #1040
	sub	sp, sp, #12
	add	r4, sp, #24
	add	r0, sp, #1016
	sub	r4, r4, #7
	ldr	r1, .L372
	mov	r2, #6
	add	r0, r0, #1
	bl	memcpy
	mov	r1, #0
	mov	r2, #1000
	mov	r0, r4
	bl	memset
	ldr	r1, .L372+4
	mov	r2, #5
	mov	r0, r4
	bl	memcpy
	add	r0, sp, #24
	mov	r1, #0
	mov	r2, #20
	sub	r0, r0, #2
	bl	memset
	add	r0, sp, #44
	ldr	r1, .L372+8
	mov	r2, #6
	sub	r0, r0, #2
	bl	memcpy
	mov	r1, #0
	mov	r2, #19
	add	r0, sp, #48
	bl	memset
	add	r0, sp, #68
	ldr	r1, .L372+12
	mov	r2, #4
	sub	r0, r0, #1
	bl	memcpy
	add	r0, sp, #72
	mov	r1, #0
	mov	r2, #21
	sub	r0, r0, #1
	bl	memset
	ldr	r1, .L372+16
	mov	r2, #6
	add	r0, sp, #92
	bl	memcpy
	add	r0, sp, #100
	mov	r1, #0
	mov	r2, #19
	sub	r0, r0, #2
	bl	memset
	add	r0, sp, #120
	ldr	r1, .L372+20
	mov	r2, #4
	sub	r0, r0, #3
	bl	memcpy
	add	r0, sp, #124
	mov	r1, #0
	mov	r2, #21
	sub	r0, r0, #3
	bl	memset
	add	r0, sp, #144
	ldr	r1, .L372+24
	mov	r2, #5
	sub	r0, r0, #2
	bl	memcpy
	add	r0, sp, #148
	mov	r1, #0
	mov	r2, #20
	sub	r0, r0, #1
	bl	memset
	add	r0, sp, #168
	ldr	r1, .L372+28
	mov	r2, #5
	sub	r0, r0, #1
	bl	memcpy
	mov	r1, #0
	mov	r2, #20
	add	r0, sp, #172
	bl	memset
	ldr	r1, .L372+32
	mov	r2, #6
	add	r0, sp, #192
	bl	memcpy
	add	r0, sp, #200
	mov	r1, #0
	mov	r2, #19
	sub	r0, r0, #2
	bl	memset
	add	r0, sp, #220
	ldr	r1, .L372+36
	mov	r2, #3
	sub	r0, r0, #3
	bl	memcpy
	mov	r1, #0
	mov	r2, #22
	add	r0, sp, #220
	bl	memset
	add	r0, sp, #244
	ldr	r1, .L372+40
	mov	r2, #6
	sub	r0, r0, #2
	bl	memcpy
	mov	r1, #0
	mov	r2, #19
	add	r0, sp, #248
	bl	memset
	add	r0, sp, #268
	ldr	r1, .L372+44
	mov	r2, #5
	sub	r0, r0, #1
	bl	memcpy
	mov	r1, #0
	mov	r2, #20
	add	r0, sp, #272
	bl	memset
	ldr	r1, .L372+48
	mov	r2, #6
	add	r0, sp, #292
	bl	memcpy
	add	r0, sp, #300
	mov	r1, #0
	mov	r2, #19
	sub	r0, r0, #2
	bl	memset
	add	r0, sp, #320
	ldr	r1, .L372+52
	mov	r2, #3
	sub	r0, r0, #3
	bl	memcpy
	mov	r1, #0
	mov	r2, #22
	add	r0, sp, #320
	bl	memset
	add	r0, sp, #344
	ldr	r1, .L372+56
	mov	r2, #7
	sub	r0, r0, #2
	bl	memcpy
	add	r0, sp, #352
	mov	r1, #0
	mov	r2, #18
	sub	r0, r0, #3
	bl	memset
	add	r0, sp, #368
	ldr	r1, .L372+60
	mov	r2, #6
	sub	r0, r0, #1
	bl	memcpy
	add	r0, sp, #376
	mov	r1, #0
	mov	r2, #19
	sub	r0, r0, #3
	bl	memset
	ldr	r1, .L372+64
	mov	r2, #6
	add	r0, sp, #392
	bl	memcpy
	add	r0, sp, #400
	mov	r1, #0
	mov	r2, #19
	sub	r0, r0, #2
	bl	memset
	add	r0, sp, #420
	ldr	r1, .L372+68
	mov	r2, #4
	sub	r0, r0, #3
	bl	memcpy
	add	r0, sp, #424
	mov	r1, #0
	mov	r2, #21
	sub	r0, r0, #3
	bl	memset
	add	r0, sp, #444
	ldr	r1, .L372+72
	mov	r2, #5
	sub	r0, r0, #2
	bl	memcpy
	add	r0, sp, #448
	mov	r1, #0
	mov	r2, #20
	sub	r0, r0, #1
	bl	memset
	add	r0, sp, #468
	ldr	r1, .L372+76
	mov	r2, #5
	sub	r0, r0, #1
	bl	memcpy
	mov	r1, #0
	mov	r2, #20
	add	r0, sp, #472
	bl	memset
	ldr	r1, .L372+80
	mov	r2, #6
	add	r0, sp, #492
	bl	memcpy
	add	r0, sp, #500
	mov	r1, #0
	mov	r2, #19
	sub	r0, r0, #2
	bl	memset
	add	r0, sp, #520
	ldr	r1, .L372+84
	mov	r2, #4
	sub	r0, r0, #3
	bl	memcpy
	add	r0, sp, #524
	mov	r1, #0
	mov	r2, #21
	sub	r0, r0, #3
	bl	memset
	add	r0, sp, #544
	ldr	r1, .L372+88
	mov	r2, #5
	sub	r0, r0, #2
	bl	memcpy
	add	r0, sp, #548
	mov	r1, #0
	mov	r2, #20
	sub	r0, r0, #1
	bl	memset
	add	r0, sp, #568
	ldr	r1, .L372+92
	mov	r2, #6
	sub	r0, r0, #1
	bl	memcpy
	add	r0, sp, #576
	mov	r1, #0
	mov	r2, #19
	sub	r0, r0, #3
	bl	memset
	ldr	r1, .L372+96
	mov	r2, #6
	add	r0, sp, #592
	bl	memcpy
	add	r0, sp, #600
	mov	r1, #0
	mov	r2, #19
	sub	r0, r0, #2
	bl	memset
	add	r0, sp, #620
	ldr	r1, .L372+100
	mov	r2, #5
	sub	r0, r0, #3
	bl	memcpy
	add	r0, sp, #624
	mov	r1, #0
	mov	r2, #20
	sub	r0, r0, #2
	bl	memset
	add	r0, sp, #644
	ldr	r1, .L372+104
	mov	r2, #5
	sub	r0, r0, #2
	bl	memcpy
	add	r0, sp, #648
	mov	r1, #0
	mov	r2, #20
	sub	r0, r0, #1
	bl	memset
	add	r0, sp, #668
	ldr	r1, .L372+108
	mov	r2, #5
	sub	r0, r0, #1
	bl	memcpy
	mov	r1, #0
	mov	r2, #20
	add	r0, sp, #672
	bl	memset
	ldr	r1, .L372+112
	mov	r2, #6
	add	r0, sp, #692
	bl	memcpy
	add	r0, sp, #700
	mov	r1, #0
	mov	r2, #19
	sub	r0, r0, #2
	bl	memset
	add	r0, sp, #720
	ldr	r1, .L372+116
	mov	r2, #4
	sub	r0, r0, #3
	bl	memcpy
	add	r0, sp, #724
	mov	r1, #0
	mov	r2, #21
	sub	r0, r0, #3
	bl	memset
	add	r0, sp, #744
	ldr	r1, .L372+120
	mov	r2, #5
	sub	r0, r0, #2
	bl	memcpy
	add	r0, sp, #748
	mov	r1, #0
	mov	r2, #20
	sub	r0, r0, #1
	bl	memset
	add	r0, sp, #768
	ldr	r1, .L372+124
	mov	r2, #6
	sub	r0, r0, #1
	bl	memcpy
	add	r0, sp, #776
	mov	r1, #0
	mov	r2, #19
	sub	r0, r0, #3
	bl	memset
	ldr	r1, .L372+128
	mov	r2, #6
	add	r0, sp, #792
	bl	memcpy
	add	r0, sp, #796
	mov	r1, #0
	mov	r2, #19
	add	r0, r0, #2
	bl	memset
	add	r0, sp, #816
	ldr	r1, .L372+132
	mov	r2, #4
	add	r0, r0, #1
	bl	memcpy
	add	r0, sp, #820
	mov	r1, #0
	mov	r2, #21
	add	r0, r0, #1
	bl	memset
	add	r0, sp, #840
	ldr	r1, .L372+136
	mov	r2, #5
	add	r0, r0, #2
	bl	memcpy
	add	r0, sp, #844
	mov	r1, #0
	mov	r2, #20
	add	r0, r0, #3
	bl	memset
	add	r0, sp, #864
	ldr	r1, .L372+140
	mov	r2, #6
	add	r0, r0, #3
	bl	memcpy
	add	r0, sp, #872
	mov	r1, #0
	mov	r2, #19
	add	r0, r0, #1
	bl	memset
	ldr	r1, .L372+144
	mov	r2, #6
	add	r0, sp, #892
	bl	memcpy
	add	r0, sp, #896
	mov	r1, #0
	mov	r2, #19
	add	r0, r0, #2
	bl	memset
	add	r0, sp, #916
	ldr	r1, .L372+52
	mov	r2, #3
	add	r0, r0, #1
	bl	memcpy
	mov	r1, #0
	mov	r2, #22
	add	r0, sp, #920
	bl	memset
	add	r0, sp, #940
	ldr	r1, .L372+148
	mov	r2, #6
	add	r0, r0, #2
	bl	memcpy
	mov	r1, #0
	mov	r2, #19
	add	r0, sp, #948
	bl	memset
	add	r0, sp, #964
	ldr	r1, .L372+152
	mov	r2, #4
	add	r0, r0, #3
	bl	memcpy
	add	r0, sp, #968
	mov	r1, #0
	mov	r2, #21
	add	r0, r0, #3
	bl	memset
	ldr	r1, .L372+156
	mov	r2, #6
	add	r0, sp, #992
	bl	memcpy
	add	r0, sp, #996
	mov	r2, #19
	add	r0, r0, #2
	mov	r1, #0
	bl	memset
	add	r2, sp, #1024
	add	r3, sp, #1024
	add	r2, r2, #14
	add	r9, sp, #1040
	add	r3, r3, #9
	add	fp, sp, #1020
	mov	sl, #0
	add	r9, r9, #3
	add	fp, fp, #3
	stmia	sp, {r2, r3}	@ phole stm
	mov	r5, sl
	mov	r7, r9
	mov	r8, r2
	mov	r6, fp
.L355:
	mov	r2, sl, asl #2
	mov	r3, sl, asl #4
	add	r4, r2, r3
	str	r3, [sp, #8]
	mov	r3, r4, asl #2
	str	r2, [sp, #12]
	add	r4, r4, r3
	strb	r5, [r9, #0]
	add	r2, sp, #17
	add	r0, r2, r4
	ldr	r2, [sp, #0]
	mov	r3, #0	@ movhi
	strh	r3, [r2, #0]	@ movhi
	ldr	r3, [sp, #4]
	mov	r2, #0	@ movhi
	strb	r5, [r3, #0]
	add	r3, sp, #1024
	strh	r2, [r3, #16]	@ movhi
	strb	r5, [fp, #0]
	mov	r1, r7
	add	r0, r0, #50
	strb	r5, [sp, #1044]
	strb	r5, [sp, #1045]
	strb	r5, [sp, #1046]
	strb	r5, [sp, #1047]
	strb	r5, [sp, #1042]
	strb	r5, [sp, #1034]
	strb	r5, [sp, #1035]
	strb	r5, [sp, #1036]
	strb	r5, [sp, #1037]
	str	r5, [sp, #1028]
	strb	r5, [sp, #1032]
	strb	r5, [sp, #1024]
	strb	r5, [sp, #1025]
	strb	r5, [sp, #1026]
	strb	r5, [sp, #1027]
	bl	stringToBinary
	add	r2, sp, #17
	add	r0, r2, r4
	mov	r1, r8
	add	r0, r0, #75
	bl	stringToBinary
	add	r3, sp, #17
	add	r1, sp, #1024
	add	r0, r3, r4
	add	r1, r1, #9
	bl	stringToBinary
	add	r0, sp, #1016
	add	r1, sp, #1024
	add	r1, r1, #4
	add	r0, r0, #1
	bl	stringToBinary
	add	r2, sp, #1024
	add	r1, sp, #1024
	add	r2, r2, #4
	mov	r3, r6
	add	r1, r1, #9
	mov	r0, r7
	bl	encrypt_decrypt
	ldr	r0, .L372+160
	bl	printf
	ldrb	r1, [sp, #1023]	@ zero_extendqisi2
	ldr	r0, .L372+164
	bl	printf
	ldrb	r1, [sp, #1024]	@ zero_extendqisi2
	ldr	r0, .L372+164
	bl	printf
	ldrb	r1, [sp, #1025]	@ zero_extendqisi2
	ldr	r0, .L372+164
	bl	printf
	ldrb	r1, [sp, #1026]	@ zero_extendqisi2
	ldr	r0, .L372+164
	bl	printf
	ldrb	r1, [sp, #1027]	@ zero_extendqisi2
	ldr	r0, .L372+164
	bl	printf
	mov	r0, #10
	bl	putchar
	add	r2, sp, #1024
	add	r2, r2, #9
	str	r8, [sp, #0]
	ldrb	r0, [sp, #1023]	@ zero_extendqisi2
	str	r2, [sp, #4]
	mov	r9, r7
	mov	fp, r6
	mov	r2, #128
	mov	r1, r5
.L363:
	tst	r0, r2
	bne	.L368
	ldrb	r3, [r8, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L345
.L346:
	ldr	r0, .L372+168
	ldr	r1, .L372+172
	mov	r2, #47
	ldr	r3, .L372+176
	bl	__assert_fail
.L368:
	ldrb	r3, [r8, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L346
.L345:
	cmp	r1, #4
	bhi	.L369
	movs	r2, r2, lsr #1
	addeq	r1, r1, #1
	ldreqb	r0, [r6, r1]	@ zero_extendqisi2
	moveq	r2, #128
	b	.L363
.L369:
	add	r2, sp, #8
	ldmia	r2, {r2, r3}	@ phole ldm
	add	r0, r3, r2
	mov	r3, r0, asl #2
	add	r0, r0, r3
	add	r3, sp, #17
	add	r0, r3, r0
	add	r1, sp, #1024
	add	r1, r1, #9
	add	r0, r0, #25
	bl	stringToBinary
	add	r1, sp, #1024
	add	r2, sp, #1024
	add	r2, r2, #4
	mov	r3, r6
	add	r1, r1, #9
	mov	r0, r8
	bl	encrypt_decrypt
	ldr	r0, .L372+180
	bl	printf
	ldrb	r1, [sp, #1023]	@ zero_extendqisi2
	ldr	r0, .L372+164
	bl	printf
	ldrb	r1, [sp, #1024]	@ zero_extendqisi2
	ldr	r0, .L372+164
	bl	printf
	ldrb	r1, [sp, #1025]	@ zero_extendqisi2
	ldr	r0, .L372+164
	bl	printf
	ldrb	r1, [sp, #1026]	@ zero_extendqisi2
	ldr	r0, .L372+164
	bl	printf
	ldrb	r1, [sp, #1027]	@ zero_extendqisi2
	ldr	r0, .L372+164
	bl	printf
	mov	r0, #10
	bl	putchar
	ldrb	r0, [sp, #1023]	@ zero_extendqisi2
	mov	r2, #128
	mov	r1, #0
.L364:
	tst	r0, r2
	bne	.L370
	ldrb	r3, [r7, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L351
.L352:
	ldr	r0, .L372+184
	ldr	r1, .L372+172
	mov	r2, #54
	ldr	r3, .L372+176
	bl	__assert_fail
.L370:
	ldrb	r3, [r7, r1]	@ zero_extendqisi2
	tst	r3, r2
	beq	.L352
.L351:
	cmp	r1, #4
	bhi	.L371
	movs	r2, r2, lsr #1
	addeq	r1, r1, #1
	ldreqb	r0, [r6, r1]	@ zero_extendqisi2
	moveq	r2, #128
	b	.L364
.L371:
	add	sl, sl, #1
	cmp	sl, #10
	bne	.L355
	ldr	r0, .L372+188
	bl	puts
	add	sp, sp, #28
	add	sp, sp, #1024
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
	bx	lr
.L373:
	.align	2
.L372:
	.word	.LC5
	.word	.LANCHOR0
	.word	.LANCHOR0+28
	.word	.LANCHOR0+56
	.word	.LANCHOR0+84
	.word	.LANCHOR0+112
	.word	.LANCHOR0+140
	.word	.LANCHOR0+168
	.word	.LANCHOR0+196
	.word	.LANCHOR0+224
	.word	.LANCHOR0+252
	.word	.LANCHOR0+280
	.word	.LANCHOR0+308
	.word	.LANCHOR0+336
	.word	.LANCHOR0+364
	.word	.LANCHOR0+392
	.word	.LANCHOR0+420
	.word	.LANCHOR0+448
	.word	.LANCHOR0+476
	.word	.LANCHOR0+504
	.word	.LANCHOR0+532
	.word	.LANCHOR0+560
	.word	.LANCHOR0+588
	.word	.LANCHOR0+616
	.word	.LANCHOR0+644
	.word	.LANCHOR0+672
	.word	.LANCHOR0+700
	.word	.LANCHOR0+728
	.word	.LANCHOR0+756
	.word	.LANCHOR0+784
	.word	.LANCHOR0+812
	.word	.LANCHOR0+840
	.word	.LANCHOR0+868
	.word	.LANCHOR0+896
	.word	.LANCHOR0+924
	.word	.LANCHOR0+952
	.word	.LANCHOR0+980
	.word	.LANCHOR0+1008
	.word	.LANCHOR0+1036
	.word	.LANCHOR0+1064
	.word	.LC45
	.word	.LC0
	.word	.LC46
	.word	.LC47
	.word	.LANCHOR0+1092
	.word	.LC50
	.word	.LC48
	.word	.LC49
	.size	main, .-main
	.section	.rodata
	.align	2
.LANCHOR0 = . + 0
.LC6:
	.ascii	"4861\000"
	.space	20
	.space	3
.LC7:
	.ascii	"15741\000"
	.space	19
	.space	3
.LC8:
	.ascii	"500\000"
	.space	21
	.space	3
.LC9:
	.ascii	"59196\000"
	.space	19
	.space	3
.LC10:
	.ascii	"691\000"
	.space	21
	.space	3
.LC11:
	.ascii	"2411\000"
	.space	20
	.space	3
.LC12:
	.ascii	"6789\000"
	.space	20
	.space	3
.LC13:
	.ascii	"20190\000"
	.space	19
	.space	3
.LC14:
	.ascii	"43\000"
	.space	22
	.space	3
.LC15:
	.ascii	"24907\000"
	.space	19
	.space	3
.LC16:
	.ascii	"3457\000"
	.space	20
	.space	3
.LC17:
	.ascii	"46052\000"
	.space	19
	.space	3
.LC18:
	.ascii	"11\000"
	.space	22
	.space	3
.LC19:
	.ascii	"113591\000"
	.space	18
	.space	3
.LC20:
	.ascii	"25482\000"
	.space	19
	.space	3
.LC21:
	.ascii	"52220\000"
	.space	19
	.space	3
.LC22:
	.ascii	"151\000"
	.space	21
	.space	3
.LC23:
	.ascii	"9851\000"
	.space	20
	.space	3
.LC24:
	.ascii	"9785\000"
	.space	20
	.space	3
.LC25:
	.ascii	"26100\000"
	.space	19
	.space	3
.LC26:
	.ascii	"859\000"
	.space	21
	.space	3
.LC27:
	.ascii	"1039\000"
	.space	20
	.space	3
.LC28:
	.ascii	"12634\000"
	.space	19
	.space	3
.LC29:
	.ascii	"57198\000"
	.space	19
	.space	3
.LC30:
	.ascii	"1081\000"
	.space	20
	.space	3
.LC31:
	.ascii	"1321\000"
	.space	20
	.space	3
.LC32:
	.ascii	"9632\000"
	.space	20
	.space	3
.LC33:
	.ascii	"49821\000"
	.space	19
	.space	3
.LC34:
	.ascii	"219\000"
	.space	21
	.space	3
.LC35:
	.ascii	"7879\000"
	.space	20
	.space	3
.LC36:
	.ascii	"12599\000"
	.space	19
	.space	3
.LC37:
	.ascii	"15771\000"
	.space	19
	.space	3
.LC38:
	.ascii	"467\000"
	.space	21
	.space	3
.LC39:
	.ascii	"2803\000"
	.space	20
	.space	3
.LC40:
	.ascii	"56924\000"
	.space	19
	.space	3
.LC41:
	.ascii	"31757\000"
	.space	19
	.space	3
.LC42:
	.ascii	"54091\000"
	.space	19
	.space	3
.LC43:
	.ascii	"894\000"
	.space	21
	.space	3
.LC44:
	.ascii	"37159\000"
	.space	19
	.space	3
	.type	__PRETTY_FUNCTION__.3103, %object
	.size	__PRETTY_FUNCTION__.3103, 5
__PRETTY_FUNCTION__.3103:
	.ascii	"main\000"
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"%02x\000"
	.space	3
.LC1:
	.ascii	"./topDecimal.bin\000"
	.space	3
.LC2:
	.ascii	"r\000"
	.space	2
.LC3:
	.ascii	"%u\000"
	.space	1
.LC4:
	.ascii	"1\000"
	.space	2
.LC45:
	.ascii	"ENCRYPTED: \000"
.LC46:
	.ascii	"lessThanEqual(outputBuf, cipherTextBuf) == 0\000"
	.space	3
.LC47:
	.ascii	"TestEncryptDecrypt.c\000"
	.space	3
.LC48:
	.ascii	"lessThanEqual(outputBuf, plainTextBuf) == 0\000"
.LC49:
	.ascii	"ALL TESTS PASSED\000"
	.space	3
.LC50:
	.ascii	"DECRYPTED: \000"
.LC5:
	.ascii	"59989\000"
	.ident	"GCC: (Sourcery G++ Lite 2008q3-72) 4.3.2"
	.section	.note.GNU-stack,"",%progbits
