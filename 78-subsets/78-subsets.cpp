class Solution {
public:
    void GenerateSubs(vector<int>nums,int n, vector<int>subset,vector<vector<int>>&answ,int start){
        for(int i=start;i<n;i++){
            subset.push_back(nums[i]);
            GenerateSubs(nums,n,subset,answ,i+1);
            subset.pop_back(); // backtrack
        }
        answ.push_back(subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>answ;
        vector<int> subset;
        int n=nums.size();
        GenerateSubs(nums,n,subset,answ,0);
        return answ;
    }
};