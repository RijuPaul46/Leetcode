class Node{
    public:
    vector<Node*> arr;
    Node(){
        arr.resize(26);
        for(int i=0;i<26;i++){
            arr[i]=nullptr;
        }
    }
};
class PrefixTree{
    public:
    Node* root;
    PrefixTree(){
        root=new Node();
    }
    void add(int i,string &word,Node* node){
        int n=word.size();
        if(i==n)return;
        int idx=word[i]-'a';
        if(node->arr[idx]==nullptr){
            node->arr[idx]=new Node();
        }
        add(i+1,word,node->arr[idx]);
    }
    bool present(int cnt,string & word,Node* node,int i){
        int n=word.size();
        if(cnt>2)return false;
        if(i==n)return true;
        int idx=word[i]-'a';
            bool ans=false;
            for(int j=0;j<26;j++){
                if(node->arr[j]!=nullptr){
                    if(j==idx)ans|=present(cnt,word,node->arr[j],i+1);
                    else ans=ans|present(cnt+1,word,node->arr[j],i+1);
                }   
            }
            return ans;
      
    }
};
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        PrefixTree* pt=new PrefixTree();
        for(auto & word:dictionary){
            pt->add(0,word,pt->root);
        }
        vector<string> ans;
        for(auto &q:queries){
            if(pt->present(0,q,pt->root,0)){
                ans.push_back(q);
            }
        }
        return ans;
    }
};