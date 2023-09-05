#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define e 2.71
double f(double x)
{
    //double a = pow(e,(-x));
    //return 4*a*sin(x)-1;
    //printf("%lf\n",x*x*x-4*x-9);
    return x*x*x-4*x-9;
}
/*
double interval()
{
    double x0=0,x1=0;
    while(x0>-5&&x1<5)
    {
        x0=x0-1;
        x1=x0+1;
        if(f(x0)*f(x1)<0){
            printf("x0 = %lf  x1 = %lf",x0,x1);
            break;
        }
    }
}*/
int main()
{
    double x0=0,x1=0;
    printf("Enter the interval:");
    scanf("%lf %lf",&x0,&x1);
    if(!(f(x0)*f(x1)<0)){
        printf("Intervals are Wrong!");
        return 0;
    }
    int count = 0;
    double x2;
    while(1)
    {
        x2=(x0+x1)/2;
        if(f(x0)*f(x2)<0)
            x1 = x2;
        else if(f(x2)*f(x1)<0)
            x0 = x2;
        //printf("x0 = %lf\tx1 = %lf\n",x0,x1);
        printf("Iteration %d: x2 = %lf\n",count+1,x2);
        count++;
        //printf("%lf\n",x1-x0);
        if((x1-x0)<=0.0001)
            break;
    }
    printf("count = %d",count);
    return 0;
}
