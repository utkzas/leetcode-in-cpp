#include<vector>
class Solution {
public:
    vector<string>codes={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
 
    vector<string> letterCombinationsH(string digits){
        vector<string> answ;

        if(digits.length()<=0){
            vector<string> base_string;
            base_string.push_back("");
            return base_string;
        }
        char ch=digits[0];
        string ros=digits.substr(1);
        
        vector<string>result=letterCombinationsH(ros);
        
        
        string curr_code=codes[ch-'1'];
        
        for(int i=0;i<curr_code.length();i++){
            char c=curr_code[i];
            for(string rstr:result){
             answ.push_back(c+rstr);   
            }
        }
        
        return answ;
    
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) {
            vector<string> dummy;
            return dummy;
        }
        return letterCombinationsH(digits);
    }
    
};