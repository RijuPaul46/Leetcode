class Solution {
public:
    //for each index record next 1 is where 
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>nxt(n,n);
        vector<int>st;
        for(int i=0;i<n;i++){
            if(nums[i]==0)st.push_back(i);
            else{
                while(!st.empty()){
                    nxt[st.back()]=i;
                    st.pop_back();
                }
            }

        }
        int l=0;
        int cnt=0,sm=0;
        for(int r=0;r<n;r++){
            sm+=nums[r];
            while(sm>goal && l<r){
                sm-=nums[l++];
            }
            if(sm==goal){
                if(nums[l]==0){
                int next=min(r,nxt[l]);
                cnt+=(next-l+1);
                }
                else cnt++;
            }
        }
        return cnt;
    }
};