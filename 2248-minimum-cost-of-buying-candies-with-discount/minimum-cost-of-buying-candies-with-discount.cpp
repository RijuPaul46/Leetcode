class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int c=0;
        if(n==1)return cost[0];
        if(n==2)return cost[0]+cost[1];
        int i=2;
        for(i=n-2;i>=0;i-=3){
            c+=cost[i]+cost[i+1];
        }
        for(int j=i+1;j>=0;j--)c+=cost[j];
        return c;
    }
};