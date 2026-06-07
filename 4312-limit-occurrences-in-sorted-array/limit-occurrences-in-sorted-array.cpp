class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i;
            int cnt=1;
            while(j+1<n && nums[j+1]==nums[i]){
                j++;
                cnt++;
            }
            for(int x=0;x<min(k,cnt);x++)ans.push_back(nums[i]);
            i=j;
        }
        return ans;
        
    }
};