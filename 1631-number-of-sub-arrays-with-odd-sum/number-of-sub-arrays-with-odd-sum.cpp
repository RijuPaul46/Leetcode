class Solution {
public:
    // 1 0 1 0 1 0 1
    
    #define ll long long
    ll mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        ll a=0,b=0,last=-1,ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2==1){
                ll temp1=a,temp2=b;
                b=temp1;
                a=temp2+(i-last);
                last=i;
                

            }
            ans=(ans+a)%mod;
            
        }
        return ans;
    }
};