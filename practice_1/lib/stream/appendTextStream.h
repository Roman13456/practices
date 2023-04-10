//
// Created by User on 09.03.2023.
//

#ifndef PRACTICE_1_APPENDTEXTSTREAM_H
#define PRACTICE_1_APPENDTEXTSTREAM_H

#endif //PRACTICE_1_APPENDTEXTSTREAM_H
void appendTextStream(string fileName){
    ofstream outfile(fileName,ios::app);
    string text;
    if(outfile.is_open()){
        printf("Enter some text: \n");
        fflush(stdin);
        getline(cin, text);
        cout<<text<<endl;
        outfile<<text;
        outfile.close();
    }else{
        cout<<"There was an error while opening file or the file doesn't exist\n";
    }

}