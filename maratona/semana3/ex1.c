#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerator1;
    int denominator1;
    char command;
    int numerator2;
    int denominator2;
} Operation;

int calculate_gcd(int number_1, int number_2) {

    int remainder;

    while(number_1 != 0) {

        remainder = number_2 % number_1;
        number_2 = number_1;
        number_1 = remainder;
    }

    if(number_2 < 0)
        number_2 *= -1;

    return number_2;
}

void operation_sign(Operation *operation){

    int numerator_positive = (operation->numerator1 >= 0) ? 1 : 0;
    int denominator_positive = (operation->denominator1 >= 0) ? 1 : 0;


    if(numerator_positive && denominator_positive){
        return;
    } else if (!numerator_positive && denominator_positive){
        return;
    } else if (numerator_positive && !denominator_positive){
        operation->numerator1 *= -1;
        operation->denominator1 = abs(operation->denominator1);
    } else {
        operation->numerator1 = abs(operation->numerator1);
        operation->denominator1 = abs(operation->denominator1);
    }

}

void reduce_fraction(Operation *operation){

    int gcd_denominator = calculate_gcd(operation->numerator1, operation->denominator1);
    // printf("GCD: %d\n", gcd_denominator);
    operation->numerator1 /= gcd_denominator;
    operation->denominator1 /= gcd_denominator;


}

void do_operation(Operation* operation){


    switch(operation->command){
        case '+':

            operation[1].numerator1 = operation[0].numerator1 * operation[0].denominator2 +
                operation[0].numerator2 * operation[0].denominator1;
            operation[1].denominator1 = operation[0].denominator1 * operation[0].denominator2;
            

            break;


        case '-':

            operation[1].numerator1 = operation[0].numerator1 * operation[0].denominator2 -
                operation[0].numerator2 * operation[0].denominator1;

            operation[1].denominator1 = operation[0].denominator1 * operation[0].denominator2;




            break;

        case '*':

            operation[1].numerator1 = operation[0].numerator1 * operation[0].numerator2;
            operation[1].denominator1 = operation[0].denominator1 * operation[0].denominator2;


            break;

        case '/':

            operation[1].numerator1 = (operation[0].numerator1 * operation[0].denominator2);
            operation[1].denominator1 = (operation[0].numerator2 * operation[0].denominator1);


            break;
    }


}

void read_operation(Operation *operation){
    char lixo;
    scanf("%d %c %d %c %d %c %d",
        &operation[0].numerator1,
        &lixo,
        &operation[0].denominator1,
        &operation[0].command,
        &operation[0].numerator2,
        &lixo,
        &operation[0].denominator2);


    // printf("%d / %d\n",operation[0].numerator1, operation[0].denominator1);
}




int main(void){


    int execution_times;
    Operation operations[2];

    scanf("%d", &execution_times);




    for(int i = 0; i < execution_times; i++){

        read_operation(operations);
        do_operation(operations);
        operation_sign(&operations[1]);

        printf("%d/%d = ", operations[1].numerator1, operations[1].denominator1);
        reduce_fraction(&operations[1]);
        printf("%d/%d\n", operations[1].numerator1, operations[1].denominator1);

    }


    return 0;
}

