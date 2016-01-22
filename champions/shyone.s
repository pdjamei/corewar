.name "Shy one"
.comment "Wesh wesh canne a peche"
	
essai:	live %42
copy:	sti r1, %:essai, %1
		and r1, %0, r1
		sti r1, %:copy, %1
		and r1, %0, r1
		sti r1, %:flag, %16
		add r1, r3, r1
		xor	r1, %15, r4
flag:	ld %0, r1
		zjmp %:copy

