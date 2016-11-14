#include <stdio.h>
#include <math.h>

double programming(double X,double T)

{
    
    int n;
    double V,U;
    
    
    
    V=(-1.0/3)*X+(1.0/2)*X*X-(1.0/6)*X*X*X;
    
    for (n=1;n<=5;++n)
    
    {
        
        V=V+(2/(n*n*n*(M_PI)*(M_PI)*(M_PI)))*exp(-(n*n)*((M_PI)*(M_PI))*T)*sin(n*M_PI*X);
        
    }
    
    U=T*(1-X)+V;
    
    return U;
    
}
