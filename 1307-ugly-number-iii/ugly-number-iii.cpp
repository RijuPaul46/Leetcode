#define ll long long
class Solution {
public:

    bool check(ll tgt,ll a,ll b,ll c,ll k){
        ll ab=lcm(a,b);
        ll ac=lcm(a,c);
        ll bc=lcm(b,c);
        ll abc=lcm(lcm(a,b),c);
        ll cnt=0;
        cnt=cnt+tgt/a;
        cnt=cnt+tgt/b;
        cnt=cnt+tgt/c;
        cnt=cnt-tgt/ab;
        cnt=cnt-tgt/ac;
        cnt=cnt-tgt/bc;
        cnt=cnt+tgt/abc;
        return cnt>=k;

    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll low=0;
        ll high=1e18+1;
        ll ans=-1;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(check(mid,1ll*a,b*1ll,c*1ll,n*1ll)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};