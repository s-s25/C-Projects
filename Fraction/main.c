# include <stdio.h>

struct Fraction {
    int numerator;
    int denominator;
};

int isUndefined(struct Fraction a) {
    return a.denominator == 0;
}

struct Fraction reduce(struct Fraction a) {
    if (isUndefined(a)) {
        struct Fraction undefined = {1, 0};
        return undefined;
    }
    int denNew = a.denominator;
    int numNew = a.numerator;
    int gcd = 0;
    while (denNew != 0) {
        gcd = denNew;
        denNew = numNew % denNew;
        numNew = gcd;
    }
    a.numerator /= gcd;
    a.denominator /= gcd;
    return a;
}

struct Fraction add(struct Fraction a, struct Fraction b) {
    if (isUndefined(a) || isUndefined(b)) {
        struct Fraction undefined = {1, 0};
        return undefined;
    }
    struct Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return reduce(result);

}

struct Fraction subtract(struct Fraction a, struct Fraction b) {
    if (isUndefined(a) || isUndefined(b)) {
        struct Fraction undefined = {1, 0};
        return undefined;
    }
    struct Fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return reduce(result);
}

struct Fraction multiply(struct Fraction a, struct Fraction b) {
    if (isUndefined(a) || isUndefined(b)) {
        struct Fraction undefined = {1, 0};
        return undefined;
    }
    struct Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return reduce(result);
}

struct Fraction divide(struct Fraction a, struct Fraction b) {
    if (isUndefined(a) || isUndefined(b) || b.numerator == 0) {
        struct Fraction undefined = {1, 0};
        return undefined;
    }
    struct Fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    return reduce(result);
}

int main() {
    struct Fraction a = {1, 2};
    struct Fraction b = {3, 4};

    struct Fraction added = add(a, b);
    struct Fraction subtracted = subtract(a, b);
    struct Fraction multiplied = multiply(a, b);
    struct Fraction divided = divide(a, b);

    printf("(%d/%d) + (%d/%d) = %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, added.numerator, added.denominator);
    printf("(%d/%d) - (%d/%d) = %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, subtracted.numerator, subtracted.denominator);
    printf("(%d/%d) * (%d/%d) = %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, multiplied.numerator, multiplied.denominator);
    printf("(%d/%d) / (%d/%d) = %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, divided.numerator, divided.denominator);
}