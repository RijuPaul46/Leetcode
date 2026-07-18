class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
       int n=obs.size();
       vector<int>ans(n);
       vector<int>arr;
       for(int i=0;i<n;i++){
        int idx=upper_bound(arr.begin(),arr.end(),obs[i])-arr.begin();
        if(idx==arr.size())arr.push_back(obs[i]);
        else {
            arr[idx]=obs[i];
        }
        ans[i]=idx+1;
       
       } 
       return ans;
    }
};