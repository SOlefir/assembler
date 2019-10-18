.name "The Spiderman"
	.comment "With great power comes great responsibility"
	    ld %1, r3
	    ld %4, r4
	    sti r1, %:say_live, %1
	    sti r1, %:loop_live, %1
start_load:
	    ld %20, r2
	    ld %5, r8
	    ld %0, r9
to_jump:
	    ldi %:start_load, r9, r10
	    sti r10, %:end, r8
	    add r8, r4, r8
	    add r9, r4, r9
loop_live:
	    live %1
	    sub r2, r3, r2
	    zjmp %:to_jump2
	    ld %0, r16
	    zjmp %:to_jump
to_jump2:
	    fork %:end
say_live:
	    live %1
	    zjmp %:say_live
end:	