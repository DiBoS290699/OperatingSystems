//
// Created by DiBoS on 26.03.2019.
//
#include <string>

using namespace std;

string decription(char* text) {
    const int KEY = 3;
    string newText = "";
    for(int i = 0; text[i] != '\0'; ++i){
        char ch = text[i];
        if(!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')){
            newText+=ch;
        }
        else {
            char newCh = (ch - KEY);
            newText += (ch < 'D' && ch >= 'A' || ch < 'd' && ch >= 'a') ? newCh + 26 : newCh;
        }
    }
    return newText;
}