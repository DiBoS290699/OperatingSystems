//
// Created by DiBoS on 26.03.2019.
//
#include <string>

using namespace std;

string decription(char* text) {
    int key = 3;
    string newText = "";
    for(int i = 0; text[i] != '\0'; ++i){
        char ch = text[i];
        if(!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')){
            newText+=ch;
        }
        else if (ch >= 'A' && ch <= 'Z'){
            if(ch-key<'A'){
                newText+=ch-key+26;
            }
            else {
                newText+=ch-key;
            }
        }
        else if (ch >= 'a' && ch <= 'z'){
            if(ch-key<'a'){
                newText+=ch-key+26;
            }
            else {
                newText+=ch-key;
            }
        }
    }
    return newText;
}