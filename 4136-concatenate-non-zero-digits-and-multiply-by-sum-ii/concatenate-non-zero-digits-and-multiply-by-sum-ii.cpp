#define ll  long long
class Solution {
public:
    const ll m=1e9+7;
    ll pow(ll n,ll r){
        if(r==0)return 1;
        if(r%2==0)return pow((n*n)%m,r/2);
        return (n*pow((n*n)%m,r/2))%m;
    }
    ll modInv(ll n){
        return pow(n,m-2)%m;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        // vector<ll> suff(n+1);
        // vector<ll>dgt(n+1);
        // vector<ll> sm(n+1);
        // int digit=0;
        // for(int i=n-1;i>=0;i--){
        //     sm[i]=(sm[i+1]+(s[i]-'0'))%m;
        //     if(s[i]-'0'!=0){
        //         suff[i]=(suff[i+1]+((s[i]-'0')*pow(10,digit))%m)%m;
        //         digit++;
        //     }
        //     else{
        //         suff[i]=suff[i+1];
        //     }
        //     dgt[i]=digit;
        // }
        
        vector<ll>pre(n+1);
        vector<ll>sm(n+1);
        vector<int>cnt(n+1);
        for(int i=0;i<n;i++){
            if(s[i]-'0'!=0){
            pre[i+1]=((pre[i]*10)%m+(s[i]-'0'))%m;
            cnt[i+1]=cnt[i]+1;
            }
            else {pre[i+1]=pre[i];
            cnt[i+1]=cnt[i];
            }
            sm[i+1]=(sm[i]+(s[i]-'0'))%m;
        }
        int q=queries.size();
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=cnt[r+1]-cnt[l];
            ll sum=(sm[r+1]-sm[l]+m)%m;
            ll num=(pre[r+1]-(pre[l]*pow(10,k))%m+m)%m;
            ll mul=(sum*num)%m;
            ans[i]=(int)mul;
        }
        return ans;

        
    }
};