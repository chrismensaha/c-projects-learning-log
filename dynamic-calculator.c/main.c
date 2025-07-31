#include <stdio.h>
#include <stdlib.h>
#include "calculator.c"

int main(){
    while (1){
    double *history=NULL;
    double a=0,b=0;
    char mode='0';
    double result=0;
    int error=0;
    printf("Enter here:");
    scanf("%lf%c%lf",&a,&mode,&b);
        
    
        result=0;
        switch (mode)
        {
        case '+':
            result=add(a,b);
            break;
        case '-':
            result=subtract(a,b);
            break;
        case '*':
            result=multiply(a,b);     
            break;
        case '/':
            if (b !=0){
                result=divide(a,b); 
            }
            else{
                printf("Error! Division by zero\n");
                error=1;
            }
            
            break;
        default:
            printf("Try again\n");
            continue;
        }
        if (error!=1){printf("%.2f\n",result);}
        else{printf("Try again\n");}
        
    }
    
    return 0;
}