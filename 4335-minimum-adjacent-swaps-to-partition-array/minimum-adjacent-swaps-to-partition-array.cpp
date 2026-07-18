#define ll long long
class Solution {
public:
    const ll m=1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int two=0;
        int three=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x<a){
                ans=(ans+two+three)%m;}
            else if(x>b){
                three++;}
            else {
                two++;
                ans=(ans+three)%m;}
        }
       return (int)ans;
    }
};