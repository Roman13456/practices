//
// Created by User on 07.03.2023.
//

#ifndef PRACTICE_1_CHANGEPLACES_H
#define PRACTICE_1_CHANGEPLACES_H

#endif //PRACTICE_1_CHANGEPLACES_H

void changePlaces(){
    ifstream infile("../example.txt");
    ofstream outfile("../new.txt");
    string substring_to_find = "БА";
    int counter = 1;
    int innerCounter = 1;
    string wordToReplace = "[БА-" + to_string(counter) + "]";
    string line;
    if (infile.is_open() && outfile.is_open()) {
        while (getline(infile, line)) {
            clear(&line,&innerCounter,substring_to_find);
            size_t pos = line.find(substring_to_find);
            while (pos != string::npos) {
                string new_word = "[" + to_string(counter) + "-БА]";
                line.replace(pos, substring_to_find.length(), new_word);
                pos = line.find(substring_to_find, pos + new_word.length()-1);
                counter+=1;
            }
            outfile << line << endl;
        }

        infile.close();
        outfile.close();
        //delete the original file and rename the temp file to the original file name
    }else{
        cout << "Failed to open file." << endl;
    }
}