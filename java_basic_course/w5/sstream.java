// Напишите метод, читающий входной поток и вычисляющий контрольную сумму прочитанных данных.

// Контрольная сумма данных вычисляется по следующему алгоритму:

// Контрольная сумма представляет собой число типа int. Контрольная сумма пустого набора данных 
// равна нулю.
// Контрольная сумма непустого набора данных вычисляется по следующей рекуррентной формуле: 
// C(n+1)=rotateLeft(Cn) xor b(n+1)C(n+1)=rotateLeft(Cn) xor b(n+1) , где Cn — контрольная сумма 
// первых n байт данных, rotateLeft — циклический сдвиг бит числа на один бит влево (чтобы не 
// изобретать велосипед, используйте Integer.rotateLeft), bnbn — n-ный байт данных.
// Поскольку метод не открывал данный InputStream, то и закрывать его он не должен. Выброшенное 
// из методов InputStream исключение должно выбрасываться из метода.

// Пример
// На вход подан InputStream, последовательно возвращающий три байта: 0x33 0x45 0x01. В качестве 
// контрольной суммы должно быть возвращено число 71.


import java.io.*;


public class sstream {

    public static int checkSumOfStream(InputStream inputStream) throws IOException {
        int sum = 0;
        int c = 0;
        
        while ((c = inputStream.read()) != -1) {
            sum = Integer.rotateLeft(sum, 1) ^ c;
        }
        return sum;
    }
    
    public static InputStream getStream(byte [] data)  {
        return new ByteArrayInputStream (data);
    }
    
    public static void main(String[] args) throws IOException {
        InputStream inp = new ByteArrayInputStream (new byte[] {0x33, 0x45, 0x01});
        System.out.print(checkSumOfStream(inp));
    }
}
