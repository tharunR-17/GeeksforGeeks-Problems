/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    void inorder(Node* node,vector<int>&in,unordered_map<int,int>&mp){
        if(!node) return;
        
        inorder(node->left,in,mp);
        
        if(!node->left && !node->right){
            mp[node->data]=1;
        }
        in.push_back(node->data);
        
        inorder(node->right,in,mp);
    }
    bool isDeadEnd(Node *root) {
        // its a dead end if
        // in inorder we have 3 consecutive integers and the middle one is leaf
        vector<int>in;
        unordered_map<int,int>is_leaf;
        inorder(root,in,is_leaf);
        int n=in.size();
        if(is_leaf[in[0]] && in[0]==1 && in[1]==2) return true;
        for(int i=1;i+1<n;i++){
            if(is_leaf[in[i]] && (in[i-1]+1==in[i]) && (in[i]+1==in[i+1])){
                return true;
            }
        }
        return false;
    }
};
