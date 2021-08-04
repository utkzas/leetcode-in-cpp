#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    if(ques.length()==0)
    {
        cout<<ans<<endl; return;
    }
    char ch=ques[0];
    string roq=ques.substr(1);
    
    printSS(roq,ans+ch);
    printSS(roq,ans+"");
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}