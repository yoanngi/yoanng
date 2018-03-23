.name		"Homer"
.comment	"Ferme ta grande gueule Flanders !"


main:		sti		r1, %:live, %1
			fork	%:live

live:		live	%1
			zjmp	%:live

r1			and		r1, %0, r1
			fork	%:jump

jump:		fork	%:512
			st		r1, 101
