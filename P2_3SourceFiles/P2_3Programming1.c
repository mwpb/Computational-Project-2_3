#include <stdio.h>
#include <math.h>

int main()

{
    
    int n;
    double X,T,V;
    
    printf("Enter X:");
    
    scanf("%lf",&X);
    
    printf("Enter T:");
    
    scanf("%lf",&T);
    
    V=(-1.0/3)*X+(1.0/2)*X*X-(1.0/6)*X*X*X;
    
    for (n=1;n<=50;++n)
    
    {
        
        V=V+(2/(n*n*n*(M_PI)*(M_PI)*(M_PI)))*exp(-(n*n)*T)*sin(n*M_PI*X);
        
    }
    
    U=T*(1-X)+V;
    
    printf("%lf",U);
    
    return 0;
    
}
