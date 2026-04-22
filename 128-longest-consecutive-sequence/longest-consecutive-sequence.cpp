class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        unordered_set<int> st;
        for(auto & num:nums){
            st.insert(num);
        }
        int ans=1;
        for(auto & elm:st){
            if(st.count(elm-1)==0){
                int temp=elm;
                int cnt=1;
                while(st.count(temp+1)){
                    temp++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};