class Solution {
public:
    void backtrack(vector<int>&candidates,int target,vector<vector<int>>&answ,vector<int> & combination,int start,int sum){
        if(sum==target){
            answ.push_back(combination);
            return;
        } else if(sum>target){
            return;
        }
        
        sort(candidates.begin(),candidates.end());
        for (int i = start; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == start || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], answ, combination, i + 1,sum);
                combination.pop_back();
            }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     vector<vector<int>> answ;
     vector<int> combination;
     backtrack(candidates,target,answ,combination,0,0);
        return answ;
    }
    
};