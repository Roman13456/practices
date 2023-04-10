//
// Created by User on 09.03.2023.
//

#ifndef PRACTICE_1_REPLACESUBSTRSTREAM_H
#define PRACTICE_1_REPLACESUBSTRSTREAM_H

#endif //PRACTICE_1_REPLACESUBSTRSTREAM_H
void replaceSubstrStream( ifstream &infile, ofstream &outfile, int flag){
    int counter = 1;
    string substring_to_find = "БА";
    string line;
    while (getline(infile, line)) {
        size_t pos = line.find(substring_to_find);
        while (pos != string::npos) {
            string new_word = flag?("[БА-" + to_string(counter) + "]"):("[" + to_string(counter) + "-БА]")  ;
            line.replace(pos, substring_to_find.length(), new_word);
            pos = line.find(substring_to_find, pos + new_word.length()-1);
            counter+=1;
        }
        outfile << line << endl;
    }
    infile.seekg(0, ios::beg);
}