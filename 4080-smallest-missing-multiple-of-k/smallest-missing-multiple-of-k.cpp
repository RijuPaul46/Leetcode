class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(auto &x:nums)st.insert(x);
        for(int i=k;i<=200;i+=k){
            if(!st.count(i))return i;
        }
        return -1;
    }
};