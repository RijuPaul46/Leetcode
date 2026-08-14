class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int mx=0;
        int i=0,j=0;
        while(j<n){
            char c=s[j];
            mp[c]++;
            while(mp[c]>2){
                mp[s[i++]]--;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};