class Solution {
public:
    using ll=long long;
    bool chck(vector<int>& coins,ll mid,int k){
        int n=coins.size();
        ll cnt=0;
        for(int i=1;i<(1<<n);i++){
            ll lc=1;
            int ct=__builtin_popcount(i);
            for(int j=0;j<n;j++){
                if(((i>>j) & 1) ==1)lc=lcm(lc,coins[j]);
            }
            cnt=cnt+((ct%2==0)?-1:1)*(mid/lc);
            
        }
        
        return cnt>=k;
    }
    
    long long findKthSmallest(vector<int>& coins, int k) {
       int n=coins.size();
       ll l=0;
       ll r=LLONG_MAX;
    ll ans=-1;
       while(l<=r){
        ll mid=l+1ll*(r-l)/2;
        if(chck(coins,mid,k)){
            ans=mid;
            r=1ll*mid-1;
        }else{
            l=1ll*mid+1;
        }
       } 
       return ans;
    }
};