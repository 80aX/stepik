// Реализуйте метод, который зачитает данные из InputStream и преобразует их в строку, 
// используя заданную кодировку.

// Пример

// InputStream последовательно возвращает четыре байта: 48 49 50 51.

// Метод, вызванный для такого InputStream и кодировки ASCII, должен вернуть строку "0123".


import java.io.*;
import java.nio.*;
import java.nio.charset.*;


public class readString {
    
    public static String readAsString(InputStream inputStream, Charset charset) throws IOException {
        
        StringBuilder builder = new StringBuilder();
        Reader r = new InputStreamReader(inputStream, charset);
        
        for (int i; (i = r.read()) != -1;) {
            char c = (char) i;
            builder.append(c);
        }
        
        return builder.toString();
    }
    
    
    public static void main(String[] args) {
        
        String result = new String("");
        byte[] b = {48, 49, 50, 51};
        
        // Reader reader = new InputStreamReader(b);
        ByteArrayInputStream byteStream = new ByteArrayInputStream(b);
        
        try {
            result = readAsString(byteStream, StandardCharsets.US_ASCII);
        } catch (IOException ex) {
            System.out.println(ex);
        }
        
        System.out.println("Result: " + result);
    }
}
