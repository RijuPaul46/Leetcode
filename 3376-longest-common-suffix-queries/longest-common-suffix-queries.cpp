class Node {
public:
    int bi;
    int arr[26]; // Notice: This is an array of ints now, not pointers!
    
    Node(int idx) {
        bi = idx;
        for(int i = 0; i < 26; i++) {
            arr[i] = -1; // -1 represents a "nullptr"
        }
    }
};

class Trie {
public:
    vector<Node> nodes; // The flat array that holds all nodes
    
    Trie(int i) {
        nodes.push_back(Node(i)); // The root node is always at index 0
    }
    
    // Removed the redundant 'Node* root' and 'int i' parameters
    void add(const string &str, int idx, const vector<string>& wc) {
        int curr = 0; // Start at the root (index 0)
        
        for(int i = str.size() - 1; i >= 0; i--) {
            int in = str[i] - 'a';
            
            // If child doesn't exist
            if(nodes[curr].arr[in] == -1) {
                nodes[curr].arr[in] = nodes.size(); // Link the new node's index
                nodes.push_back(Node(idx));         // Create the new node
            } 
            else {
                int next_node = nodes[curr].arr[in];
                int prev = nodes[next_node].bi;
                
                if(wc[idx].size() < wc[prev].size() || 
                  (wc[idx].size() == wc[prev].size() && idx < prev)) 
                {
                    nodes[next_node].bi = idx;
                }
            }
            
            curr = nodes[curr].arr[in]; // Move to the child node
        }
    }
    
    int bestindex(const string &str) {
        int curr = 0; // Start at root
        
        for(int i = str.size() - 1; i >= 0; i--) {
            int idx = str[i] - 'a';
            
            if(nodes[curr].arr[idx] == -1) {
                return nodes[curr].bi;
            }
            
            curr = nodes[curr].arr[idx];
        }
        
        return nodes[curr].bi;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int bi = 0;
        for (int i = 0; i < wordsContainer.size(); i++) {
            if(wordsContainer[i].size() < wordsContainer[bi].size()) {
                bi = i;
            }
        }
        
        Trie tr(bi); // Stack allocation (cleans itself up automatically!)
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            const string& str = wordsContainer[i]; 
            tr.add(str, i, wordsContainer); 
        }
  
        int n = wordsQuery.size();
        vector<int> ans(n, -1);
        
        for(int i = 0; i < n; i++) {
            const string& query = wordsQuery[i];
            ans[i] = tr.bestindex(query);
        }
        
        return ans;
    }
};