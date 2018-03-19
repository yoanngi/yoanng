.name		"Homer"
.comment	"Ferme ta grande gueule Flanders !"

main:		st		r1, 9
			fork	%:live
			fork	%:kill
live:		st		r1, 6

jump:		zjmp	%:kill

kill:		fork	%-2024
			zjmp	%:jump
