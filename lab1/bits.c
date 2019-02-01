/* 
 * CS:APP Data Lab 
 * 
 * <Beomjoo Kim, beomjoo>
 * 
 */

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */

int bang(int x) 
{
  int signX = (x>>31);
  int signmX = (((~x)+1)>>31);
  return ((~(signX | signmX)) & 1);
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) 
{
  int mask = 0x11 + (0x11 << 8) + (0x11 << 16) + (0x11 << 24);
  int fourth = mask & x;
  int third = (x>>1) & mask;
  int second = (x>>2) & mask;
  int first = (x>>3) & mask;
  int sum = first + second + third + fourth;
  int mask2 = 15;
  return (mask2 & sum) + (mask2 & (sum>>4)) + (mask2 & (sum>>8)) + (mask2 & (sum>>12)) + (mask2 & (sum>>16)) + (mask2 & (sum>>20)) + (mask2 & (sum>>24)) + (mask2 & (sum>>28));
}

/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) 
{
  return ~((~x) & (~y));
}

/*
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40
 *   Rating: 4
 */
int bitRepeat(int x, int n) 
{
    int mask = ~(~1 << (n-1));
    int real = x & mask;
    int numofP = 32/n;
    int inc = n%32;
    int neg;
    int biinc;
    real |= (real << inc);
    biinc = inc*2;
    numofP = 31 -  biinc;
    neg = ((numofP) >> 31);
    inc = biinc * !neg;
    real |= (real << inc);
    biinc = inc*2;
    numofP = 31 -  biinc;
    neg = ((numofP) >> 31);
    inc = biinc * !neg;real |= (real << inc);
    biinc = inc*2;
    numofP = 31 -  biinc;
    neg = ((numofP) >> 31);
    inc = biinc * !neg;real |= (real << inc);
    biinc = inc*2;
    numofP = 31 -  biinc;
    neg = ((numofP) >> 31);
    inc = biinc * !neg;
    return real | (real << (inc));
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
int fitsBits(int x, int n) 
{
  int moveN = (33 + (~n));
  int tctd = ((x << moveN) >> (moveN));
  return !(tctd ^ x);
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) 
{
  int mask = 255;
  int y = x >> (n<<3);
  return y & mask;
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) 
{
  int minX = ~x+1;
  int sub = y + minX;
  int sign = sub >> 31 & 1;
  int signmask = 1 << 31;
  int signX = signmask & x;
  int signY = signmask & y;
  int comsign = signX ^ signY;
  comsign = (comsign >> 31) & 1;
  return (comsign & (signX >> 31)) | (!sign & !comsign);
}

/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) 
{
  int signM = 1 << 31;
  int sign = x & signM;
  return (!sign) & (!!x);
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) 
{
  int y = x >> n;
  int mask = (1 << 31) >> n << 1;
  return y & ~mask;
}

/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) 
{
  return (1 << 31);
}
