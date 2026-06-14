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
#define ll long long
class Solution {
public:
    int pairSum(ListNode* head) {
        int n=1;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            n+=2;
            fast=fast->next->next;
            slow=slow->next;
        }
        n++;
        ListNode* temp1=nullptr;
        if(slow->next!=nullptr)temp1=slow->next;
        ListNode* temp2=nullptr;
        if(temp1->next!=nullptr)temp2=temp1->next;
        slow=nullptr;
        while(temp2!=nullptr){
            temp1->next=slow;
            slow=temp1;
            temp1=temp2;
            temp2=temp2->next;
        }
        temp1->next=slow;
        ll mx=0;
        for(int i=0;i<(n/2);i++){
            ll sum=head->val+temp1->val;
            mx=max(mx,1ll*sum);
            head=head->next;
            temp1=temp1->next;
        }
        return (int)mx;


    }
};