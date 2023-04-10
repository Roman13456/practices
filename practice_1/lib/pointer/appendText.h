//
// Created by User on 09.03.2023.
//

#ifndef PRACTICE_1_APPENDTEXT_H
#define PRACTICE_1_APPENDTEXT_H

#endif //PRACTICE_1_APPENDTEXT_H
void appendText(char* fileName){
    FILE* fp = fopen(fileName,"a");
    char text[MAX_LINE_LENGTH];
    printf("Enter some text: \n");
    fflush(stdin);
    fgets(text, sizeof (text), stdin);//в кінці записує сивол нового рядка \n
    cout<<text<<endl;
    // Remove newline character at end of input
    text[strlen(text)-1] = '\0';
    fwrite(text, sizeof(char), strlen(text), fp);
    fclose(fp);
}

