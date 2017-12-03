// Реализуйте метод, вычисляющий симметрическую разность двух множеств.

// Метод должен возвращать результат в виде нового множества. Изменять переданные в него 
// множества не допускается.

// Пример

// Симметрическая разность множеств {1, 2, 3} и {0, 1, 2} равна {0, 3}.


import java.util.*;


public class symmetricDiff {

    public static <T> Set<T> symmetricDifference(Set<? extends T> set1, Set<? extends T> set2) {
        
        Set<T> set3 = new HashSet<>();
        set3.addAll(set1);
        set3.addAll(set2);
        
        Iterator<T> it = set3.iterator();
        
        while (it.hasNext()) {
            T el = it.next();
            if (set1.contains(el) && set2.contains(el)) {
                it.remove();
            }
        }
        
        // Iterator<T> it1 = set1.iterator();
        // Iterator<T> it2 = set2.iterator();
        
        // while (it1.hasNext()) {
            // T element1 = it1.next();
            // if (!set2.contains(element1)) {
                // set3.add(element1);
            // }
        // }
        
        // while (it2.hasNext()) {
            // T element2 = it2.next();
            // if (!set1.contains(element2)) {
                // set3.add(element2);
            // }
        // }
        
        return set3;
    }
    
    // @Override
    // public int hashCode() {
        // return value.hashCode();
    // }
    
    
    public static void main(String[] args) {
        
        // int[] array1 = new int[] {1, 2, 3};
        // int[] array2 = new int[] {0, 1, 2};
        
        // Set<Integer> first = new HashSet(Arrays.asList(array1));
        // Set<Integer> second = new HashSet(Arrays.asList(array2));
        
        Set<Integer> first = new HashSet();
        Set<Integer> second = new HashSet();
        
        first.add(1);
        first.add(2);
        first.add(3);
        
        second.add(0);
        second.add(1);
        second.add(2);
        
        System.out.println(symmetricDifference(first, second));
    }
    
}
