class Solution {
public:
    // 2|3 first block blocked 
    // 8,9  last block blocked
    // 4,5,6,7  two block blocked 
    // i willl calculate how many blocked 
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;
        for(auto &ed:reservedSeats){
            int row=ed[0];
            int seat=ed[1];
            if(seat>=2 && seat<=5)mp[row].insert(1);
            if(seat>=4 && seat<=7)mp[row].insert(2);
            if(seat>=6 && seat<=9)mp[row].insert(3);
        }
        int total_grp_poss=2*n;
        int blocked_grp=0;
        for(auto &[row,grps]:mp){
            int cnt=0;
            if(grps.size()==3)cnt=2;
            if(grps.size()==2){
                cnt=1;
            }
            if(grps.size()==1)cnt=1;
            blocked_grp+=cnt;
        }
        return total_grp_poss-blocked_grp;
    }
};