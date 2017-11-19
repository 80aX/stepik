// Напишите функцию поиска первого вхождения шаблона в текст. В качестве
// первого параметра функция принимает текст (C-style строка), в которой
// нужно искать шаблон. В качестве второго параметра строку-шаблон (C-style
// строка), которую нужно найти. Функция возвращает позицию первого вхождения
// строки-шаблона, если он присутствует в строке (помните, что в C++ принято
// считать с 0), и -1, если шаблона в тексте нет. 
// 
// Учтите, что пустой шаблон (строка длины 0) можно найти в любом месте текста. 
// 
// Требования к реализации: при выполнении данного задания вы можете определять
// любые вспомогательные функции, если они вам нужны. Вводить или выводить
// что-либо не нужно. Реализовывать функцию main не нужно.
// Нажмите, чтобы начать решать ✍


#include <iostream>

int strstr(const char *text, const char *pattern) {
    int len_text = 0;
    int len_pattern = 0;
    int cnt = 0;
    int i = 0;
    int j = 0;
    
    for (i = 0; text[i] != '\0'; ++i) 
        len_text += 1;
    
    for (i = 0; pattern[i] != '\0'; ++i)
        len_pattern += 1;
    
    if (len_pattern == 0)
        return 0;
    
    if (len_pattern > len_text)
        return -1;
    
    for (i = 0; i <= (len_text - len_pattern); ++i) {
        if (text[i] == pattern[j]) {
            cnt = 0;
            for (j = 0; j < len_pattern; ++j) {
                if (text[i + j] == pattern[j]) 
                    cnt += 1;
                else 
                    break;
            }
            if (cnt == len_pattern) 
                return i;
            else 
                j = 0;
        }
    }
    return -1;
}

int main(void) {
    const char t[] = "abcdefefgh";
    const char p[] = "efgh";
    std::cout << strstr(t, p) << std::endl;
    return 0;
}
