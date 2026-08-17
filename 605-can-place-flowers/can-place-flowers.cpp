class Solution {
public:
    bool canPlaceFlowers(vector<int>& fl, int n) {
        int cnt=0;
        int len=fl.size();
        for(int i=0;i<len;i++){
            if(fl[i]==0){
            if((i-1>=0 && fl[i-1]==1) || (i+1<len && fl[i+1]==1)){}
            else {fl[i]=1;cnt++;}
            }
           
            }
            return cnt>=n;
    }
};