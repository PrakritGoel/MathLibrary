#include "mathlib.h"

#include <stdlib.h>

// All of the functions below were built following the Python code provided
// in the assignment document.

double Exp(double x) {
    double trm = 1.0;
    double sum = trm;
    uint32_t k = 1;

    while (trm > EPSILON) {
        trm *= Abs(x) / k;
        sum += trm;
        k += 1;
    }

    if (x > 0) {
        return (sum);
    } else {
        return (1 / sum);
    }
}

double Sin(double x) {
    double s = 1.0, v = x, t = x, k = 3.0;

    while (Abs(t) > EPSILON) {
        t = (t * (x * x)) / ((k - 1) * k);
        s = -s;
        v += s * t;
        k += 2.0;
    }

    return v;
}

double Cos(double x) {
    double s = 1.0, v = 1.0, t = 1.0, k = 2.0;

    while (Abs(t) > EPSILON) {
        t = (t * (x * x)) / ((k - 1) * k);
        s = -s;
        v += s * t;
        k += 2.0;
    }

    return v;
}

double Sqrt(double x) {
    double z = 0.0;
    double y = 1.0;

    while (Abs(y - z) > EPSILON) {
        z = y;
        y = 0.5 * (z + x / z);
    }

    return y;
}

double Log(double x) {
    double y = 1.0;
    double p = Exp(y);

    while (Abs(p - x) > EPSILON) {
        y = y + x / p - 1;
        p = Exp(y);
    }

    return y;
}
