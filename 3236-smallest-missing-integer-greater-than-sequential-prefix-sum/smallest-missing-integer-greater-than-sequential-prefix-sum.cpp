class Solution {
public:
// 25*51=  1275
    int missingInteger(vector<int>& nums) {
        int prev=nums[0];
        int sm=prev;
        unordered_set<int> st;
        st.insert(prev);
        int n=nums.size();
        for(int i=1;i<n;i++){
            st.insert(nums[i]);
            if(nums[i]==prev+1){
                sm+=nums[i];
                prev=nums[i];
            }
            else{
                prev=-1;
            }
        }
        for(int j=sm;j<=1275;j++){
            if(!st.count(j))return j;
        }
        return -1;
    }
};