#define ll long long
class Solution {
public:
    ll dp[10][10][10][20][2][2];
    ll solve(int idx,int ec,int oc,int rem,int tight,int ldz,string& tgt,int k){
        int n=tgt.size();
        if(idx==n){
            if(ec==oc && rem==0)return 1;
            else return 0;
        }
        if(dp[idx][ec][oc][rem][tight][ldz]!=-1)return dp[idx][ec][oc][rem][tight][ldz];
        int mx=tight?tgt[idx]-'0':9;
        ll ans=0;
        for(int i=0;i<=mx;i++){
            int n_tight=tight&(i==mx);
            int n_ldz=ldz&(i==0);
            int n_rem=(rem*10+i)%k;
            int n_ec = ec ;
            int n_oc = oc ;
            if(!n_ldz){
                n_ec = ec + ((i%2)==0);
                n_oc = oc + ((i%2)==1);
            }
            
            ans+=solve(idx+1,n_ec,n_oc,n_rem,n_tight,n_ldz,tgt,k);
        }
        return dp[idx][ec][oc][rem][tight][ldz]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s1=to_string(high);
        memset(dp,-1,sizeof(dp));
        int h=solve(0,0,0,0,1,1,s1,k);
        memset(dp,-1,sizeof(dp));
        string s2=to_string(low-1);
        int l=solve(0,0,0,0,1,1,s2,k);
        return h-l;
        
    }
};