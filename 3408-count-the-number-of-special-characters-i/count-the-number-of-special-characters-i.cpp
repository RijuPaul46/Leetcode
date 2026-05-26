class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq(26,0);
        for(auto & ch:word){
            int idx=ch-'a';
            if(idx>=0 && idx<26)freq[idx]++;
        }
        vector<bool>taken(26,false);
        int cnt=0;
        for(auto & ch:word){
            int idx=ch-'A';
            if(idx>=0 && idx<26){
                if(freq[idx] && !taken[idx]){taken[idx]=true;cnt++;}
            }
        }
        return cnt;
    }
};