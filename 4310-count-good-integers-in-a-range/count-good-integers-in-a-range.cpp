#define ll long long
class Solution {
public:
    ll dp[16][2][2][10];
    ll solve(int idx,int ldz,int tight,string & tgt,int k,int prev){
        int n=tgt.size();
        if(idx==n)return 1;
        auto & ref=dp[idx][ldz][tight][prev];
        if(ref!=-1)return ref;
        int limit=tight?(tgt[idx]-'0'):9;
        ll ans=0;
        for(int i=0;i<=limit;i++){
            if(ldz){
                int nldz=ldz&&i==0;
                int ntight=tight&(i==limit);
                ans+=solve(idx+1,nldz,ntight,tgt,k,i);
            }
            else if(abs(prev-i)<=k){
                int nldz=ldz&&i==0;
                int ntight=tight&(i==limit);
                ans+=solve(idx+1,nldz,ntight,tgt,k,i);
            }
        }
        return ref=ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        string s1=to_string(r);
        ll ans1=0;
        int limit1=s1[0]-'0';
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=limit1;i++){
            int ldz=(i==0);
            int tight=(i==limit1);
            ans1+=solve(1,ldz,tight,s1,k,i);
        }
        ll ans2=0;
            string s2=to_string(l-1);
            int limit2=s2[0]-'0';
            memset(dp,-1,sizeof(dp));
            for(int i=0;i<=limit2;i++){
                int ldz=(i==0);
                int tight=(i==limit2);
                ans2+=solve(1,ldz,tight,s2,k,i);
            }
        
        return ans1-ans2;
    }
};