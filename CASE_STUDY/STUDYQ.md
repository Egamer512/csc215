# Study Questions

1. Suppose you want to add unary operations (i.e., ones requiring only one
operand) to the calculator. For example, we might add "M" to indicate
unary minus (i.e., change the sign of the old value) and "A" to indicate
absolute value. What changes would need to be made to the program?
* The operands to change to those charcters and do the correct operations based on the specific characters

2. Suppose that words rather than single character symbols are to be used
for the operators (e.g., the user types "times" instead of "*"). Where in
the program would the necessary changes occur?
* just change the == so that it is the word not the character. But this also requires a loop to ensure everything is correct.

3. Suppose that the calculator is to be converted to use C++ double values rather than integers. Where would changes need to be made?

Just make sure that the inputs would be able to handle the double values instead of just integers. Also make sure that any code that was specified for integers work for doubles.

4. 