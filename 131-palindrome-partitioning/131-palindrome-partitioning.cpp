class Solution {
public:
    bool isPalindrome(string str){
        int li=0;
        int ri=str.length()-1;
        while(li<ri){
            char left=str[li];
            char right=str[ri];
            if(left!=right)
                return false;
            li++; ri--;
        }
        return true;
    }
    
    void solve(string str, vector<string> curr,vector<vector<string>>& answ)
    {
        if(str.length()<=0){
            cout<<"ppo";
            answ.push_back(curr);
            return;
        }
        for(int i=0;i<str.length();i++){
            string prefix = str.substr(0,i+1);
            string ros = str.substr(i+1);
            if(isPalindrome(prefix)){
                curr.push_back(prefix);
                solve(ros,curr,answ);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>>answ;
        vector<string>curr; 
        solve(s,curr,answ);
        return answ;
    }
};
/*
string s1=s;
        reverse(s1.begin(),s1.end())
        if(s==s1){
            answ.push_back(s);
            return;
        }
        
        rev(s);
        */