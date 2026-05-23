#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<ll,ll>> dp(n);
        vector<int>f(n+1);
        
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                ll d=1ll*nums[i]-1ll*nums[j];
                ans+=dp[j][d];
                dp[i][d]+=dp[j][d]+1;
            }
           
        }
        return ans;
    }
};