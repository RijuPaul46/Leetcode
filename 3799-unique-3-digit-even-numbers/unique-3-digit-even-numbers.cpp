class Solution {
public:
    int solve(int idx,vector<int> &freq){
        if(idx==3){
            int evn=0;
            for(int i=0;i<=8;i+=2){
                if(freq[i]>0)evn++;
            }
            return evn;
        }
            int low=0;
            if(idx==1)low=1;
            int ans=0;
            for(int i=low;i<=9;i++){
                if(freq[i]>0){
                    freq[i]--;
                    ans+=solve(idx+1,freq);
                    freq[i]++;
                }
                
            }
            return ans;    
        
    }
    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10);
        for(auto &d:digits)freq[d]++;
        return solve(1,freq);
    }
};