#include <stdio.h>
#include <math.h>
double funktion_f(double k,double r) {return k/(1+k*(1-k)*r);}// die funktinon f ist immer k/(1+k*(1-k)*r)

double funktion_g(double u,double r){
	double delta= 1 - 2*u*r + u*u*r*r + 4*u*u*r;	// Delta = b^2 - 4ab 
	double k1=(u*r - 1  + sqrt(delta) )/(2*u*r);	// lösung von k=g(u,r)
	                                             	// double k2=(u*r - 1  - sqrt(delta) )/(2*u*r);
	if(u*r == 0){return u;}
    else if(delta==0) {return (u*r+1)/(2*u*r);} 	//delta=0 k=-b/2a                  
	else if(delta<0)  {return 0;}              		//delta <0 keine
	else              {return k1;}
}
int main(void){
    //k,r
	printf("k \t\t | \t r \t\t | \t f(k,r) \t | \t g(f(k,r)r)\n");
    double r;
    for(r=0;r<=5;r++){
        double k;
        for(k=0;k<=1;k+=0.1){
    		printf("%.5f \t | \t %.5f \t | \t %.5f \t | \t %.5f\n", k, r, funktion_f(k,r), funktion_g(funktion_f(k,r),r));
        }
    }
    printf("\n");
    //u,r
    printf("u \t\t | \t r \t\t | \t g(u,r) \t | \t f(g(u,r)r)\n");
    for(r=0;r<=5;r++){
        double u;
        for(u=0;u<=5;u++){
            printf("%f \t | \t %f \t | \t %f \t | \t %f\n", u, r, funktion_g(u,r), funktion_f(funktion_g(u,r),r));
        }
    }
}

