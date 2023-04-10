//
// Created by User on 09.03.2023.
//

#ifndef PRACTICE_1_CREATEFILE_H
#define PRACTICE_1_CREATEFILE_H

#endif //PRACTICE_1_CREATEFILE_H


void createFileStream( string fileName, int *trigger) {
    ifstream infile(fileName);
    if(infile.good()){
        cout<<fileName<<" already exists, choose another name.\n";
    }else {
        infile.close();
        ofstream outfile(fileName);
        if (outfile.is_open()) {
            cout << fileName << " has been successfully created.\n";
            infile.close();
            *trigger = 1;
        }
    }
}