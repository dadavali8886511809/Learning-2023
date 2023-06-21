/*2. Write a C program that uses functions to perform the following operations: 
     i) Reading a complex number 
     ii) Writing a complex number 
     iii) Addition of two complex numbers 
     iv) Multiplication of two complex numbers 
  (Note: represent complex number using a structure. */


#include <stdio.h>
struct Complex {
    double real;
    double imaginary;
};

void readComplex(struct Complex *c) {
    printf("Enter the real part: ");
    scanf("%lf", &(c->real));

    printf("Enter the imaginary part: ");
    scanf("%lf", &(c->imaginary));
}

void writeComplex(const struct Complex *c) {
    printf("Complex number: %.2f + %.2fi\n", c->real, c->imaginary);
}

struct Complex addComplex(const struct Complex *c1, const struct Complex *c2) {
    struct Complex result;
    result.real = c1->real + c2->real;
    result.imaginary = c1->imaginary + c2->imaginary;
    return result;
}

struct Complex multiplyComplex(const struct Complex *c1, const struct Complex *c2) {
    struct Complex result;
    result.real = (c1->real * c2->real) - (c1->imaginary * c2->imaginary);
    result.imaginary = (c1->real * c2->imaginary) + (c1->imaginary * c2->real);
    return result;
}

int main() {
    struct Complex c1, c2, sum, product;

    printf("Reading Complex Number 1:\n");
    readComplex(&c1);

    printf("\nReading Complex Number 2:\n");
    readComplex(&c2);

    printf("\nComplex Number 1:\n");
    writeComplex(&c1);

    printf("\nComplex Number 2:\n");
    writeComplex(&c2);

    sum = addComplex(&c1, &c2);
    printf("\nSum of Complex Numbers:\n");
    writeComplex(&sum);

    product = multiplyComplex(&c1, &c2);
    printf("\nProduct of Complex Numbers:\n");
    writeComplex(&product);

    return 0;
}