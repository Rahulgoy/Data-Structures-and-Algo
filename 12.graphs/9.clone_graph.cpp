#include <bits/stdc++.h>
using namespace std;
Node* dfs(Node* node, unordered_map<Node*, Node*> &hash) {
        if(hash.find(node) == hash.end()) {
                hash[node] = new Node(node->val);
                for(Node* neighbor : node->neighbors) {
                    hash[node] -> neighbors.push_back(dfs(neighbor, hash));
                }
            }
        return hash[node];
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        unordered_map<Node*, Node*> hash;
        return dfs(node, hash);
    }
int main(){


return 0;
}