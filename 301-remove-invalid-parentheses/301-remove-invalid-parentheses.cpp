class Solution {
public:
    vector<string>answ;
    unordered_map<string,int>mapp; // to remove duplications
    int getMinimumRemovals(string s){
        stack<char>stackk;
        for(int i=0;i<s.length();i++){
            char ch= s[i];
            if(ch=='('){
                stackk.push(ch);
            } else if(ch==')'){
                if(stackk.size()==0){
                    stackk.push(ch); // invalid hai, push hoja ab
                } else if(stackk.top()==')') {
                    stackk.push(ch); // ab bhi invalid hai, push hoja ab bhi
                } else if(stackk.top()=='('){
                    stackk.pop(); // mil gaya !! jao pair bana lo
                }
            }
        }
        return stackk.size();
    }
    void solve(string s, int minimumRemovals){
        //to remove duplication
        if(mapp[s]!=0)
            return;
        else
            mapp[s]++;
        
        if(minimumRemovals<0) return;
        if(minimumRemovals==0){
            if(!getMinimumRemovals(s))
                answ.push_back(s);
            return;
        }
        for(int i=0;i<s.size();i++){
            string left= s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right,minimumRemovals-1);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        int minimumRemovals=getMinimumRemovals(s);
        solve(s,minimumRemovals);
        return answ;
    }
};