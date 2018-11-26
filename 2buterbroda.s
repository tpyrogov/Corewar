.name "2buterbroda(4)"
.comment "TANYA DELAET PRIKOLY"

	sti r1, %:live_fork_1, %1
	sti r1, %:live_fork_2, %1
	sti r1, %:live_fork_3, %1
	sti r1, %:live_fork_4, %1
	sti r1, %:live_loop, %1
	sti r1, %:live_loop1, %1
	ld %0, r1
live_fork_1:
	live %0
	fork %:live_fork_1
live_fork_2:
	live %0
	fork %:live_fork_2
live_fork_3:
	live %0
	fork %:live_fork_3
live_fork_4:
	live %0
	fork %:live_fork_4
live_loop:
	live %0
live_loop1:
	live %0
	zjmp %:live_loop
