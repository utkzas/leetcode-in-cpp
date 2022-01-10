class Solution {
public:
    int solve(int n,int k){
        if(n==1)
            return 0;
        return (solve(n-1,k) +k)%n;
    }
    int findTheWinner(int n, int k) {
        return solve(n,k)+1; // 0 based index to 1 based
    }
};
// If I have the winner for 'n-1' and 'k'. I can find the winner for 'n' and 'k' by moving on to the next kth person (i.e. f(n) = f(n-1)+k). Keeping in mind that they are sitting on a round table we have to rotate also (i.e. f(n) = (f(n-1)+k)%n).