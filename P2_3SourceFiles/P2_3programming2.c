#include <stdio.h>
#include <math.h>
#include <gsl/gsl_matrix.h>
#include <P2_3programming1.h>

int main()

{
    
    int m,n,p,N;
    
    double y,x,n0,n1,n2,m1,T,v,dx,dt,val;
    float q;
    FILE*f=fopen("P2_3Output/programming2","w");
    FILE*g=fopen("P2_3Output/logplot","a");
    
    gsl_matrix*M;
    
    printf("Enter T:");
    
    scanf("%lf",&T);
    
    printf("Enter 12*v:");
    
    scanf("%lf",&v);
    
    printf("Enter N:");
    
    scanf("%d",&N);
    
    dx=1.0/N;
    dt=(v/12.0)*dx*dx;    
    
    p=(int)(T/dt+0.5);
    q=(float)T/dt;
    
    if((p-q)!=0)
    
    {
        
        printf("T and v input are not compatible.");
        
    }
    
    M=gsl_matrix_calloc(p+1,N+1);
    
    for(m=0;m<p+1;++m)
    
    {
        
        gsl_matrix_set(M,m,0,m*dt);
        
    }
    
    for(m=1;m<p+1;++m)
    
    {
        
        for(n=1;n<N;++n)
        
        {
            
            n0=gsl_matrix_get(M,m-1,n-1);
            n1=gsl_matrix_get(M,m-1,n);
            n2=gsl_matrix_get(M,m-1,n+1);
            
            m1=(1.0-2.0*(v/12.0))*n1+(v/12.0)*(n0+n2);
            
            gsl_matrix_set(M,m,n,m1);
            
        }
        
    }
    
    for(m=0;m<p+1;++m)
    
    {
        
        for(n=0;n<N+1;++n)
        
        {
        
            val=gsl_matrix_get(M,m,n);
            
            printf("(%d,%d) %lf\t",m,n,val);

        }
        
        printf("\n");
        
    }
    
    fprintf(f,"#x\t\tu\t\tAna\t\tError\n");
    
    for(n=0;n<N+1;++n)
    
    {
        
        x=n*(1.0/N);
        
        val=gsl_matrix_get(M,p,n);
            
        fprintf(f,"%lf\t%lf",x,val);
        
        y=programming(x,T);
        
        if(x==0.2)
        
        {
            
            fprintf(g,"%lf\t%lf\n",log(fabs(y-val)),log(1.0/N));
            
        }
        
        fprintf(f,"\t%lf\t%lf\n",y,y-val);

    }
        
    return 0;
    
}
