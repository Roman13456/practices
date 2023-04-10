//
// Created by User on 09.03.2023.
//

#ifndef PRACTICE_1_DOWNLOADDATA_H
#define PRACTICE_1_DOWNLOADDATA_H

#endif //PRACTICE_1_DOWNLOADDATA_H

void downloadDataStream( string fileName) {
    ifstream infile(fileName);
    if (!infile.is_open()) {
        printf("Error opening file.\n");
        return;
    }
    string line;
    fflush(stdin);
    while (getline(infile,line)) {
        cout<<line<<"\n";
    }
    cout<<endl;
    infile.close();
}