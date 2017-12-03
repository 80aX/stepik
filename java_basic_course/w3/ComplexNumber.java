// Дан класс ComplexNumber. Переопределите в нем методы equals() и hashCode() так, 
// чтобы equals() сравнивал экземпляры ComplexNumber по содержимому полей re и im, а hashCode() был бы согласованным с реализацией equals().

// Реализация hashCode(), возвращающая константу или не учитывающая дробную часть re и im, засчитана не будет

// Пример

// ComplexNumber a = new ComplexNumber(1, 1);
// ComplexNumber b = new ComplexNumber(1, 1);
// a.equals(b) must return true
// a.hashCode() must be equal to b.hashCode()

// Подсказка 1. Поищите в классе java.lang.Double статический метод, который поможет в решении задачи.
// Подсказка 2. Если задача никак не решается, можно позвать на помощь среду разработки, которая умеет сама генерировать equals() и hashCode(). Если вы воспользовались помощью IDE, то разберитесь, что было сгенерировано и почему оно выглядит именно так. Когда вас на собеседовании попросят на бумажке реализовать equals() и hashCode() для какого-нибудь простого класса, то среда разработки помочь не сможет.


public final class ComplexNumber {
    private final double re;
    private final double im;

    public ComplexNumber(double re, double im) {
        this.re = re;
        this.im = im;
    }

    public double getRe() {
        return re;
    }

    public double getIm() {
        return im;
    }
    
    @Override
    public int hashCode() {
        int result = 1;
        result = Double.hashCode(getRe()) + Double.hashCode(getIm());
        return result;
    }
        
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        ComplexNumber other = (ComplexNumber) obj;
        if (getRe() != other.getRe())
            return false;
        if (getIm() != other.getIm())
            return false;
        return true;
    }
    
    public static void main(String[] args) {
        ComplexNumber object1 = new ComplexNumber(11, 11);
        ComplexNumber object2 = new ComplexNumber(11, 11);
        
        System.out.println("object1: " + object1);
        System.out.println("hashCode object1: " + object1.hashCode());
        System.out.println("object2: " + object2);
        System.out.println("hashCode object2: " + object2.hashCode());
        
        System.out.println("equals?: " + object1.equals(object2));
        System.out.println("hashCode equals?: " + 
                        (object1.hashCode() == object2.hashCode()));
    }
}
