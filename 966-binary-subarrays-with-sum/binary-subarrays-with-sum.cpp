class Solution {
public:
    // by two pointer approach we can easily calculate number of subarray having sum<=x easily ... because we shrink the left pointer untill the sum>goal ... so we stop at the largest subarray having sum=goal so all inside subarray will have sum<=goal ...and for our answer we can do 
    // no of subarray with sum<=goal - no of subarray with sum<=goal-1 
    int subarray(vector<int>&nums,int goal){
        int n=nums.size();
        int l=0;
        int sm=0;
        int cnt=0;
        for(int r=0;r<n;r++){
            sm+=nums[r];
            while(sm > goal && l<r){
                sm-=nums[l++];
            }
            if(sm <=goal)
            cnt+=(r-l+1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a=subarray(nums,goal);
        int b=0;
        if((goal-1) >=0)
        b=subarray(nums,goal-1);
        return a-b;
    }
};