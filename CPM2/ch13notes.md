### Big Idea: In Chapter 12, we were introduced to subroutines with CI and CO --> These are REALLY impractical because it's only 1 char. at a time!

### We want to use Line-oriented I/O --> we can read the FULL LINE and display it w/ Returns

* Utilize PIP B:CPMIO.C12=CPMIO.ASM to save backup files
* Use PIP A:CPMIO.ASM=B:CPMIO.C12 for permanent backup
* Use **.LIB** files for incremental edits --> simplifies editing and testing


![Alt text](image-2.png)
* Carriage Return and Line Feed (CCRLF)
    * Outputs CR and LF using the CO subroutine
    * Ends with JUMP CO --> Saves the byte and increases execution speed by directly JUMPING to CO

![Alt text](image-3.png)
* Console Message Output (COMSG)
    * Use MOV A, M to get a character then check if the character is the terminator (00H) using ORA A
    * Outputs each of the characters until 00H is reached 
    * Use CALL CO to print each character and increments the pointer


