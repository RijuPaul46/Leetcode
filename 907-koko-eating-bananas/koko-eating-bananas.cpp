#define ll long long
class Solution {
public:
    bool chck(int x,vector<int>&arr,int h){
        ll hour=0;
        for(auto &p:arr){
            hour+=(p/x);
            hour+=(p%x==0)?0:1;
        }
        return hour<=h;
    }
    int minEatingSpeed(vector<int>& piles, int hr) {
        int n=piles.size();
        int mx=*max_element(piles.begin(),piles.end());
        int l=1,h=mx,ans=mx;
        while(l<=h){
            int mid=l+(h-l)/2;
            // cout<<mid<<endl;
            if(chck(mid,piles,hr)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};