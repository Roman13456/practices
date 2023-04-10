//
// Created by User on 09.03.2023.
//

#ifndef PRACTICE_1_CREATEFILE_H
#define PRACTICE_1_CREATEFILE_H

#endif //PRACTICE_1_CREATEFILE_H

void createFile( char* fileName, int *trigger) {
    if(fopen(fileName, "r")!=NULL){
        printf("%s already exists, choose another name.\n",fileName);
    } else {
        FILE *fp = fopen(fileName, "wt");
        if (fp == NULL) {
            printf("Error creating file.\n");
            return;
        } else {
            printf("file, %s, has been successfully created.\n", fileName);
            fclose(fp);
            *trigger = 1;
            return;
        }
    }
}