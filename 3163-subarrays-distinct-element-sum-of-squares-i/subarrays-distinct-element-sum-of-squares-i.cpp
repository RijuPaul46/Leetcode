class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int j=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.clear();
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                int sz=st.size();
                sum+=(sz*sz);
            }
        }
        return sum;
    }
};