// Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных 
// целых чисел (Greatest Common Divisor, GCD). Для этого воспользуйтесь следующими свойствами:

// GCD(a,b)=GCD(b,amodb)GCD(a,b)=GCD(b,amodb)
// GCD(0,a)=aGCD(0,a)=a
// GCD(a,b)=GCD(b,a)GCD(a,b)=GCD(b,a)
// Требования к реализации: в данном задании запрещено пользоваться циклами. Вы можете 
// заводить любые вспомогательные функции, если они вам нужны. Функцию main определять 
// не нужно.


#include <iostream>


unsigned gcd(unsigned a, unsigned b) 
{
    // алгоритм Евклида для вычисления наибольшего общего делителя.
    if (a == 0 || b == 0) {
        return a + b;
    } else if (a >= b) {
        return gcd(a % b, b);
    } else if (b >= a) {
        return gcd(a, b % a);
    }
}


int main(void) 
{
    unsigned a = 0;
    unsigned b = 0;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    
    return 0;
}
