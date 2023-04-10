#ifndef PRACTICE_1_FIRSTFILE_H
#define PRACTICE_1_FIRSTFILE_H
#endif //PRACTICE_1_FIRSTFILE_H


#include <stdio.h>
#include <string.h>
#include "../checking/inputCheck.h"
#include "replaceSubstr.h"
#include "appendText.h"
#include "downloadData.h"
#include "createFile.h"
void clear(char* str, int* count, const char* substr) {
    char *p = str;
    while ((p = strstr(p, substr))) {
        *p = '\0';
        strcat(str, substr);
        *count += 1;
        p += strlen(substr);
    }
}
void fileNameFunc(char *fileName){
    printf("Enter file name: ");
    scanf("%s", fileName);
}
void setBeforeReplacements(char* fileName) {
    char toReplace[] = "[%s-%d]";
    char substring_to_find[] = "БА";
    char newFile0[] = "new.txt";
    char newFile1[] = "new1.txt";
    char toReplace1[] = "[%d-%s]";
    FILE* infile = fopen(fileName, "r+");
    FILE* outfile = fopen(newFile0, "w");
    FILE* outfile1 = fopen(newFile1, "w");
    if (infile != NULL && outfile != NULL && outfile1 != NULL) {
        fseek(infile,SEEK_SET,0);
        replaceSubstr(infile,outfile,substring_to_find,toReplace,1);
        fseek(infile,SEEK_SET,0);
        replaceSubstr(infile,outfile1,substring_to_find,toReplace1,0);
        fclose(infile);
        fclose(outfile);
        fclose(outfile1);
        cout<<"До:"<<endl;
        downloadData(fileName);
        cout<<"Після заміни БА на [БА-1], [БА-2] (new.txt):"<<endl;
        downloadData(newFile0);
        cout<<"Після заміни БА на [1-БА], [2-БА] (new1.txt):"<<endl;
        downloadData(newFile1);
    } else {
        printf("Failed to open file.\n");
    }
}
void appPointer(bool val, char *filename) {
    int option;
    int boolean;
    int trigger = 0;
    char fileName[MAX_LINE_LENGTH];//= "../example.txt"
    if(val){
        trigger=1;
        strcpy(fileName, filename);
    }
    printf("Menu: \nFile mode:        Records mode: \n");
    printf("0 - create file   2 - append text: \n");
    printf("1 - read file     3 - replace 'БА'\n");
    printf("4 - finish program\n");
    do {
        printf("Choose option(from the menu above): \n");
        do {
            fflush(stdin);
            boolean = intInput(&option);
            if (!boolean) {
                printf("you have entered a symbol, try again\n");
            } else if (option < 0 || option > 4) {//9
                boolean = 0;
                printf("there is no such option, try again\n");
            }
        } while (!boolean);
        switch (option) {
            case 0:
                fileNameFunc(fileName);
                createFile(fileName, &trigger);
                break;
            case 1:
                if (trigger) {
                    downloadData(fileName);
                } else {
                    fileNameFunc(fileName);
                    createFile(fileName, &trigger);
                }
                break;
            case 2:
                if (trigger) {
                    appendText(fileName);
                } else {
                    fileNameFunc(fileName);
                    createFile(fileName, &trigger);
                }
                break;
            case 3:
                if (trigger) {
                    setBeforeReplacements(fileName);
                } else {
                    fileNameFunc(fileName);
                    createFile(fileName, &trigger);
                }
                break;
            case 4:
                boolean = 0;
                break;

        }
    } while (boolean == 1);
}





