#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Capture printf output
static char output_buffer[65536];
static int output_pos = 0;

int captured_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int written = vsnprintf(output_buffer + output_pos, sizeof(output_buffer) - output_pos, fmt, args);
    va_end(args);
    if (written > 0) output_pos += written;
    return written;
}

#define printf captured_printf

// Include user code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple calculator program
int user_main() {
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
    return 0; }

#undef printf

JNIEXPORT jstring JNICALL
Java_com.example.capp_MainActivity_runMain(JNIEnv *env, jobject thiz) {
    output_pos = 0;
    memset(output_buffer, 0, sizeof(output_buffer));
    user_main();
    return (*env)->NewStringUTF(env, output_buffer);
}