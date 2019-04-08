//
// Created by DiBoS on 26.03.2019.
//
#include <string>

using namespace std;

void encryption(string &text) {
    int key = 3;
    string newText = "";
    for(int i = 0; text[i] != '\0'; ++i){
        char ch = text[i];
        if(!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')){
            newText += ch;
        }
        else if (ch >= 'A' && ch <= 'Z'){
            ch += (key % 26);
            if (ch > 'Z')
                ch -=26;
            newText+=ch;
        }
        else if (ch >= 'a' && ch <= 'z'){
            ch +=(key%26);
            if (ch > 'z')
                ch -= 26;
            newText+=ch;
        }
    }
    text = newText;
}