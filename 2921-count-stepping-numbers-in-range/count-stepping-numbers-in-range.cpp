#define ll long long
ll dp[102][2][2][10];
class Solution {
public:
    const ll m=1e9+7;
    string subtractOne(string &s) {
    int n = s.size();

    int i = n - 1;

    while (i >= 0) {
        if (s[i] > '0') {
            s[i]--;
            break;
        }

        s[i] = '9';
        i--;
    }
    int pos = 0;
    while (pos + 1 < s.size() && s[pos] == '0')
        pos++;

    return s.substr(pos);
}
    ll solve(int idx,int tight,int ldz,int prev,string & tgt){
        int n=tgt.size();
        if(idx==n)return 1;
        if(dp[idx][tight][ldz][prev]!=-1)return dp[idx][tight][ldz][prev];
        int limit=tight?(tgt[idx]-'0'):9;
        ll ans=0;
        if(ldz){
            for(int i=0;i<=limit;i++){
            int n_tight=tight&(i==limit);
            int n_ldz=ldz&(i==0);
            ans=(ans+solve(idx+1,n_tight,n_ldz,i,tgt))%m;
            }
            return dp[idx][tight][ldz][prev]=ans;
        }
        int first=prev-1;
        int second=prev+1;
        if(first>=0 && first<=limit){
            int n_tight=tight&(first==limit);
            int n_ldz=ldz&(first==0);
            ans=(ans+solve(idx+1,n_tight,n_ldz,first,tgt))%m;
        }
        if(second<=limit && second>=0){
            int n_tight=tight&(second==limit);
            int n_ldz=ldz&(second==0);
            ans=(ans+solve(idx+1,n_tight,n_ldz,second,tgt))%m;
        }
        return dp[idx][tight][ldz][prev]=ans;
    }
    int countSteppingNumbers(string low, string high) {

        ll h=0;
        memset(dp,-1,sizeof(dp));
        h=solve(0,1,1,0,high);
        string req=subtractOne(low);
        ll l=0;
        memset(dp,-1,sizeof(dp));
        l=solve(0,1,1,0,req);
        return (int)(h-l+m)%m;
    }
}; 