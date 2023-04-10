//
// Created by User on 07.03.2023.
//

#ifndef PRACTICE_1_FIRSTFILE_H
#define PRACTICE_1_FIRSTFILE_H
#endif //PRACTICE_1_FIRSTFILE_H
#include "../clear.h"
#include "changePlaces.h"
#include "replaceSubstrStream.h"
#include "createFile.h"
#include "../checking/inputCheck2.h"
#include "downloadData.h"
#include "appendTextStream.h"
void fileNameFuncStream(string& fileName){
    printf("Enter file name: ");
    cin>>fileName;
}
void setBeforeReplacementsStream(string fileName){
    string outfileName = "new.txt";
    string outfile1Name = "new1.txt";
    ifstream infile(fileName);
    ofstream outfile(outfileName);
    ofstream outfile1(outfile1Name);
    if (outfile.is_open() && outfile1.is_open() && infile.is_open()) {
        replaceSubstrStream(infile,outfile,1);
        infile.clear();//щоб обнулити флажок кінця рядку
        infile.seekg(0, ios::beg);
        replaceSubstrStream(infile,outfile1,0);
        infile.close();
        outfile.close();
        outfile1.close();
        cout<<"До:"<<endl;
        downloadDataStream(fileName);
        cout<<"Після заміни БА на [БА-1], [БА-2]..:"<<endl;
        downloadDataStream(outfileName);
        cout<<"Після заміни БА на [1-БА], [2-БА]..:"<<endl;
        downloadDataStream(outfile1Name);
        //delete the original file and rename the temp file to the original file name
    }
    else {
        cout << "Failed to open file." << endl;
    }
}
void appStream(bool val, string filename) {
    int option;
    int boolean;
    int trigger = 0;
    string fileName;//= "../example.txt"
    if(val){
        trigger=1;
        fileName = filename;
    }
    printf("Menu: \nFile mode:        Records mode: \n");
    printf("0 - create file   2 - append text: \n");
    printf("1 - read file     3 - replace 'БА'\n");
    printf("4 - finish program\n");
    do {
        printf("Choose option(from the menu above): \n");
        do {
            fflush(stdin);
            boolean = intInput2(&option);
            if (!boolean) {
                printf("you have entered a symbol, try again\n");
            } else if (option < 0 || option > 4) {//9
                boolean = 0;
                printf("there is no such option, try again\n");
            }
        } while (!boolean);
        switch (option) {
            case 0:
                fileNameFuncStream(fileName);
                createFileStream(fileName, &trigger);
                break;
            case 1:
                if (trigger) {
                    downloadDataStream(fileName);
                } else {
                    fileNameFuncStream(fileName);
                    createFileStream(fileName, &trigger);
                }
                break;
            case 2:
                if (trigger) {
                    appendTextStream(fileName);
                } else {
                    fileNameFuncStream(fileName);
                    createFileStream(fileName, &trigger);
                }
                break;
            case 3:
                if (trigger) {
                    setBeforeReplacementsStream(fileName);
                } else {
                    fileNameFuncStream(fileName);
                    createFileStream(fileName, &trigger);
                }
                break;
            case 4:
                boolean = 0;
                break;

        }
    } while (boolean == 1);
}
