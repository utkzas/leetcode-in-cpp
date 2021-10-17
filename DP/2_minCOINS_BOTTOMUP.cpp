// ॐ नमः शिवाय 
// जय श्री राम
// हर- हर महादेव
#include<bits/stdc++.h>
using namespace std;
// PROBLEM - MIN COINS
// BOTTOM APPROACH 

int minCoins(int N, int coins[],int T) {
	int dp[100]={0};
	
	//Iterate over all states 1....n
	for(int n=1;n<=N;n++)
	{
	    //Init the current ans as int_max
	    dp[n]=INT_MAX;
	    for(int i=0;i<T;i++)
	    {
	        if(n-coins[i]>=0) {
	            int subprob = dp[n-coins[i]];
	            dp[n]=min(dp[n],subprob+1);
	        }
	    }
	}
	return dp[N];
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	#endif

    int N=15;
    int coins[]={1,7,10};
    
    int T=sizeof(coins)/sizeof(int);

    cout<<minCoins(N,coins,T)<<endl;

return 0;
}