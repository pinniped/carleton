;
;	SYSC2001 Lab1
;
Display	.EQU 04E9h	; address of Libra display
;
Message: .DB 'Zabcxyz~$' ;String to print

PrtLow:
; BX register gets first character of message
; DX reg gets address of Libra display

;
	mov BX, Message
	mov DX, Display
;
PrtChar:
;
; You need to place the next character to print into the 'al' register
;
	mov AL,[BX]
;
; Try to figure out how the CMP and JE statements work here (because you are
; going to have to figure out how to add statements such as these 
; in Part II of the lab). These 2 statements check for a '$' symbol in AL and jump to the  
; end of program label "EndPrt" (look for it!) if so.
;
; CMP a,b compares a to b. After the CMP instruction, you can include a conditional
; jump instruction. In this case, we have used the JE conditional jump, which means
; jump to the label "EndPrt" if a EQUALS b. 
;
; There are many other conditional jump instructions, that will jump to the label 
; "EndPrt" here) depending on the result of the CMP instruction. For example, JAE will 
; "jump if a is above or equal to b".
;
; Essentially, conditional jumps are used to "skip over" some instructions that come
; after the jump instruction, iff the conditions are met.
;
	cmp AL,'$'	; is the character a '$' ?
	JE EndPrt	; if so, we are done

	; Check for ASCII above 'a'
	cmp AL,'a'	
	; If if 'a' > AL, then go to next letter
	JL incPtr

	; Check for ASCII above 'z'
	cmp AL,'z'	
	; If below, go to next letter
	JG incPtr
;
; Here is the 'out' statement which actually prints a single character
;
	out DX,AL	; print the char
	
incPtr:
	inc BX		; step along the string to the next character
;
; The next statement is an unconditional jump back to the beginning of the loop
; "Unconditional" means that the jump is ALWAYS taken (no CMP needed).
;
	jmp PrtChar	; loop back
	
;
; The next statement defines another address - the end of the program
;

EndPrt:
	HLT			; Stop the Libra processor

.END PrtLow
