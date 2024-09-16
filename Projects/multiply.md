Multiplication is repeated addition. 

Let's say you have 4 * 3. You add 4, 3 times. This means if you have a way to track the counter (3), you are able to repeatedly add 4, 3 times.

Instructions
|Pneumonic|Description|Hex|
|--------|----------|-----|
|`LDA`|Load accumalator w/ number (value to be added)| 3A|
|(address)|Least Significant| 30|
|(address)|Most Significant| 00|
|`MOV (A-->B)`|Move the "value to be added" to B| 47|
|`LDA`|Load accumalator w/ counter| 3A|
|(address)|Least Significant| 40|
|(address)|Most Significant| 00|
|`MOV (A-->C)`|Move the "counter" to C|79|
|`MVI (A)`|Reset Register A to 0|3E|
|`ADD (B + A)`|Add B + A|80|
|`DCR (C)`|Decrement the counter|0C|

