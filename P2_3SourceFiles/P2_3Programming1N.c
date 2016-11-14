#include <stdio.h>
#include <math.h>
#include <P2_3programming1.h>

int main ()

{
    
    double i,h,y,T;
    FILE*f=fopen("P2_3Output/programming1","w");
    
    printf("Enter h:");
    
    scanf("%lf",&h);
    
    printf("Enter T:");
    
    scanf("%lf",&T);

    fprintf(f,"#x\t\tU\n");

    for(i=0;i<=1+h;i=i+h)
    
    {
    
        y=programming(i,T);
        
        fprintf(f,"%lf\t%lf\n",i,y);
        
    }
    
    fclose(f);
    
    return 0;
    
}
