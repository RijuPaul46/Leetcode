#define ll long long
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        ll ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll nr=1ll*nums[i]*nums[j];
                ll dr=1ll*gcd(nums[i],nums[j])*gcd(nums[i],nums[j]);
                ll str=nr/dr;
                ans=max(ans,str);
            }
        }
        return ans;
    }
};