class Solution {
public:
    void miniDFS(int num,int i,vector<int>&answ){
    if(i>num)
        return;
    answ.push_back(i);
    for(int j=0;j<10;j++){
        miniDFS(num,10*i+j,answ);
    }
}
    vector<int> lexicalOrder(int n) {
       vector<int>answ;
       for(int i=1;i<=9;i++)
       miniDFS(n,i,answ);
        return answ;
    }
};

