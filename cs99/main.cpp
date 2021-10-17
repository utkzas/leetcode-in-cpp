// ॐ सह नाववतु ।
// सह नौ भुनक्तु ।
// सह वीर्यं करवावहै ।
// तेजस्वि नावधीतमस्तु मा विद्विषावहै ।
// ॐ शान्तिः शान्तिः शान्तिः ॥

// Qualification Round 2021 - Code Jam 2021
// Problem Name: Reversort


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
#define mod             1000000007
#define vi  vector<int>
#define vll vector<long long int>

int reversort(vi &L){
  int cost=0;
  for(int i=0;i<L.size()-1;i++){
    int m= *min_element(L.begin()+i,L.end()); 
    auto x= find(L.begin(), L.end(), m);

    reverse(L.begin()+i,x+1); // it works like [a,b) so take care of last index
    cost+= distance(L.begin(),x)-i+1;
  }
  return cost;
}

int main(){
    std::ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif

    int T;
    cin >> T;

    for(int c = 1; c < T+1; c++){

        int n;
        cin >> n;

        vi L;

        for(int j = 0; j < n; j++){
          int e;
          cin >> e;
          L.push_back(e);
        }

        cout << "Case #" << c << ": " << reversort(L) << endl;
    }

}
    
