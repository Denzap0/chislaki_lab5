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
    return pow(x,0.5)/(1 + x * x);
}


double trapezoid(double a, double b, int n){
    double h = (b - a)/n;
    double sum = f1(a) + f1(b);
    for(int i = 1; i <= n -1; i++){
        sum += 2 * f1(a + i * h);
    }
    sum *= h/2;
    return  sum;
}

double sympson(double a, double b, int n){
    double h = (b - a)/n;
    double sum = f1(a) + f1(b);
    for(int i = 1; i <= n -1; i++){
        if(i % 2 == 0){
            sum += 2 * f1(a + i * h);
        }else{
            sum += 4 * f1(a + i * h);
        }
    }
    sum *= h/3;
    return  sum;
}


void rungeCriterior(){
    double sum = 0, sumPrev = 0;
    int n = 1;
    do{
        sumPrev = sum;
        sum = trapezoid(0, 1.0, n);
        n++;
    }while(abs(sum - sum) > 3 * eps);
    cout << sum << endl;
    sum = 0;
    sumPrev = 0;
    do{
        sumPrev = sum;
        sum = sympson(0, 1.0, n);
        n++;
    }while(abs(sum - sumPrev) > 15 * eps);
    cout << sum;
}

int main(){
    rungeCriterior();
}
