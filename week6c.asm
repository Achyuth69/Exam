DATA SEGMENT
    ORG 0500h
    COUNT DB 4
    MAT1  DB 1, 2, 3, 4
    MSG   DB 'Result:', 13, 10, '$'
    ORG 0601h
    MAT2  DB 5, 6, 7, 8
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

BEGIN:
    MOV AX, DATA
    MOV DS, AX

    MOV SI, 0500h
    MOV DI, 0601h

    MOV CL, [SI]
    MOV CH, 00h
    INC SI

ADD_LOOP:
    MOV AL, [SI]
    ADD AL, [DI]
    MOV [SI], AL
    INC SI
    INC DI
    LOOP ADD_LOOP

    LEA DX, MSG
    MOV AH, 09h
    INT 21h

    MOV CX, 4
    MOV SI, 0501h   ; Start of result matrix

PRINT_LOOP:
    MOV AL, [SI]
    MOV AH, 0
    MOV BL, 10
    DIV BL            ; AL = AL/10, AH = remainder

    ADD AH, '0'       ; print tens digit
    MOV DL, AH
    MOV AH, 02h
    INT 21h

    ADD AL, '0'       ; print units digit
    MOV DL, AL
    MOV AH, 02h
    INT 21h

    MOV DL, ' '       ; print space
    MOV AH, 02h
    INT 21h

    INC SI
    LOOP PRINT_LOOP

    MOV AH, 4Ch
    INT 21h

CODE ENDS
END BEGIN
