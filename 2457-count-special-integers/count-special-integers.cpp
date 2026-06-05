#define ll long long
class Solution {
public:
    // const int mx_num=(1<<10)+1;
    ll dp[10][2][(1<<10)+1][2];
    ll solve(int idx,int ldz,int num,int tight,string &tgt){
        int n=tgt.size();
        if(idx==n)return 1;
        if(dp[idx][ldz][num][tight]!=-1)return dp[idx][ldz][num][tight];
        int mx=tight?tgt[idx]-'0':9;
        ll ans=0;
        for(int i=0;i<=mx;i++){
            if((num>>i &1) ==0){
            int n_ldz=ldz&(i==0);
            int n_tight=tight&(i==mx);
            int n_num=num;
            if(ldz && i==0){}
            else n_num=num|(1<<i);
            ans=(ans+solve(idx+1,n_ldz,n_num,n_tight,tgt));
            }
        }
        return dp[idx][ldz][num][tight]=ans;
        
    }
    int countSpecialNumbers(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,1,0,1,s)-1;
    }
};