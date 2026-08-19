class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>st;
        int cnt=1;
        int ans=1;
        int n=nums.size();
        st.insert(nums[0]);
        int l=0;
        
        for(int i=1;i<n;i++){
            int x=nums[i];
            
            int mx=*(prev(st.end()));
            int mn=*(st.begin());
            if(abs(x-mn)<=limit && abs(x-mx)<=limit){
                cnt++;
                st.insert(x);
            }
            else{
                while(st.size()>0 && l<i){
                     int mx=*(prev(st.end()));
                     int mn=*(st.begin());
                    if(abs(x-mn)<=limit && abs(x-mx)<=limit){
                        break;
                    }
                    else{
                        st.erase(st.find(nums[l++]));
                        cnt--;
                    }
               
                }
                st.insert(x);
                cnt++;
            }
            ans=max(ans,cnt);
            
         }
        return ans;
    }
};