/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool f(Node*l , Node*r){
        if(l == NULL && r == NULL) return 1 ;
        if( (l == NULL && r != NULL) || (l != NULL && r == NULL) || (l -> data != r -> data)) return 0 ;
        
        return f(l -> right , r -> left) && f(l -> left , r -> right) ;
    }
    
    bool isSymmetric(Node* root) {
        return f(root -> left , root -> right) ;
        
    }
};
