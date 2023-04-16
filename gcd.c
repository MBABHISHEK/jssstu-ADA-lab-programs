#include<stdio.h>
#include<stdlib.h>


int gcdinteger(int m,int n)
{
     if(m==0)
    return n;
    
    if(n==0)
    return m;

    if(m==n)
     return m;

     int k;
     if(m>n)
     k=n;
     else
     k=m;

    while(k>0)
    {
        if(m%k==0&&n%k==0)
            return k;
         k--;
    }
}


int eucildgcd(int m, int n)
{
    int r;
  /* if(m==0)
    return n;
    */
    if(n==0)
    return m;

    while(n!=0)
    {
       r=m%n;
       m=n;
       n=r;
    }

    return m;
}
void main()
{
    int ch;
    for(;;)
    {
  printf("ENTER THE CHOICE\n1.TO CALCULATE GCD WITH INTEGER METHOD\n2.TO CALCULATE GCD WITH EUCLIDS METHOD\n0.TO EXIT\n");
    scanf("%d",&ch);
   if(ch==0)exit(0);
   int m,n;
   m=10;
   n=21;
 l1:printf("ENTER THE  TWO POSITIVE NUMBERS\n");
     scanf("%d %d",&m,&n);
   if(m<0||n<0)
    goto l1;
   
   switch(ch)
   {
      case 1:printf("THE GCD OF THE NUMBERS %d and %d IS %d\n",m,n,gcdinteger(m,n));break;
      case 2:printf("THE GCD OF THE NUMBERS %d and %d IS %d\n",m,n,eucildgcd(m,n));break;
        default:printf("ENTER THE VALID CHOICE\n");
   }
    }

}

