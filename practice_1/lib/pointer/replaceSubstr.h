//
// Created by User on 09.03.2023.
//

#include <cstdio>
//#include "../clear.h"
#ifndef PRACTICE_1_REPLACESUBSTR_H
#define PRACTICE_1_REPLACESUBSTR_H
#endif //PRACTICE_1_REPLACESUBSTR_H


void replaceSubstr(FILE* infile, FILE* outfile, char *substring_to_find, char* toReplace, int flag){
    int counter = 1;
    int innerCounter = 1;
    char line[MAX_LINE_LENGTH];
    char new_word[MAX_LINE_LENGTH];

        while (fgets(line, MAX_LINE_LENGTH, infile)) {
//            printf("before:%s", line);
//            clear(line, &innerCounter, substring_to_find);
//            printf("after:%s", line);

            char* pos = strstr(line, substring_to_find);
            while (pos != NULL) {
                flag?(snprintf(new_word, MAX_LINE_LENGTH, toReplace, substring_to_find, counter))
                :(snprintf(new_word, MAX_LINE_LENGTH, toReplace, counter, substring_to_find ));
                int start = pos - line;
                int length = strlen(substring_to_find);
                memmove(pos + strlen(new_word), pos + length, strlen(line) - start - length+1);//символ кінця рядка
                memcpy(pos, new_word, strlen(new_word));
                pos = strstr(pos + strlen(new_word), substring_to_find);//pos + strlen(new_word) це те саме ще адреса першого символа знайденоъ підстроки+кількість символів півстроки на яку ми замінили
                counter += 1;
            }
//            cout<<"text: "<<line<<endl;
            fprintf(outfile, "%s", line);//записати строку в файл(так буде з кожною)
        }

}