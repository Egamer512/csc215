## Multiplication is repeated addition. 

## Let's say you have 4 * 3. You add 4, 3 times. This means if you have a way to track the counter (3), you are able to repeatedly add 4, 3 times.

### `DCR` means to decrement register/memory. This is like -=1 in most programming languages!

### `MVI` basically means to set the register to a set value, not referring to memory. Like setting the B register to 00.

## `JNZ` means "Jump if not Zero." This checks a register/memory and if it's not zero, it will jump to an instruction.



Instructions
|Pneumonic|Description|Hex|
|--------|----------|-----|
|`LDA`|Load accumalator w/ Multiplicand| 3A|
|(address)|Least Significant Address| 30|
|(address)|Most Significant Address| 00|
|`MOV (A-->B)`|Move the Multiplicand to B| 47|
|`LDA`|Load accumalator w/ Multiplier, which is the counter| 3A|
|(address)|Least Significant Address | 40|
|(address)|Most Significant Address | 00|
|`MOV (A-->C)`|Move the "counter" to C|4F|
|`MVI (A)`|Reset Register A to 0, this is the command|3E|
|`MVI (A)`|Reset Register A to 0, this is the value |00|
|`ADD (B + A)`|Add B + A|80|
|`DCR (C)`|Decrement the counter|0D|
|`JNZ`|If the C register is not 0, go back to the addition of B + A |C2|
|(address)|Go back to 09, which is A + B, low sig|09|
|(address)|Go back to 09, which is A + B, high sig|00|
|`STA`|Store the addition from the accumalator |32|
|(address)|Store accumalator, low sig|50|
|(address)|Store accumalator, high sig|00|
|`HLT`|Halt|76|