class Solution {
public:
    #define ll long long
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        //let a b c are taken a+c>=need1 b+c>=need2 
        // find min((need1-c)*cost1+(need2-c)*cost2+c*cb)
        // let try bs on answer let answer be x(min total cost) now >=x we can fulfil the condition 
        // can we think greedy ... yes ... whose cost is least 
        // c1<c2<cb take c1 as much as possible 
        // if cb<c1<c2 then answer is cb*(max(n1,n2))
        
        if(1ll*costBoth>=(cost1+cost2)){
            ll ans=1ll*(1ll*need1*cost1+1ll*need2*cost2);
            return ans;
        }
        // let i have taken c elm for cb min(0,need1-cb)
        //let c>=need1 need2 cost is c*cb 
        // c< both need1*c1 + n2*c2 +c(cb-c1-c2)  all are const
        // if cb>(c1+c2) take c=0   if cb< (c1+c2)
        if(1ll*costBoth<=min(cost1,cost2)) {
        ll ans=1ll*costBoth*(1ll*max(need1,need2));
        return ans;}
        ll both=min(need1,need2);
        ll total=1ll*both*costBoth;
        need1-=both;
        need2-=both;
        if(need1>0){
            total+=1ll*(need1)*min(cost1,costBoth);
        }
        else if(need2>0){
            total+=1ll*(need2)*min(cost2,costBoth);
        }
        // c1<=cb<=c2

        return total;
        

    }
};