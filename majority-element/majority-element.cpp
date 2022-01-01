class Solution {
public:
    
int validCandidate(vector<int> &arr) {
    int val = arr[0];
    int count = 1;
    for(int i = 1; i < arr.size(); i++) {
        if(val == arr[i]) {
            count++;
        } else {
            count--;
        }
        if(count == 0) {
            val = arr[i];
            count = 1;
        }
    }
    return val;
}
    int majorityElement(vector<int>& arr) {
        int val=validCandidate(arr);
        int count=0;
        for(int ele:arr){
            if(ele==val){
                count++;
            }
        }
        if(count>arr.size()/2)
        return val;
        return val;
    }
    

};