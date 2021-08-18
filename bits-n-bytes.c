#include<stdio.h>

//Ques1

int bitAnd (int x, int y) {
    int res = ~(~x | ~y);
     return res;
}

//Ques2

int bitXor (int x, int y) {
    int res = ~(~x & ~y) & ~(x & y);
     return res;
}

//Ques3

int sign(int x) {
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
     
    return (x >> (n << 3)) & 0xff;
}

//Ques5

int logicalShift(int x, int n) {
    int res = (x >> n) & (~(((1 << 31) >> n) << 1));
    return res;
}

//Ques6

int conditional(int x, int y, int z) {
    int res = z ^ ((y ^ z) & ((!x) + ~0));
    return res;
}


//Ques7

int bang(int x) {
    int res = (((~x + 1) | x) >> 31) + 1;
    return res;
}

//Ques8


int invert (int x, int p, int n) {
    int res = x ^ (~(~0 << n) << (p + 1 - n));
    return res;
}


int main()
{
    int x,y,z,n,p;
    scanf("%d %d %d %d %d",&x,&y,&z,&n,&p);
    
    printf("%d\n",bitAnd(x,y));
    printf("%d\n",bitXor(x,y));
    printf("%d\n",sign(x));
    printf("%d\n",getByte(x,n));
    printf("%d\n",logicalShift(x,n));
    printf("%d\n",conditional(x,y,z));
    printf("%d\n",bang(x));
    printf("%d\n",invert(x,p,n));

}

