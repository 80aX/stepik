// Реализуйте метод, вычисляющий факториал заданного натурального числа.

// Факториал NN вычисляется как 1⋅2⋅...⋅N1⋅2⋅...⋅N.

// Поскольку это очень быстро растущая функция, то даже для небольших NN вместимости типов 
// int и long очень скоро не хватит. Поэтому будем использовать BigInteger.

// Воспользуйтесь предоставленным шаблоном. Декларацию класса, метод main и обработку ввода-вывода 
// добавит проверяющая система.

// Sample Input 1:
// 1
// Sample Output 1:
// 1
// Sample Input 2:
// 3
// Sample Output 2:
// 6


/**
 * Calculates factorial of given <code>value</code>.
 *
 * @param value positive number
 * @return factorial of <code>value</code>
 */


import java.math.BigInteger;


public class factorialCalculator {

    public static BigInteger factorial(int value) {
        BigInteger result = BigInteger.valueOf(1);
        
        for (int i = 1; i <= value; ++i) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }


    public static void main(String[] args) {
        int n = 8;
        System.out.println(factorial(n));
    }
}
