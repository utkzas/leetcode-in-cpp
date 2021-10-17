// ॐ नमः शिवाय 
// जय श्री राम
// हर- हर महादेव
#include<bits/stdc++.h>
using namespace std;
// PROBLEM - MIN COINS
// TOP DOWN APPROACH 

int minCoins(int n, int coins[],int T,int dp[]) {
	//BaseCase
	if(n==0)
    return 0;
	//LookUp
	if(dp[n]!=0)
	return dp[n];
	//Rec Case
	int ans=INT_MAX;
	for(int i=0;i<T;i++) {
		if(n-coins[i]>=0) {
			int subprob=minCoins(n-coins[i],coins,T,dp);
			ans=min(ans,subprob+1);
		}
	} 
	dp[n]=ans;
	return dp[n];
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	#endif

    int N=15;
    int coins[]={1,7,10};
    int dp[100]={0};
    int T=sizeof(coins)/sizeof(int);

    cout<<minCoins(N,coins,T,dp)<<endl;

return 0;
}