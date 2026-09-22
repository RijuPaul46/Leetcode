class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>missing(n);
        for(int i=0;i<n;i++){
            missing[i]=arr[i]-(i+1);
        }
        int next=lower_bound(missing.begin(),missing.end(),k)-missing.begin();
        if(next==0)return k;
        int prev=next-1;
        return (k-missing[prev])+arr[prev];
    }
};