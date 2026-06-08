class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int cnt=0;
        int i=0;
        for(auto &x:nums){
            if(x<pivot)ans[i++]=x;
            else if(x==pivot)cnt++;
        }
        for(int k=0;k<cnt;k++)ans[i++]=pivot;
        for(auto &x:nums){
            if(x>pivot)ans[i++]=x;
        }
        return ans;

    }
};