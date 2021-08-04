#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str.length()==0)
    {cout<<asf<<endl;return;}
    
    for(int i=0;i<str.length();i++)
    {   char c=str[i];
        string leftpart=str.substr(0,i);
        string rightpart=str.substr(i+1);
    
        string ros=leftpart+rightpart;
        printPermutations(ros,asf+c);
    }
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}