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
    string stradd(string &a,string &b){
        int carry=0;
        int m=a.size();
        int n=b.size();
        string ans="";
        int i=m-1,j=n-1;
        while(i>=0 && j>=0){
            int sm=carry+(a[i--]-'0')+(b[j--]-'0');
            int d=sm%10;
            carry=sm/10;
            ans+=to_string(d);
        }
        while(i>=0 ){
            int sm=carry+(a[i--]-'0');
           int d=sm%10;
            carry=sm/10;
            ans+=to_string(d);
        }
        while( j>=0){
            int sm=carry+(b[j--]-'0');
            int d=sm%10;
            carry=sm/10;
            ans+=to_string(d);
        }
        if(carry!=0)ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1="";
        string s2="";
        while(l1!=nullptr){
            s1+=to_string(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr){
            s2+=to_string(l2->val);
            l2=l2->next;
        }
        string ans=stradd(s1,s2);
        
        ListNode* head=new ListNode(ans[0]-'0');
        ListNode* temp=head;
        int i=1;
        while(i<ans.size()){
            head->next=new ListNode(ans[i++]-'0');
            head=head->next;
        }
        return temp;
    }
};