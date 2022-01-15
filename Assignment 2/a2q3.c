/*Operating Systems (CSE231) Refresher Module
Assignment 2, Question 3*/
/*C program to create a matrix of a size input by the user*/

#include <stdio.h>
#include <stdlib.h>

/*Function to add two numbers*/
void add(int a, int b){
    printf("%d + %d = %d\n",a,b,a+b);
}

/*Function to subtract a number from another number*/
void sub(int a, int b){
    printf("%d - %d = %d\n",a,b,a-b);
}

/*Function to multiply two numbers*/
void mul(int a, int b){
    printf("%d * %d = %d\n",a,b,a*b);
}

/*Function to divide a number from another number*/
void divd(int a, int b){
    printf("The Quotient is %d and the Remainder is %d\n",(a/b),(a%b));
}

/*Function for exponential*/
void expo(int a, int b){
    long ans = 1.0;
    //Multiplies a, b times
    while (b!=0){
        ans*=a;
        --b;
    }
    printf("The exponent is %d\n",ans);
}

/*Driver code*/
int main(){
    int a, b, op;

    typedef void (*type)(int, int);
    type func[] = {&add, &sub, &mul, &divd, &expo};

    printf("Operations:\n");
    printf("Addition - 1\n");
    printf("Subtraction - 2\n");
    printf("Multiplication - 3\n");
    printf("Division - 4\n");
    printf("Expoential - 5\n");

    while(1){
        printf("\nEnter the operation: ");
        scanf("%d",&op);
        printf("\nEnter the two numbers (space seperated): ");
        scanf("%d %d",&a,&b);

        if (op==1||op==2||op==3||op==4||op==5){
            func[op-1](a,b);
        }
        else{
            break;
        }
    }

    return 0;
}