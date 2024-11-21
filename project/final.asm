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