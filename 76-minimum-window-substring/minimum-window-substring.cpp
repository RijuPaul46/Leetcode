class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freq;
        
        for(auto &c:t)freq[c]++;
        int si=-1,ei=-1;
        int n=s.size();
        int m=t.size();
        int req=m;
        if(m>n)return "";
        int j=0;
        int len=INT_MAX;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(freq.count(c)){
                freq[c]--;
                if(freq[c]>=0)
                req--;
            }
            while(req==0 && j<=i){
                char ch=s[j];
                if(freq.count(ch)){
                    freq[ch]++;
                    if(freq[ch]>0)req++;
                }
                
                if((i-j+1) < len){
                    si=j;
                    ei=i;
                    len=(i-j+1);
                }
                j++;
            }
            
        }
        if(si!=-1 && ei!=-1)
        return s.substr(si,ei-si+1);
        return "";
    }
};