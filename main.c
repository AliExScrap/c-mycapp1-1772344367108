#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple calculator program
int main() {
    printf("=== Calculator ===\n");
    
    double a, b;
    char op;
    
    printf("Enter first number: ");
    scanf("%lf", &a);
    
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);
    
    printf("Enter second number: ");
    scanf("%lf", &b);
    
    double result;
    switch(op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if(b == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            result = a / b;
            break;
        default:
            printf("Unknown operator: %c\n", op);
            return 1;
    }
    
    printf("%.2f %c %.2f = %.2f\n", a, op, b, result);
    return 0;
}