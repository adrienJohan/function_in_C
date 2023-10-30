#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 0.000001

float f(float a);
float df(float a);
float nv_approximation(float a);



int main () 
{

    float x0 = 1, 
          final = 0,
          delta = 2;

    while(delta > EPS)
    {
        final = nv_approximation(x0);
        delta = fabs(x0 - final);
        x0 = final;
    }
    printf("the x number = %f\n", final);

    return 0;
}

float f(float a)
{
	return log(a)-1;      
}

float df(float a)
{
    return 1/a;
}

float nv_approximation(float a)
{
    return ((df(a)*a) - f(a))/(df(a));
}

