//
// Created by User on 07.03.2023.
//

#ifndef PRACTICE_1_CLEAR_H
#define PRACTICE_1_CLEAR_H

#endif //PRACTICE_1_CLEAR_H
using namespace std;
void clear(string* line,int* counter, string substr){
    string new_word = "[БА-" + to_string(*counter) + "]";
    size_t pos = line->find(new_word);
    cout<<"iteration, pos:"<<pos<<"; counter: "<<*counter<<"\n";
    while (pos != string::npos) {
        cout<<"pos:"<<pos<<"\n";
        line->replace(pos, new_word.length(), substr);
        *counter+=1;
        cout<<"\ncounter:"<<*counter<<"\n";
        new_word = "[БА-" + to_string(*counter) + "]";
        pos = line->find(new_word, pos + substr.length());
    }
}