#include<stdio.h>

//Ques1

// sample Input : 4 5 = 4

// Using d morgans therom ~(a&b) = ~a | ~ b which can be also written as a&b = ~(~a | ~b) 

int bitAnd (int x, int y) {
    int res = ~(~x | ~y);
     return res;
}

//Ques2

// sample Input 4 5 = 1

// In the first half of the expression i.e ~(~x & ~y) . Here firstly when we do ~x & ~y we get the bits that are zero in both x and y and when we do ~(~x & ~y) we set the bits to 1 which were zero in ~x & ~y.
// In the second half of the expression i.e ~(x & y) . Here when we do x & y we will get the bits that are 1 in both x and y now we set the bits of x&y that are zero to 1 by ~(x & y).

// now when we do & of both the halves we will get 1 on those bits which were different in x and y or x^y.

int bitXor (int x, int y) {
    int res = ~(~x & ~y) & ~(x & y);
     return res;
}

//Ques3

int sign(int x) {

    // Sample Input  120 = 1;
    // Sample Input  0 = 0;
    // Sample Input  -45 = -1;

    // In the first half of the expression i.e (!!x) !! of any number other than 0 is 1 else equal to 0 

    // In the second half of the expression i.e (x>>31). Now x>>31 of any number less than 0 is -1 else it is 0;

    // If we do | of first half and second half we will get -1 for negative number , 1 for positive and 0 for zere  


    int res = ((!!x) | (x >> 31));
    if(res>0)
    {
        return 1;
    }
    else if(res<0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
    return res;
}

//Ques4

int getByte(int x, int n) {
    // Output required is to extract nth byte from x

    // now one hexadecimal no. is 4 bits and 1 byte is 8 bits that means we have get the correct pair of hexadecimal numbers

    // In the first half (x >> (n*8)) we get the nth byte to the right most position by shifting n*8 times because 1 byte is 8 bits

    // now we do & of first half with 0xff i.e (x >> (n*8)) & 0xff because 0xff is 11111111 and & of 0xff with (x >> (n*8)) will give me the value of right most byte which is required
     
    return (x >> (n*8)) & 0xff;
}



//Ques6

int conditional(int x, int y, int z) {
    // Output required  x ? y:z

    // we will see the expression right to left
    // first part i.e ((!x)+ ~0) ! of any number is 1 if number is zero else it is 0 and In (!x) + ~0 if !x is 1 then the result will be 0 else it will be -1 .
    // second part i.e ((y ^ z) & ((!x) + ~0)) if first res of first part is zero then this ((y ^ z) & ((!x) + ~0)) will be zero as & of anything with zero is zero else it will be (y^z)

    // if the second part i.e ((y ^ z) & ((!x) + ~0)) is zero then answer is z else it is z^( y ^ z ) which is equal to y as z^z cancels out

    int res = z ^ ((y ^ z) & ((!x) + ~0));
    return res;
}


//Ques7

int bang(int x) {
    // output required !x 

    // now in the first part i.e. (~x+1) here we did the 2s compliment which is inverting and adding one to the number, now if x is 0 then it will give out 0 , if it is negative number then it will give out positve number and for a positve number it will give out negative number

    // so in the second part if the (((~x + 1) | x) we do | of first part with x where if first part is 0 it will return 0 because if it is zero then x is 0 , else first will return negative number

    // now in the third part  (((~x + 1) | x) >> 31) now shifting second part by 31 will return 0 if the second part is zero else it will return -1 if second part is a negative number


    // in the last if third part is 0 then answer is 0+1 else if it is -1 then it is -1 + 1 =0 which is !x

    int res = (((~x + 1) | x) >> 31) + 1;
    return res;
}

//Ques8


int invert (int x, int p, int n) {

    // inverted n bits of x from p
    // in the first part we set right most n bits to 1 i.e (~(~0 << n)
    int a = (~(~0<<n));

    // now we set n bits to 1 from p position 
    a = a <<(p-n);

    // now x^a to invert the required bits
    int res = x ^ a;
    return res;
}


