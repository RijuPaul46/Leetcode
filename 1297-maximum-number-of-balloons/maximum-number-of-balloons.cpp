class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26);
        for(auto&ch:text){
            freq[ch-'a']++;
        }
        int a=0;
        int b=1;
        int l='l'-'a';
        int o='o'-'a';
        int n='n'-'a';
        int cnt=0;
        while(freq[a]>0 && freq[b]>0 && freq[l]>1 && freq[o]>1 && freq[n]>0){
            cnt++;
            freq[a]--;
            freq[b]--;
            freq[l]-=2;
            freq[o]-=2;
            freq[n]--;
        }
        return cnt;

    }
};