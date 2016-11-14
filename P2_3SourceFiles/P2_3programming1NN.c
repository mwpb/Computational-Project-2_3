#include <stdio.h>
#include <math.h>
#include <gsl/gsl_sf_erf.h>

int main ()

{
    
    double y,h,t,s,x,z;
    FILE*f=fopen("P2_3Output/programming1_1","w");
    
    printf("Enter t:");
    
    scanf("%lf",&t);
    
    printf("Enter h:");
    
    scanf("%lf",&h);
    
    fprintf(f,"#x\t\tf\n");
    
    for(x=0;x<=1+h;x=x+h)
    
    {
        
        z=x/(sqrt(t));
        
        y=(1.0+(0.5)*(z*z))*gsl_sf_erfc(z/2.0)-(1.0/M_PI)*z*exp((-1.0/4.0)*z*z);
        
        s=y*t;
        
        fprintf(f,"%lf\t%lf\n",x,s);
        
    }
    
    return 0;
    
}
