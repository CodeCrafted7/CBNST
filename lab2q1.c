#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define e 2.71


double f(double x)
{
    return x*x*x-4*x-9;
}

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
        printf("Iteration %d: x2 = %lf\n",count+1,x2);
        count++;
        if((x1-x0)<=0.0001)
            break;
    }
    printf("count = %d",count);
    return 0;
}
