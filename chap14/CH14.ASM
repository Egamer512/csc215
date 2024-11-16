CR      EQU     0DH
LF      EQU     0AH
CTRLZ   EQU     1AH
RCONIN  EQU     1
WCONOUT EQU     2
RBUF    EQU     10
RBOOT   EQU     0
BDOS    EQU     5
TPA     EQU     5

        ORG     TPA
START:  LXI     SP,STAK
START1: CALL    CCRLF
        LXI     H,SIGNON
        CALL    COMSG
START2: CALL    TWOCR
        CALL    SPMSG
        DB      'TESTING FOR YES OR NO',CR,LF,0
        CALL    GETYN
        JNZ     START3
        CALL    SPMSG
        DB      LF,'ANSWER WAS "YES!!!"',0
        JMP     START2

SIGNON: DB      'SIGN-ON-MSG',CR,LF,0
CI:     PUSH    B
        PUSH    D
        PUSH    H
        MVI     C,RCONIN
        CALL    BDOS
        ANI     7FH
        POP     H
        POP     D
        POP     B
        RET

CO:     PUSH    B
        PUSH    D
        PUSH    H
        MVI     C,WCONOUT
        MOV     E,A
        CALL    BDOS
        POP     H
        POP     D
        POP     B
        RET

TWOCR:  CALL    CCRLF          ; Print two newlines
CCRLF:  MVI     A,CR           ; Print a carriage return
        CALL    CO
        MVI     A,LF           ; Print a line feed
        ORA     A
        CALL    CO
        INX     H
        JMP     COMSG

COMSG:  MOV     A,M            ; Output characters in memory until a null terminator
        ORA     A
        RZ
        CALL    CO
        INX     H
        JMP     COMSG

CIMSG:  PUSH    B              ; Input a string from the console
        PUSH    D
        PUSH    H
        LXI     H,INBUF+1
        MOV     A,M
        MVI     D,0
        DAD     D
        INX     H
        MVI     M,0
        POP     H
        POP     D
        POP     B
        RET

SPMSG:  XRA     A              ; Special routine for processing and displaying a message
        ADD     M
        INX     H
        XTHL
        RZ
        CALL    CO
        JMP     SPMSG

GETYN:  DB      '(Y/N):',0     ; Prompt for and process 'Y' or 'N' input
        CALL    CIMSG
        CALL    CCRLF
        LDA     INBUF+2
        ANI     01011111B
        CPI     'Y'
        RZ
        CPI     'N'
        JNZ     GETYN
        RET

INBUF:  DS      83             ; Input buffer
        DS      64
STAK:   DB      0              ; Stack storage
        END
