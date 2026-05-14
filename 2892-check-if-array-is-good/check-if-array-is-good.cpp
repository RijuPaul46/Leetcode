class Solution {
public:
    bool isGood(vector<int>& nums) {
      int n=nums.size()-1;
      vector<int> freq(n+1);
      for(auto & x:nums){
        if(x>n)return false;
        else freq[x]++;
      }
      for(int i=1;i<n;i++){
        if(freq[i]!=1)return false;
      }
      return freq[n]==2;  
    }
};