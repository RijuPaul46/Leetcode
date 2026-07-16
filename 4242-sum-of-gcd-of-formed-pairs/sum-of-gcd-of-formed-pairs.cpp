#define ll long long
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        ll maxi=nums[0];
        int n=nums.size();
        vector<ll>prefixGcd(n);
        for(int i=0;i<n;i++){
            maxi=max(maxi,1ll*nums[i]);
            prefixGcd[i]=gcd(maxi,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int l=0,r=n-1;
        ll ans=0;
        while(l<r){
            ans+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};