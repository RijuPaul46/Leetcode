class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(auto&x:nums){
            mx=max(mx,x);
            mn=min(mn,x);
        }
        return gcd(mx,mn);
    }
};