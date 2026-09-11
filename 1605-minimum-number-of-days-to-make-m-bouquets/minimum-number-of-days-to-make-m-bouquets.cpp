#define ll long long
class Solution {
public:
    bool chck(int x,vector<int>&arr,int m,int k){
        int n=arr.size();
        vector<bool>pos(n,false);
        for(int i=0;i<n;i++){
            if(arr[i]-x<=0)pos[i]=true;
        }
        int streak=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(pos[i]){
                streak++;
                if(streak==k){
                    cnt++;
                    streak=0;
                }
            }
            else streak=0;
            
        }
        return cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // i need to find min days..... let days is too high ... every 
        // flower will be bloomed ... we can take them 
        // let x be the min days such that our condition satisfy ...
        int n=bloomDay.size();
        if(1ll*m*k>n)return -1;
        int l=1,h=*max_element(bloomDay.begin(),bloomDay.end()),ans=h;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(chck(mid,bloomDay,m,k)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    
};