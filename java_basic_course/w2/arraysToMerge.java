// Реализуйте метод, сливающий два отсортированных по неубыванию массива чисел в один 
// отсортированный в том же порядке массив. Массивы могут быть любой длины, в том числе нулевой.

// Предполагается, что вы реализуете алгоритм слияния, имеющий линейную сложность: он будет 
// идти по двум исходным массивам и сразу формировать отсортированный результирующий массив. 
// Так, чтобы сортировка полученного массива при помощи Arrays.sort() уже не требовалась. 
// К сожалению, автоматически это не проверить, так что это остается на вашей совести :)

// Воспользуйтесь предоставленным шаблоном. Декларацию класса, метод main и обработку ввода-вывода 
// добавит проверяющая система.

// Пример

// Если на вход подаются массивы {0, 2, 2} и {1, 3}, то на выходе должен получиться массив 
// {0, 1, 2, 2, 3}


/**
 * Merges two given sorted arrays into one
 *
 * @param a1 first sorted array
 * @param a2 second sorted array
 * @return new array containing all elements from a1 and a2, sorted
 */

public class arraysToMerge {

    public static int[] mergeArrays(int[] a1, int[] a2) {
        int[] result = new int[a1.length + a2.length];
        int i = 0, j = 0;
        
        while (i + j < result.length) {
            if (j >= a2.length || (i < a1.length && a1[i] <= a2[j])) {
                result[i + j] = a1[i];
                i++;
            } else {
                result[i + j] = a2[j];
                j++;
            }
        }
        return result;
    }
    
    
    public static void main(String[] args) {
        int[] n1 = new int[] {0, 2, 2};
        int[] n2 = new int[] {1, 3};
        int[] finalArray = new int[n1.length + n2.length];
        
        finalArray = mergeArrays(n1, n2);
        for (int i = 0; i < finalArray.length; i++) {
            System.out.println(finalArray[i]);
        }
    }
}
