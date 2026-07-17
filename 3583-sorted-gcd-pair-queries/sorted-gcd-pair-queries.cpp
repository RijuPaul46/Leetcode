#define ll long long
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int mx=0;
        //store the freq of each number 
        for(auto &x:nums){
            mp[x]++;
            mx=max(mx,x);
        }
        vector<ll>cnt(mx+1);
        for(int i=mx;i>=1;i--){
            ll count=0;
            int j=i;
            while(j<=mx){
                count+=mp[j];
                j+=i;
            }
            ll ans=0;
            if(count>=2){
                ans=ans+1ll*(count)*(count-1)/2;
            
            int temp=i+i;
            while(temp<=mx){
                ans-=cnt[temp];
                temp+=i;
            }
            }
            cnt[i]=ans;
        }
        //prefix sum
        for(int i=1;i<=mx;i++){
            cnt[i]+=cnt[i-1];
        }
        vector<int>ans;
        for(auto &idx:queries){
            idx++;
            auto it=lower_bound(cnt.begin()+1,cnt.end(),1ll*idx);
            int i=it-cnt.begin();
            ans.push_back(i);
            
        }
        return ans;

        
    }
};