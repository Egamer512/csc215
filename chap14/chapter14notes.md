### This chapter is about introducing NEW subroutines to simplify the repitive tasks --> Making things more Efficient!

* The TWOCR subroutine is used to double-space output lines by issuing two carriage returns.

* SPMSG: This is a subroutine displays a string on the console followed by a line feed to create a space after da message; Emebds the message directly in the program flow!

* Example of SPMSG (look how it uses arguments!): 
    * CALL SPMSG
    * DB "message", 0

* GETYN is like out own subroutine that we made for this chapter - compares yes or no.
* We are able to use Y/y and N/n --> If you mess up and type it wrong then the prompt will reappear.

* RZ = Return Zero, and so this works with the GETYN command. 
    * If you say "yes" then the GETYN returns with a zero
    * If you say "no" then it does not 

* XTHL retrives the return address from teh stack and  then simplifies the handling to make readbility better

* Binary is used to make lower case to uppercase: Use 01011111B

* JNZ = jump on zero

* Labels like START2 and START3 are used to structure the flow which allows hte progam tp jump to specific parts based on the conditions

### Overall by using these unique techniques, I am able to use inline messging and reduce the manual work neeed. I also have more Subroutines that can be resued for new programs.

