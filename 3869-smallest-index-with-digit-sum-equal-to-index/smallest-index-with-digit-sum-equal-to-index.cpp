class Solution {
public:
    int sumofdigit(int n){
        string s=to_string(n);
        int sm=0;
        for(auto &c:s){
            sm+=(c-'0');
        }
        return sm;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(sumofdigit(nums[i])==i)return i;
        }
        return -1;
    }
};