# Study Questions

1. To avoid calling ToInt() with BigInt values that exceed INT_MAX, it’s
possible to convert the BigInt value to a double value and compare
double values rather than comparing BigInt values. Write code
implementing this approach.

2. Yet another approach to dealing with INT_MAX overflow requires
changing the header of ToInt() to have a third parameter, bool overflow,
which is set when overflow occurs. Write this version of ToInt() and
discuss its advantages and disadvantages compared to the approach
taken in this case study.

3. Write the body of a testing program for the constructor that converts an
int to a BigInt and describe test data for it, giving an explanation for
each data set and describing its importance.

4. Use the BigInt class to create a function that calculates values of large
factorials.
BigInt Factorial(int n)
// Pre: 0 <= n
// Post: returns the value of N! = N * N-1 * N-2 *...*1

5. Modify the Factorial function so that n is a BigInt. Does it make sense to
worry about finding the value of n! where INT_MAX < n?

6. Use the BigInt class to create a function that calculates large Fibonacci
values.