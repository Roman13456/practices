//
// Created by User on 11.04.2023.
//

#ifndef PRACTICE_4_SET_H
#define PRACTICE_4_SET_H

class Set{
private:
    int num;
    int length;
    string symbols;
public:
    static int counter;
    Set(){
        length = 0;
        symbols = '\0';
    }
    Set(int length, char* arr):length(length){
        counter++;
        num = counter;
        symbols = arr;
        delete[] arr;
    };
    int getLength()const{
        return length;
    }
    int getNum()const{
        return num;
    }
    string getSymbols()const{
        return symbols;
    }
    void showSet(){
        cout<<num<<"-th element:"<<endl;
        cout<<"("<<symbols<<")";
        cout<<endl;
    }
    Set operator+(const Set obj){
        int initLength = length;
        int quantity = 0;
        char* tmp = new char[length+obj.getLength()+1];
        for(int i = 0; i < initLength; i++){
            tmp[i] = symbols[i];
        }
        int counter5 = length;
        for(int i = 0; i < obj.getLength(); i++){
            if(symbols.find(obj.getSymbols()[i]) == string::npos){
                quantity++;
                tmp[counter5] = obj.getSymbols()[i];
                counter5++;
            }
        }
        tmp[length+quantity] = '\0';
        return {length+quantity+1, tmp};
    }
    Set operator*(const Set obj){
        string first = symbols;
        string second = obj.getSymbols();
        char* tmp = new char[length+obj.getLength()+1];
        int counter1 = 0;
        for(int i = 0; i < obj.getLength(); i++){
            if(first.find(second[i]) != string::npos){
                tmp[counter1] = second[i];
                counter1++;
            }
        }
        tmp[counter1] = '\0';
        if(counter1){
            return {counter1, tmp};
        } else{
            cout<<"Empty set"<<endl;
            return {};
        }
    }
    Set operator-(const Set obj){
        string first = symbols;
        string second = obj.getSymbols();
        char* tmp = new char[length+1];
        int counter1 = 0;
        for(int i = 0; i < length; i++){
            if(second.find(first[i]) == string::npos){
                tmp[counter1] = first[i];
                counter1++;
            }
        }
        tmp[counter1] = '\0';
        if(counter1){
            return {counter1, tmp};
        } else{
            cout<<"Empty set"<<endl;
            return {};
        }
    }
};
int Set::counter = 0;

#endif //PRACTICE_4_SET_H
