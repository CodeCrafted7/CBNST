#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void Roundoff(double p,double v)
{
    double val = (v * pow(10, p+1));
    int temp = val + 1e-9;
    int n = temp%10;
    if(n>5)
    {
        temp+=10;
        temp-=n;
        temp/=10;
        double ans = temp/pow(10, p);
        printf("\nAfter %d Roundoff of the Number is : ",(int)p);
        printf("%lf",ans);
    }
    else if(n<5)
    {
        temp-=n;
        temp/=10;
        double ans = temp/pow(10, p);
        printf("\nAfter %d Roundoff of the Number is : ",(int)p);
        printf("%lf",ans);

    }
    else
    {
        int x = temp/10;
        int y = x%10;
        if(y%2==1)
            x=x+1;
        double k = x/pow(10, p);
        printf("\nAfter %d Roundoff of the Number is : ",(int)p);
        printf("%lf",k);
    }
}
void truncate(double p,double v)
{
    double m = pow(10,p);
    double truncate= (int)(v*m)/m;
    printf("\nTruncation of a Number is : ");
    printf("%lf",truncate);
}
int main()
{
    double x,y;
    printf("Enter the Value of X and Y : ");
    scanf("%lf %lf",&x,&y);
    double temp = x-y;
    if(temp<0)
        temp*=-1;
    double ae = temp;
    double re = (ae/x);
    double pe = (re*100);
    printf("\nae = %lf, re = %lf, pe = %lf\n",ae,re,pe);
    printf("Enter the Number How many decimal point do you want to Roundoff the Value : ");
    double p;
    scanf("%lf",&p);
    Roundoff(p,ae);
    truncate(p,ae);
    Roundoff(p,re);
    truncate(p,re);
    Roundoff(p,pe);
    truncate(p,pe);
    return 0;
}
