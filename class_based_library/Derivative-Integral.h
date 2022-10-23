#pragma once

double trapezoidal(double(*f_x)(double), double a, double b, int n);
double Simpson13rule(double(*f_x)(double), double a, double b, int n);
double Simpson38rule(double(*f_x)(double), double a, double b, int n);