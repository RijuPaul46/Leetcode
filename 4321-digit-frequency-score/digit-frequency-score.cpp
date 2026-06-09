class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int>freq(10);
        string s=to_string(n);
        for(auto &d:s){
            freq[d-'0']++;
        }
        int ans=0;
        for(int i=0;i<10;i++)ans+=i*freq[i];
        return ans;
    }
};