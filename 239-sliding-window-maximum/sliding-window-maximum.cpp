class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int>ans;
        int j=0;
        for(int i=0;i<n;i++){
            
                while(!dq.empty() && nums[dq.back()]<= nums[i])dq.pop_back();
                dq.push_back(i);
            if(i>=k){
                if(dq.front()==j)dq.pop_front();
                j++;
            }
            if(i>=(k-1))ans.push_back(nums[dq.front()]);
            
        }
        return ans;
    }
};