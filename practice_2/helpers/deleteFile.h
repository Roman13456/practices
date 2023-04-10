//
// Created by User on 18.03.2023.
//

#ifndef PRACTICE_2_DELETEFILE_H
#define PRACTICE_2_DELETEFILE_H

#endif //PRACTICE_2_DELETEFILE_H
void deleteFile( string fileName,int *trigger) {
    if ( remove(fileName.c_str()) == 0) {
        printf("File has been successfully deleted.\n");
        *trigger = 0;
        return;
    } else {
        printf("Error deleting file.\n");
        return;
    }
}