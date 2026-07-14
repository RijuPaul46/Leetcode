#define ll long long 
class Solution {
public:
    const ll m=1e9+7;
    ll dp[201][201][201];
    ll solve(int idx,int g1,int g2,vector<int>& nums){
        int n=nums.size();
        if(idx==n){
            return g1==g2;
        }
        // take this elem in g1
        auto &ref=dp[idx][g1][g2];
        if(ref!=-1)return ref;
        int a=gcd(g1,nums[idx]);
        int b=gcd(g2,nums[idx]);
        ll seq1=solve(idx+1,a,g2,nums);
        ll seq2=solve(idx+1,g1,b,nums);
        ll skip=solve(idx+1,g1,g2,nums);
        return ref=(seq1+seq2+skip)%m;

    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        ll ans=solve(0,0,0,nums)-1;
        return (int)ans;
    }
};