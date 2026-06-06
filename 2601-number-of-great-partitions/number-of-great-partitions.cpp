#define ll long long
class Solution {
public:
    const ll m=1e9+7;
    // ll solve(int idx,ll sumA,ll sumB,int k,vector<int>& arr,vector<unordered_map<ll,ll>> &dp){
    //     int n=arr.size();
    //     ll checkA=min(1ll*k,sumA);
    //     ll checkB=min(1ll*k,sumB);
    //     if(idx==n){
    //         if(sumA>=k && sumB>=k)return 1;
    //         return 0;
    //     }
    //     if(dp[idx].count(checkA))return dp[idx][checkA];
    //     int cnt=1;
    //     int i=idx+1;
        
    //     //take in A
    //     ll ans=0;
    //     ll nextA=(sumA+cnt*arr[idx])%m;
    //     ans=(ans+(1ll*solve(i,nextA,sumB,k,arr,dp))%m)%m;
    //     //take in B
    //     ll nextB=(sumB+cnt*arr[idx])%m;
    //     ans=(ans+(1ll*solve(i,sumA,nextB,k,arr,dp))%m)%m;
    //     return dp[idx][checkA]=(1ll*ans)%m;
    // }
    // ll pow(ll b,ll r){
    //     if(r==0)return 1;
    //     if(r%2==0)return (pow((b*b)%m,r/2))%m;
    //     return (b*(pow((b*b)%m,r/2))%m)%m;
    // }
    ll solve(vector<int>& nums, int k,int idx,int sum,vector<vector<ll>> &dp){
        int n=nums.size();
        if(sum>=k)return 0;
        if(idx==n){
            if(sum<k)return 1;
            else return 0;
        }
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        //take that 
        ll ans=0;
        ans=(ans+solve(nums,k,idx+1,sum+nums[idx],dp))%m;
        //skip
        ans=(ans+solve(nums,k,idx+1,sum,dp))%m;
        return dp[idx][sum]=ans;
    }
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        if(sum < 2*k)
        return 0;
        vector<vector<ll>> dp(n,vector<ll>(k,-1));
        ll total=1;
        for(auto & num:nums){
            total=(total*2)%m;
        }
        ll bad=solve(nums,k,0,0,dp);
        ll ans=(total-(2*bad)%m+m)%m;
        return (int)ans;

    }
};