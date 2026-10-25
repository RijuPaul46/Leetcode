class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0;
        int zero=0;
        int mx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)zero++;
            while(zero>k){
                if(nums[j]==0)zero--;
                j++;
            }
            mx=max(mx,i-j+1);
        }
        return mx;
    }
};