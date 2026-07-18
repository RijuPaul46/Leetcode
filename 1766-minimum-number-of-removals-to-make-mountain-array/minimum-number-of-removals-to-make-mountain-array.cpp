class Solution {
public:
    // at each element check number of element need to remove to make it the peak..... exclude first and last element....LIS take nlogn  for each element it will be n^2logn  6*10^6.... will be acc 
    // int lis(int peak,vector<int>&nums){
    //     int n=nums.size();
    //     vector<int>len(n+1,INT_MIN);
    //     len[0]=INT_MAX;
    //     len[1]=nums[peak];
    //     int llds=1;
    //     for(int i=peak-1;i>=0;i--){
    //         int x=nums[i];
    //         int ridx=(upper_bound(len.rbegin(),len.rend(),x)-len.rbegin());
    //         int idx=n-ridx;
    //         if(idx+1!=1){
    //             len[idx+1]=max(len[idx+1],x);
    //             llds=max(llds,idx+1);
    //         }
    //     }
    //     int rlds=1;
    //     len.resize(n+1,INT_MIN);
    //     len[0]=INT_MAX;
    //     len[1]=nums[peak];
    //      for(int i=peak+1;i<n;i++){
    //         int x=nums[i];
    //         int ridx=(upper_bound(len.rbegin(),len.rend(),x)-len.rbegin());
    //         int idx=n-ridx;
    //         if(idx+1!=1){
    //             len[idx+1]=max(len[idx+1],x);
    //             rlds=max(rlds,idx+1);
    //         }
    //     }
    //     int total_elm=n;
    //     cout<<"rlds,llds:"<<rlds<<" ,"<<llds<<endl;
    //     int in_mountain=rlds+llds-1;
    //     int to_rm=total_elm-in_mountain;
    //     return to_rm;
    // }
    int minimumMountainRemovals(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        vector<int>lis(n);
        vector<int>lds(n);
        vector<int>arr;
        arr.push_back(INT_MIN);
        for(int i=0;i<n;i++){
            int x=nums[i];
            auto idx=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
            if(idx==arr.size()){arr.push_back(x);}
            else{
                arr[idx]=min(arr[idx],x);
            }
            lis[i]=idx;   
        }
        arr.clear();
        arr.push_back(INT_MIN);
        for(int i=n-1;i>=0;i--){
           int x=nums[i];
            auto idx=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
            if(idx==arr.size()){arr.push_back(x);}
            else{
                arr[idx]=min(arr[idx],x);
            }
            lds[i]=idx; 
        }
        for(int i=0;i<n;i++){
            if(lis[i]>1 && lds[i]>1){
            int to_rm=n-(lis[i]+lds[i]-1);
            ans=min(ans,to_rm);
            }
        }
        return ans==INT_MAX?0:ans;
    }
};