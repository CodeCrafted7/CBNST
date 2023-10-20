#include<stdio.h>
int n;

void convertToDiagonal(float a[][n+1],int n)
{
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
         if(j!=i)
         {
             ratio=a[j][i]/a[i][i];
             for(k=0;k<n+1;k++)
                a[j][k]=a[j][k] -( ratio * a[i][k]);
         }
      }
    }
}

void printUnknowns(float a[][n+1],int n)
{
   int i;
   printf("Values of unknowns are:\n");
   for(i=0;i<n;i++)
      printf("Value of Variable %d=%f\n",i,a[i][n]/a[i][i]);

}
int main()
{
    int i,j,k,x,y;
    float ratio;
    printf("Enter no of Unknowns:");
    scanf("%d",&n);
    float a[n][n+1];
    printf("Enter the Augmented Matrix:\n");
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n+1;j++)
        scanf("%f",&a[i][j]);
    }
    convertToDiagonal(a,n);
    printUnknowns(a,n);
    return 0;
}
