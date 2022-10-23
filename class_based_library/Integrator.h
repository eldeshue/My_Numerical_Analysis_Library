#pragma once
double RK1_euler(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step);
double RK2_Heun(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step);
double RK2_MidPoint(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step);
double RK2_Ralston(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step);
double RK3(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step);
double RK4(double(*f_x)(double, double), double init_x, double init_y, double target_x, int number_of_step);