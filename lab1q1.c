#include<stdio.h>
#include<math.h>
#include <stdlib.h>

double Roundoff(double p,double v)
{
    double val = (v * pow(10, p+1));
    int temp = val + 1e-9;
    int n = temp%10;
    double ans;
    if(n>5)
    {
        temp+=10;
        temp-=n;
        temp/=10;
        ans = temp/pow(10, p);
    }
    else if(n<5)
    {
        temp-=n;
        temp/=10;
        ans = temp/pow(10, p);
    }
    else
    {
        int x = temp/10;
        int y = x%10;
        if(y%2==1)
            x=x+1;
        ans = x/pow(10, p);
    }
    return ans;
}

double truncate(double p,double v)
{
    double m = pow(10,p);
    double truncate= (int)(v*m)/m;
    return truncate;
}

int main()
{
    double x,y,p,x1,temp,ae,re,pe;
    int s=0;
    printf("Enter the value of x: ");
    scanf("%lf",&x);
    printf("If you want to round off the value Press 1 or for truncation Press 2 : ");
    scanf("%d",&s);
    printf("Enter how many decimal point value should be : ");
    scanf("%lf",&p);
    if(s==1)
    {
        x1 =Roundoff(p,x);
    }
    else if(s==2)
    {
        x1 = truncate(p,x);

    }if(s==1){
    x1 =Roundoff(p,x);
    temp = x-x1;
    if(temp<0)
        temp*=-1;
    ae = temp;
    re = ae/x;
    pe = re*100;
    printf("\n\t\t--After RoundOff--\nAbsolute Error: %lf\nRelative Error: %lf\nPercentage Error: %lf %%\n",ae,re,pe);
    }
    else if(s==2)
    {
    x1 = truncate(p,x);
    temp = x-x1;
    if(temp<0)
        temp*=-1;
    ae = temp;
    re = ae/x;
    pe = re*100;
    printf("\n\t\t--After Truncate--\nAbsolute Error: %lf\nRelative Error: %lf\nPercentage Error: %lf %%\n",ae,re,pe);
    }

    return 0;
}
