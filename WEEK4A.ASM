ASSUME CS:CODE,DS:DATA
DATA SEGMENT
DATA ENDS
CODE SEGMENT
START:
MOV CX,5H
MOV AH,1H
NEXT:
MUL CX
DEC CX
CMP CX,1H
JNZ NEXT
MOV AH,4CH
MOV BL,AL
MOV AL,09H
INT 03H
CODE ENDS
END START