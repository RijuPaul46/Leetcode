class Node{
    public:
    vector<Node*> arr;
    Node(){
        arr.resize(10);
        for(int i=0;i<10;i++)arr[i]=nullptr;
    }
};
class PrefixTree{
    public:
    Node* root;
    PrefixTree(){
        root=new Node();
    }
    
};
class Solution {
public:
    void add(Node * node,vector<int>&digits,int i){
        if(i<0)return;
        if(node->arr[digits[i]]==nullptr){
            node->arr[digits[i]]=new Node();
        }
        add(node->arr[digits[i]],digits,i-1);
    }
    int lcp(vector<int>& digits,int i,Node* node){
        if(i<0)return 0;
        if(node->arr[digits[i]]!=nullptr){
            return 1+lcp(digits,i-1,node->arr[digits[i]]);
        }
        return 0;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        PrefixTree* pt=new PrefixTree();
        for(auto & x:arr1){
            vector<int> digits;
            while(x>0){
                digits.push_back(x%10);
                x/=10;
            }
            add(pt->root,digits,digits.size()-1);
        }
        int mx=0;
        for(auto & x:arr2){
            vector<int> digits;
            while(x>0){
                digits.push_back(x%10);
                x/=10;
            }
            mx=max(mx,lcp(digits,digits.size()-1,pt->root));

        }
        return mx;
    }
};