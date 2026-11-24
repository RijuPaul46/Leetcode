class Solution {
public:
    #define ll long long
    //lcm(a,b,c)=lcm(lcm(a,b),c)
    //same for gcd also
    ll lcm(ll a, ll b){
        return (a*b)/gcd(a,b);
    } 
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ll prdt=1,_lcm=1,_gd=0;
            for(int j=i;j<n;j++){
                prdt*=1ll*nums[j];
                
                _lcm=lcm(_lcm,nums[j]);
                _gd=gcd(_gd,nums[j]);
                if(prdt>(_gd*_lcm))break;
                if(prdt==(_lcm*_gd)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};