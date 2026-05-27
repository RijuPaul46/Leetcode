#define ll long long
class Solution {
public:
    const int mod=1e9+7;
    int numTilings(int n) {
        if(n<=2)return n;
        vector<ll>f(n+1);
        f[0]=1;
        f[1]=1;
        f[2]=2;
        for(int i=3;i<=n;i++){
            ll total=(f[i-1]+f[i-2])%mod;
            for(int j=i-3;j>=0;j--){
                total=(total+2*f[j])%mod;
            }
            f[i]=total;
        }
        return (int)f[n];
    }
};