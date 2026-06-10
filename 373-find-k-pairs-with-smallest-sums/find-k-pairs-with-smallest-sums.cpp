#define ll long long
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](auto &pr1, auto &pr2) {
    return (nums1[pr1.first] + nums2[pr1.second]) >
           (nums1[pr2.first] + nums2[pr2.second]);
          };
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        decltype(cmp)> pq(cmp);
        unordered_set<ll> visited;
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>> ans;
        pq.push({0,0});
        visited.insert(0);
        while(!pq.empty()){
            auto pr=pq.top();
            pq.pop();
            int i1=pr.first;
            int i2=pr.second;
            ans.push_back({nums1[i1],nums2[i2]});
            k--;
            if(k==0)break;
            ll hash1=1ll*((i1+1)*n2+i2);
            ll hash2=1ll*((i1)*n2+i2+1);
            if(i1+1<n1 && !visited.count(hash1)){
                pq.push({i1+1,i2});
                visited.insert(hash1);
            }
            if(i2+1<n2 && !visited.count(hash2)){
                pq.push({i1,i2+1});
                visited.insert(hash2);

            }
        }
        return ans;


    }
};