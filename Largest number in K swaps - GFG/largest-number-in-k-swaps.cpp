// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    void swap(string& str,int i,int j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    char getMax(string& str,int start)
    {
        char m = 0;
        
        for(int i=start;i<str.size();i++)
            m = max(m,str[i]);
            
        return m;
    }
    void help(string& str,int k,int start,string& max)
    {
        if(str > max)
            max = str;
            
        if(!k || start == str.size())
            return;
            
        char m = getMax(str,start);
        
        if(str[start] == m)
            help(str,k,start+1,max);
            
        else
        {
            for(int i=start+1;i<str.size();i++)
            {
                if(str[i] == m)
                {
                    swap(str,start,i);
                    help(str,k-1,start+1,max);
                    swap(str,start,i);
                }
            }
        }
    }
    
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string& str, int k)
    {
       // code here.
       string max = "";
       
       help(str,k,0,max);
       
       return max;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends