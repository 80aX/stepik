// Реализуйте generic-класс Pair, похожий на Optional, но содержащий пару элементов разных 
// типов и не запрещающий элементам принимать значение null.

// Реализуйте методы getFirst(), getSecond(), equals() и hashCode(), а также статический 
// фабричный метод of(). Конструктор должен быть закрытым (private).

// С корректно реализованным классом Pair должен компилироваться и успешно работать следующий код:

// Pair<Integer, String> pair = Pair.of(1, "hello");
// Integer i = pair.getFirst(); // 1
// String s = pair.getSecond(); // "hello"

// Pair<Integer, String> pair2 = Pair.of(1, "hello");
// boolean mustBeTrue = pair.equals(pair2); // true!
// boolean mustAlsoBeTrue = pair.hashCode() == pair2.hashCode(); // true!


// Пожалуйста, не меняйте модификатор доступа класса Pair. Для корректной проверки класс 
// должен иметь пакетную видимость.


class Pair <T, S> {
    
    private T first;
    private S second;

    private Pair(T first, S second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }
    public S getSecond() {
        return second;
    }

    public static <T, S> Pair<T, S> of(T first, S second) {
        return new Pair<T, S>(first, second);
    }

    @Override
    public boolean equals(Object obj) {
        
        if (obj == this)
            return true;
        
        if (obj == null || !(obj instanceof Pair))
            return false;

        Pair <T, S> otherPair = (Pair <T, S>) obj;

        if (first == null && otherPair.first != null
                || second == null && otherPair.second != null) {
            return false;
        }

        if (first == null && otherPair.first == null
                && second == null && otherPair.second == null) {
            return true;
        }

        return first.equals(otherPair.first) && second.equals(otherPair.second);
    }

    @Override
    public int hashCode() {
        int hash1 = first == null ? 0 : first.hashCode();
        int hash2 = second == null ? 0 : second.hashCode();

        return hash1 ^ hash2;
    }
    
    public static void main(String[] args) {
        
        Pair<Integer, String> pair = Pair.of(1, "hello");
        Integer i = pair.getFirst(); // 1
        String s = pair.getSecond(); // "hello"

        Pair<Integer, String> pair2 = Pair.of(1, "hello");
        boolean mustBeTrue = pair.equals(pair2); // true!
        boolean mustAlsoBeTrue = pair.hashCode() == pair2.hashCode(); // true!

        System.out.println(i);
        System.out.println(s);
        System.out.println(mustBeTrue);
        System.out.println(mustAlsoBeTrue);

        Pair<Integer, String> pair1 = Pair.of(null, null);
        System.out.println(pair1.equals(Pair.of(null, null)));
    }
}
