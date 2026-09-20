class Solution {
public:
    int reverseDegree(string s) {
        int sm=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            sm+=('z'-c+1)*(i+1);
        }
        return sm;
    }
};