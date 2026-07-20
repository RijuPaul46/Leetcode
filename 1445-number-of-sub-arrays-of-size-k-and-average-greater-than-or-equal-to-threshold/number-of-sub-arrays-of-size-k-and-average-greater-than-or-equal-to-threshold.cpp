class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0;
        int l=0;
        int r=0;
        int n=arr.size();
        int curr=0;
        for(int i=0;i<k;i++){
            curr+=arr[i];
            r++;
        }
        while(r<n){
            if(curr/k>=threshold)cnt++;
            curr-=arr[l++];
            curr+=arr[r++];
        }
        if(curr/k>=threshold)cnt++;
        return cnt;
    }
};