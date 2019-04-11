//
// Created by DiBoS on 26.03.2019.
//
#include <string>

using namespace std;

void encryption(string &text) {
    setlocale(LC_ALL, "rus");
    const int KEY = 3;
    string newText = "";
    for(int i = 0; text[i] != '\0'; ++i){
        char ch = text[i];
        if(!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')){
            newText += ch;
        }
        else {
            char newCh = (ch + KEY);
            newText += (ch > 'W' && ch <= 'Z' || ch > 'w' && ch <= 'z') ? newCh - 26 : newCh;
        }
    }
    text = newText;
}