class Solution {
public:
    int mx_freq(unordered_map<char,int>&mp){
        int mx=0;
        for(auto & [u,v]:mp)mx=max(mx,v);
        return mx;
    }
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while((i-j+1-mx_freq(mp))>k){
                char c=s[j];
                mp[c]--;
                if(mp[c]==0)mp.erase(c);
                j++;
            }
            ans=max(ans,i-j+1);

        }
        return ans;
    }
};