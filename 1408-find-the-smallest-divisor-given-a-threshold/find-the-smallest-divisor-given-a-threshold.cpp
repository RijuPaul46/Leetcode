class Solution {
public:
    bool check(vector<int>&arr,int threshold,int divisor){
        int sm=0;
        for(auto &x:arr){
            sm+=ceil((double)x/(double)divisor);
        }
        return sm<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,h=1e6;
        int ans=1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(nums,threshold,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};