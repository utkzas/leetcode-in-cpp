class Solution {
public:
    int n;
    
    void backtrack(vector<int>candidates, int target, vector<vector<int>>&answ, int start,vector<int>&combination,int sum){
        if(sum==target){
            answ.push_back(combination);
            return;
        } else if(sum>target) {
            return;
        }
        
    
        for(int i=start;i<n;i++){
            combination.push_back(candidates[i]);
            backtrack(candidates,target,answ,i,combination,sum+candidates[i]);
            combination.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>answ;
        vector<int>combination;
        n=candidates.size();
        backtrack(candidates,target,answ,0,combination,0);
        return answ;
    }
};