class Solution {
    void permutations(vector<vector<int>>& res, vector<bool>& visited, vector<int>& data,vector<int>& nums)
    {
        if(data.size() == nums.size())
        {
            res.push_back(data);
            return;
        }
        unordered_map<int,bool> map;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!visited[i] and map.find(nums[i]) == map.end())
            {
                data.push_back(nums[i]);
                visited[i] = true;
                permutations(res,visited,data,nums);
                data.pop_back();
                visited[i] = false;
                map[nums[i]] = true;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
         vector<vector<int>> res;
         vector<int> data;
         vector<bool> visited(nums.size(),false);
         permutations(res,visited,data,nums);
         return res;
    }
};