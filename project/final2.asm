CR      EQU     0DH     
LF      EQU     0AH     
CTRLZ   EQU     1AH     

; CP/M BDOS Functions
RCONIN  EQU     1       
WCONOUT EQU     2       
RBUF    EQU     10      

; CP/M Addresses
RBOOT   EQU     0       
BDOS    EQU     5      
TPA     EQU     100H    

        ORG     TPA 

START:  LXI     SP,STAK
START1: CALL    CCRLF
        LXI     H,SIGNON
        CALL    COMSG
START2: LXI     H,MSG1
        CALL    COMSG
        CALL    GETNUM
        MOV     B,A 
        CALL    CCRLF
START3: LXI     H,MSG2
        CALL    COMSG
        CALL    GETNUM
        MOV     C,A 
        CALL    CCRLF

        MOV     A,B
        SUB     C 
        CALL    DISPLAY_RES
        RET
        

SIGNON: DB      'Hello! Welcome to the Subtractor! (Press Ctrl + Z to exit)',CR,LF,0
MSG1:   DB      'Enter your first number: ',CR,LF,0
MSG2:   DB      'Enter your second number:',CR,LF,0
MSG3:   DB      'The difference is: ',CR,LF,0





DISPLAY_RES:
        LXI     H,MSG3
        CALL    COMSG
        ADD     A,'0'
        CALL    CO
        CALL    CCRLF
        JMP     START


; Console Character Input Routine
CI:     PUSH    B       ; Save registers
        PUSH    D
        PUSH    H
        MVI     C,RCONIN ; Read function
        CALL    BDOS
        ANI     7FH      ; Mask to 7 bits
        POP     H        ; Restore registers
        POP     D
        POP     B
        RET

; Console Output Character Routine
CO:     PUSH    B       ; Save registers
        PUSH    D
        PUSH    H
        MVI     C,WCONOUT ; Select function
        MOV     E,A     ; Character to E
        CALL    BDOS    ; Output by CP/M
        POP     H       ; Restore registers
        POP     D
        POP     B
        RET

; Carriage Return and Line Feed Routine
CCRLF:  MVI     A,CR
        CALL    CO
        MVI     A,LF
        JMP     CO

; Print Message Pointed to by HL to Console
COMSG:  MOV     A,M     ; Get A character
        ORA     A       ; Check if zero
        RZ              ; Return on zero
        CALL    CO      ; Else output the character
        INX     H       ; Point to the next character
        JMP     COMSG   ; Repeat

GETNUM: CALL    CI
        SUI     '0'
        RET

; Stack Setup
        DS      64      
STAK:   DB      0       

        END