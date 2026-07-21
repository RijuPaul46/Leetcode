class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<pair<int,int>> arr;
        int one=0,zero=0;
        if(s[0]=='1')one++;
        else{
            zero++;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                one++;
                if(zero!=0){
                    arr.push_back({zero,0});
                    zero=0;
                }
            }
            else{
                zero++;
                if(one!=0){
                    arr.push_back({one,1});
                    one=0;
                }
            }
        }
        if(one!=0){
            arr.push_back({one,1});
            one=0;
        }
        if(zero!=0){
            arr.push_back({zero,0});
            zero=0;
        }
        int len=arr.size();
        int ans=0;
        int total_one=0;
        for(int i=0;i<len;i++){
            int num=arr[i].first;
            int type=arr[i].second;
            if(type==1){
                total_one+=num;
                if(i!=0 && i!=len-1){
                    int x=arr[i-1].first+arr[i+1].first;
                    ans=max(ans,x);   
                }
            }

        }
        return ans+total_one;
    }
};