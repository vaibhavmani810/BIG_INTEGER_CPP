# BIG_INTEGER_CPP
This repository contains implementation of Large integers which do not fit into native data types like long long.
This repository contains implementation of Large unsigned integers which do not fit into native data types like long long.

It contains basic implementation of number storing each digit at a index equal to its place value. For Example : To store 123 , store 3 at index 0 , store 2 at index 1, store 1 at index 2.

Basic Methods described here:

Constructors (Default , Copy Constructor , etc.)
Methods for recieving input/output from standard cin, cout stream.(operator overloading of '<<' & '>>')
Basic Comparison operators (<,>,<=,>=,==,!=) This enables us to use standard functions like sort(),max(),min(),etc.
Addition , Multiplication , Modulo with a number less than 2^64-1 , etc .
Some Additional methods like typecasting the number to long long if applicable , and to_string() function.
Additional things I will be adding after Some Time :

Division of Numbers
Support for Negative Numbers
Exponentiation
Scope for improvement :

Memory can be improved by storing a chunk of digits at single place . For example : 123456789 can be stored as {'789' '456' '123'} , bigger grouping complicates the code but improve the memory required / range of number significantly.
Use of Karatsuba Algorithm to modify the time Complexity of Multiplication.
Memory can also be improved by storing digits as characters instead of array.
The repository also contains a program with certain applications of big integers like finding factorial of number, sorting big integers , etc. image We can see the factorial of 246 to be accurate

Feel free to contribute to this :)
