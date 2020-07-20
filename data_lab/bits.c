/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
//有离散内味了，直接套公式
int bitAnd(int x, int y) {
  return ~((~x)|(~y));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
//利用移位直接算，n从0开始每增加1就会导致移位增加8，然后直接用0xff提取出最后的信息就好
int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xff;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
//逻辑右移，就是高位皆用0填充
//通过算数右移之后高位会用最高有效位填充，所以我们想实现逻辑右移只要把被填充的位置0就好
//如果要达成这个目标，我们通过把1挪到最高位，然后通过算数右移挪动对应的位数，这样通过算数右移带出来的有效位被1覆盖了
//这时候我们再左移一位后取反，那么原先被1覆盖的位就被置零，这时通过和这个数进行与运算就能屏蔽掉原先的最高有效位填充。
int logicalShift(int x, int n) {
  return (x >> n) & (~((1 << 31) >> n << 1));
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  return 2;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
//0是全0，非0在位里一定有1存在
//只要能抽出这个1然后挪到最低位再取反，然后和1进行与运算就得到了！运算符的结果
//通过(x | (~x + 1))这个运算就可以将非0数的最高位变成1，0的最高位变成0
int bang(int x) {
  return ~((x | (~x + 1)) >> 31) & 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
//没什么好说的，找最小数
int tmin(void) {
  return 1 << 31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
//x是否能用n位数据表示，在n位能表示的情况下
//对于非负数，只能在他的n-1位里有1
//对于负数，只能n-1位里有0
//那么我们我们右移n-1位后，负数就会变成全1，正数就会变成全0
//所以我们右移n-1位后加1，然后再右移1位，这样所有位都变成0了
//然后再进行一次非运算，对n位可以表示的数返回true了。
int fitsBits(int x, int n) {
  return !(((x >> (n - 1)) + 1) >> 1);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int sign = x >> 31;
    int offset = sign & ((1 << n) + (~0));
    return (x + offset) >> n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
//算补码
int negate(int x) {
  return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return !(((x >> 31) & 1) | (!x));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int signx = (x >> 31) & 1;
  int signy = (y >> 31) & 1;
  int result = y + (~x + 1);
  int signr = !((result >> 31) & 1); //if x < y, the result is positive,so this sign should be 1
  return ((signx ^ signy) & signx) | ((signx ^ signy ^ 1) & signr)
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  int sign = !!(x >> 16); //判断前16位是否有1，有的话sign就是1，没有的话就是0
  int shift1 = sign << 4; //1 * 2^4 or 0 * 2^4
  x = x >> shift1; //如果有1就丢掉后16位

  sign = !!(x >> 8);
  int shift2 = sign << 3;
  x = x >> shift2;

  sign = !!(x >> 4);
  int shift3 = sign << 2;
  x = x >> shift3;

  sign = !!(x >> 2);
  int shift4 = sign << 1;
  x = x >> shift4;

  sign = !!(x >> 1);
  int shift5 = sign;

  return shift1 + shift2 + shift3 + shift4 + shift5;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 int tmp = uf & (0x7fffffff);
 int neg = uf ^ (0x80000000);
 if(tmp > 0x7f800000)
     return uf;
 return neg;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  unsigned absx, sign, flag, temp, aftershift, shiftnum;
  absx = x;
  sign = x&(1 << 31);
  if(sign) {
      absx = -x;
  }
  aftershift = absx;
  if(!x)
      return 0;
  while(1) {
      temp = aftershift;
      aftershift = aftershift << 1;
      ++shiftnum;
      if(temp & 0x80000000)
          break;
  }
  //接下来是判断是否进位，按四舍五入的标准来
  if(aftershift&0x01ff > 0x0100) //后9位里第一位为1，后8位有1
      flag = 1;
  else if(aftershift&0x03ff == 0x0300) //后9位里第一位为1，后8位为0
      flag = 1;
  else
      flag = 0;
  return sign + ((127 + 32 - shiftnum) << 23) + (aftershift >> 9) + flag;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  //非规格化数，阶码全是0
  if((uf & 0x7f800000) == 0) {
      uf = ((uf & 0x007fffff) << 1) | (uf & 0x80000000);
  }
  //不是NaN，阶码不全是1，直接阶码加1
  else if((uf & 0x7f800000) != 0x7f800000) {
      uf = uf + 0x800000;
  }
  return uf;
}
