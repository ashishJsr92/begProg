#include<stdio.h>

double sqrt(double val);

int main()
{
    double value = 0;
    printf("Enter the value : ");
    scanf("%lf",&value);

    printf("Square root : %lf\n", sqrt(value));

    return 0;
}

double absolute(double val)
{
    if(val < 0)
        return (val * -1);
}
double sqrt(double val)
{
    if(val < 0){
        printf("\nError : Square of a number cannot be negative");
        return -1;       
    }
    else if (val == 0){
        return 0;
    }
   
    double guess = 1;
    while( absolute(val - (guess * guess)) > 0.00001){
        guess = (guess + (val / guess)) / 2;
    }
 
    return guess;
}

