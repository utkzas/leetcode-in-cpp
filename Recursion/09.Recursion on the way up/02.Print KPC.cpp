#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // write your code here
    
    if(ques.length()==0)
    {
        cout<<asf<<endl; return;
    }
    char ch=ques[0];
    string ros=ques.substr(1);
    
    string codeforch= codes[ch-'0'];
    
    for(int f=0;f<codeforch.length();f++)
    {
        char chcode=codeforch[f];
        printKPC(ros, asf+chcode);
    }
    
    
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}