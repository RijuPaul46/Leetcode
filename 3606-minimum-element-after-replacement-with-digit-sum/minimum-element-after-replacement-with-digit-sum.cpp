class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mn=INT_MAX;
        for(auto &n:nums){
            mn=min(mn,digitsum(n));
        }
        return mn;
    }
};