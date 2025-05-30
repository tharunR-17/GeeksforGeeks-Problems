/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void solve( Node* root , int k , int tempans, int &ans){
        if(root == NULL)return ;
        tempans=k-root->data;
        if(root->data<=k&&tempans<=k-ans){
            ans= root->data;
        }
        solve( root->left , k, tempans , ans );
        solve( root->right , k, tempans , ans );
        
    }
    int findMaxFork(Node* root, int k) {
        // the difference between the number and k should be minimum 
        if(!root)return -1;
        int ans= -1;
        int tempans=-1;
        solve(root, k , tempans, ans);
        return ans ;
        
    }
};
