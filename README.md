# RSA Factoring Challenge

This projects is about receiving factoring a list of numbers using trial division. 



## Requirements

This program uses the library gmp to deal with big numbers. If you want to compile the code you'll need to have installed gmp. If you just want to run the program. It's enough just to execute it doing

```
factors <file>
```

where <file> it's a file with one number per line

## How to compile

Use the gcc compiler and the gmp library

```
gcc factors.c -lgmp
```

## Example

Input:

```
$cat tests/test00
25
4
12
45
35
34
128
1024
4958
1718944270642558716715
9
99
999
9999
9797973
49
239809320265259
9213874924379423750243750239457
25
81
49
8633
7
5
3
2
```

Output

```
$./factors tests/test00
25=5*5
4=2*2
12=6*2
45=15*3
35=7*5
34=17*2
128=64*2
1024=512*2
4958=2479*2
1718944270642558716715=343788854128511743343*5
9=3*3
99=33*3
999=333*3
9999=3333*3
9797973=3265991*3
49=7*7
239809320265259=15485783*15485773
9213874924379423750243750239457=837624993125402159113068203587*11
25=5*5
81=27*3
49=7*7
8633=97*89
7=7*1
5=5*1
3=3*1
2=2*1
```

