//
// Created by User on 09.03.2023.
//

#ifndef PRACTICE_1_DOWNLOADDARA_H
#define PRACTICE_1_DOWNLOADDARA_H
#endif //PRACTICE_1_DOWNLOADDARA_H

void downloadData( char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char line[MAX_LINE_LENGTH];
    fflush(stdin);
    while (fgets(line,MAX_LINE_LENGTH,fp)) {
        cout<<line<<"\n";
    }
    cout<<endl;
    fclose(fp);
}