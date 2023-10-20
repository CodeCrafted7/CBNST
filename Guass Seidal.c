#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define EPSILON 0.001
int n;
int flag;

float findSum(int i,float a[][n+1])
{
     float sum=0;
     for(int j=0;j<n;j++)
     {
       if(i!=j)
         sum+=a[i][j];
     }
     return sum;
}

bool isMethodApplicable(float a[][n+1])
{
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {

           if(fabs(a[i][i])>findSum(i,a))
              continue;
           else
              return false;

       }
   }
   return true;
}

void print(int iteration,float values[n])
{
  printf("Iteration %d ",iteration);
  for(int i=0;i<n;i++)
    printf("value[%d]=%f ",i+1,values[i]);
  printf("\n");
}

void findValues(float a[][n+1],float values_old[n])
{
    int i,j,k,iteration=1;
    float ratio,sum=0;
    float values_new[n];
    for(int i=0;i<n;i++)
     values_new[i]=0;
    while(1)
    {
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                sum+=a[i][j]*values_new[j];
            }
            values_new[i]=(a[i][n] - sum)/a[i][i];
        }

        for(k=0;k<n;k++)
        {
            if(fabs(values_old[k]-values_new[k])<EPSILON)
                continue;
            else
            {
               flag=1;
               break;
            }
        }
        if(flag==0)
        {
            print(iteration,values_new);
            return ;
        }
        flag=0;
        print(iteration,values_new);
        for(k=0;k<n;k++)
             values_old[k]=values_new[k];
        iteration++;
    }
}
