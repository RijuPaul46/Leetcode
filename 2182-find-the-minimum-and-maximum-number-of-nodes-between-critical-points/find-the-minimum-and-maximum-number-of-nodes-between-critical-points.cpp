/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        int i=1;
        ListNode* temp=head->next;
        if(temp==nullptr || temp->next==nullptr){
            return {-1,-1};
        }
        int prev=head->val;
        while(temp->next !=nullptr){
            int val=temp->val;
            int next=temp->next->val;
            if((val>prev && val>next) ||(val<prev && val<next)){
                critical.push_back(i);
            }
            i++;
            prev=val;
            temp=temp->next;
        }
        if(critical.size()<=1)return {-1,-1};
        int n=critical.size();
        int mx=critical[n-1]-critical[0];
        int mn=INT_MAX;
        for(int i=1;i<n;i++){
            mn=min(mn,critical[i]-critical[i-1]);
        }
        return {mn,mx};
    }
};