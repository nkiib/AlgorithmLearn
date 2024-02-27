#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

double ipower(double x, int n){
    int abs_n;
    double r;

    abs_n = abs(n);
    r = 1;

    while(abs_n != 0){
        if(abs_n & 1) r *= x;
        x *= x; abs_n >>= 1;
    }
    if ( n>= 0) return r; else return 1 / r;
}

double power(double x, double y){
    if(y <= INT_MAX && y >= -INT_MAX && y == (int)y)
        return ipower(x,y);
    if(x > 0)
        return exp(y * log(x));
    if(x != 0 || y <= 0)
        fprintf(stderr , "power: domain error \n");

    return 0;
}

int main(){
    double x = 2.0;
    double y = 2.0;
    
    printf("%f\n",power(x,y));
}