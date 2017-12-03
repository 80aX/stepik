// Напишите метод, возвращающий стрим псевдослучайных целых чисел. Алгоритм генерации чисел 
// следующий:

// Берется какое-то начальное неотрицательное число (оно будет передаваться в ваш метод 
// проверяющей системой).
// Первый элемент последовательности устанавливается равным этому числу.
// Следующие элементы вычисляются по рекуррентной формуле Rn+1=mid(R2n)Rn+1=mid(Rn2), 
// где mid — это функция, выделяющая второй, третий и четвертый разряд переданного числа. 
// Например, mid(123456)=345mid(123456)=345.
// Алгоритм, конечно, дурацкий и не выдерживающий никакой критики, но для практики работы со 
// стримами сойдет :)

// Пример

// pseudoRandomStream(13) должен вернуть стрим, состоящий из следующих чисел:

// 13, 16, 25, 62, 384, 745, 502, 200, 0, ... (дальше бесконечное количество нулей)


import java.util.stream.*;


public class sCreate {

    public static IntStream pseudoRandomStream(int seed) {
        IntStream stream = IntStream.iterate(seed, n -> (((n * n) / 10) % 1000));
        
        return stream;
    }
    
    public static void main(String[] args) {
        // Stream<Integer> streamFromIterate = Stream.iterate(1, n -> n + 2);
        // System.out.println("streamFromIterate = " + streamFromIterate.limit(3).collect(Collectors.toList()));
        
        pseudoRandomStream(13).forEach(System.out::println);
        
        // System.out.println((123456 / 10) % 1000);
    }
}
