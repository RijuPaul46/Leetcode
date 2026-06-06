#define ll long long
ll dp[24][2][2][401];
class Solution {
public:
    const ll m=1e9+7;
    ll solve(int idx,int ldz,int tight,int sum,string &tgt,int mn,int mx){
        int n=tgt.size();
        if(sum>mx)return 0;
        if(idx==n){
            if(sum<=mx && sum>=mn)return 1;
            return 0;
        }
        if(dp[idx][ldz][tight][sum]!=-1)return dp[idx][ldz][tight][sum];
        ll ans=0;
        int limit=tight?(tgt[idx]-'0'):9;
        for(int i=0;i<=limit;i++){
            int n_ldz=ldz&(i==0);
            int n_tight=tight&(i==limit);
            int n_sum=sum+i;
            ans=(ans+solve(idx+1,n_ldz,n_tight,n_sum,tgt,mn,mx))%m;
        }
        return dp[idx][ldz][tight][sum]=ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        ll low=solve(0,1,1,0,num1,min_sum,max_sum);
        memset(dp,-1,sizeof(dp));
        ll high=solve(0,1,1,0,num2,min_sum,max_sum);
        ll cnt=0;
        ll sum=0;
        for(auto &c:num1){
            sum+=(c-'0');
        }
        if(sum>=min_sum && sum<=max_sum)cnt++;
        return (int)(high-low+cnt+m)%m;
    }
};