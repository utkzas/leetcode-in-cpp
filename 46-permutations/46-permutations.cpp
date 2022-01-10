class Solution {
public:
    void dfs(int pos, vector<int> &num, vector<vector<int>> &result){
    if(pos == num.size()){
        result.push_back(num);
    }
    else{
        for(int i=pos; i<num.size(); i++){
            swap(num[i], num[pos]);
            dfs(pos+1, num, result);
            swap(num[i], num[pos]);
        }
    }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>answ;
        dfs(0,nums,answ);
        return answ;
    }
};
// didnt get this one, tired YT, Random leetcode discuss solns, a lot of things but i think i need a strong empire, for which, i need time. i am not getting that time