#define ll long long
class Solution {
public:
    const ll m=1e9+7;
    const ll p=1e9+5;
    vector<ll> pwr;
    bool hasUnique(ll sz,vector<int>& nums){
        int n=nums.size();
        int l=0,i=0;
        ll x=0;
        for(i=0;i<sz;i++){
            x=(x+(nums[i]*pwr[sz-i])%m)%m;
        }
        unordered_map<ll,ll>mp;
        mp[x]++;
        while(i<n){
            x=((((x-(nums[l++]*pwr[sz])%m+m)%m)*p)%m+(nums[i++]*p)%m)%m;
            mp[x]++;
        }
        for(auto &[a,b]:mp){
            if(b==1)return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        pwr.resize(n+1);
        pwr[0]=1;
        for(int i=1;i<=n;i++){
            pwr[i]=(pwr[i-1]*p)%m;
        }
        int l=1;
        int r=n;
        while(l<r){
            int mid=l+(r-l)/2;
            if(hasUnique(mid,nums))r=mid;
            else l=mid+1;
        }
        return r;
    }
};