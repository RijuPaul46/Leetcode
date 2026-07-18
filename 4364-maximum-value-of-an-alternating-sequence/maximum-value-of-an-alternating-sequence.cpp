#define ll long long
class Solution {
public:
    ll solve(int n,int s,int m){
        ll ans=1ll*s+1ll*(n/2)*m-(n-1)/2;
        return ans;
    }
    long long maximumValue(int n, int s, int m) {
        if(n==1)return 1ll*s;
        ll ans=max(solve(n,s,m),solve(n-1,s,m));
        return ans;
    }
};