//
//  main.cpp
//  lab5
//
//  Created by MacBook on 12/19/20.
//

#include <iostream>
#include <cmath>
#define eps 1e-4
using namespace std;

double f1(double x)
{
    return pow(x, 0.5) * sin(x * x);
}


double trapezoid(double a, double b, double h){
    double sum = f1(a) + f1(b);
    for(int i = 1; i <= (b - a)/h - 1; i++){
        sum += 2 * f1(a + i * h);
    }
    sum *= h/2;
    return  sum;
}

double sympson(double a, double b, double h){
    double sum = f1(a) + f1(b);
    for (int i = 1; i <= (b - a) / h; i += 2){
        sum += 4 * f1(a + i * h);
    }
    for (int i = 2; i < (b - a) / h - 1; i += 2) {
        sum += 2 * f1(a + i * h);
    }
    sum *= h/3;
    return  sum;
}


void rungeCriterior(double a, double b){
    double sumPrev = 0, sum = 0;
    double h = b - a;
    do{
        sumPrev = sum;
        sum = trapezoid(a, b, h);
        h /= 2;
    }while(abs(sum - sumPrev) > 3 * eps);
    cout << sum << endl;
    sumPrev = 0;
    sum = 0;
    h = (b - a)/2;
    do{
        sumPrev = sum;
        sum = sympson(a, b, h);
        h/= 2;
    }while(abs(sum - sumPrev) > 15 * eps);
    cout << sum;
    
}

int main(){
    rungeCriterior(0, 1);
}
