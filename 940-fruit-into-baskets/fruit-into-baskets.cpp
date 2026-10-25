class Solution {
public:
    //find longest subarray having maximum 2 distinct elm 
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n=fruits.size();
        int j=0;
        int mx=0;
        for(int i=0;i<n;i++){
            int x=fruits[i];
            mp[x]++;
            while((int)mp.size()>2){
                int y=fruits[j];
                mp[y]--;
                if(mp[y]==0)mp.erase(y);
                j++;
            }
            mx=max(mx,i-j+1);
        }
        return mx;
    }
};