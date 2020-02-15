#include "../inc/calculator.h"
#include "../inc/minilibmx.h"

#define SUB 45
#define ADD 43
#define MUL 42
#define DIV 47
#define MOD 37

#define INCORRECT_OPERAND 1
#define INCORRECT_OPERATION 2
#define DIV_BY_ZERO 3

int main (int argc, char *argv[]) {

    t_operation *operation = (t_operation*) malloc(sizeof(t_operation));
    //enum e_operation oper;

    static char *e_error_names[] = {
    "error: invalid number\n",
    "error: invalid operation\n",
    "error: division by zero\n",
    "usage: ./calc [operand1] [operation] [operand2]\n"
    };
    
    int a = 0, b = 0, result = 0;

    if (argc != 4) {
        mx_printerr(e_error_names[3]);
        exit(1);
    }

    for (int i = 0; argv[1][i]; i++) {
        if (!mx_isdigit(argv[1][i])) {
            mx_printerr(e_error_names[0]);        
            exit(INCORRECT_OPERAND);
        }
    }

    for (int i = 0; argv[3][i]; i++) {
        if (!mx_isdigit(argv[3][i])) {
            mx_printerr(e_error_names[0]);        
            exit(INCORRECT_OPERAND);
        }
    }

    a = mx_atoi(&*argv[1]);
    b = mx_atoi(&*argv[3]);    

    if (*argv[3] == '0' && *argv[2] == '/') {
        mx_printerr(e_error_names[2]);        
        exit(DIV_BY_ZERO);
    }
    else if (*argv[2] == '-') {
        operation->op = SUB;
        operation->f = mx_sub;        
    } else if (*argv[2] == '+') {
        operation->f = mx_add;        
    } else if (*argv[2] == '/') {
        operation->f = mx_div;        
    } else if (*argv[2] == '%') {
        operation->f = mx_mod;        
    } else if(*argv[2] == '*') {    
        operation->f = mx_mul;        
    } else {
        mx_printerr(e_error_names[1]);        
        exit(INCORRECT_OPERATION);        
    }    
    
    result = operation->f(a ,b);

    if (result == 0) 
        mx_printchar(result + 48);        
    else
        mx_printint(result);
    
    mx_printchar('\n');

    free(operation);
    return 0;
}
