#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
vector<string> codes = {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
vector<string> getKPC(string str)
{   int n=str.size();
    if(n==0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    
    char ch=str[0];
    
    string ros = str.substr(1);//baad wali string
    vector<string> rres=getKPC(ros);
    vector<string> mres;
    
    string codeforch=codes[ch-'0'];
    
    for(int i=0;i<codeforch.length();i++)
    {
        char chcode = codeforch[i];
        for(string rstr: rres)
        {
            mres.push_back(chcode+rstr);
        }
    }
    return mres;
}
int main(){
    string s;
    cin >> s;
    vector<string> ans = getKPC(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}