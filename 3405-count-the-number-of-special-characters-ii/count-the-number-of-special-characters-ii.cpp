class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>frequp(26);
        vector<int>freqlow(26);
        vector<bool>notTake(26,false);
        int cnt=0;
        for(auto &c:word){
            int idx=-1;
            if(islower(c)){
                idx=c-'a';
                if(frequp[idx]==0){
                freqlow[idx]++;
                }
                else{
                    notTake[idx]=true;
                }
            }
            else{
                idx=c-'A';
                frequp[idx]++;
            }
        }
        for(int i=0;i<26;i++){
            if(frequp[i]>0 && freqlow[i]>0 && !notTake[i])cnt++;
        }
        return cnt;
    }
};