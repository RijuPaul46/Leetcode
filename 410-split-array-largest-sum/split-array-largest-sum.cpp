class Solution {
public:
    // we can sense bs .... let x be the min answer 
    // we can easily make >x sum within k split
    bool check(vector<int>&nums,int k,int x){
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        if(mx>x)return false;
        int sm=0;
        int cnt=0;
        for(int i=0;i<n;i++){
           if((sm+nums[i])>x){
                cnt++;
                sm=nums[i];  
           }
           else sm+=nums[i];
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=1e9;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(nums,k-1,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};