/*
//Template
void Backtrack(int start)
{
    //Base case 

// loop for all possible values
{
    //include the current element at this position if possible in the ans 
	//More generally, make a choice 

    Backtrack(start+1) 

    //backtrack by removing current element 
}
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int> subset;
        n=a.size();
        
        sort(a.begin(),a.end()); //sort the elements so that we can keep track of duplicates
        GenerateSubs(a,0,subset,ans);
        return ans;    
    }
private:
    int n;
    void GenerateSubs(vector<int>&a,int s,vector<int>&subset,vector<vector<int>>&ans)
    {
        for(int i=s;i<n;i++)
        {
            if(i==s||a[i]!=a[i-1]) 
            {
              subset.push_back(a[i]); //include element at ith position
              GenerateSubs(a,i+1,subset,ans); //generate all subsets including ith element
              subset.pop_back(); //backtrack
            }
        }
        ans.push_back(subset);
    }
};