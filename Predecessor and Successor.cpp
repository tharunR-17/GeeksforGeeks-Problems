/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        stack<Node *> std;
        vector<Node *> list(2,NULL);
        //std.push(root);
        Node *p=root;
        while(p!=NULL ||!std.empty()){
            while(p!=NULL){
                std.push(p);
                p=p->left;
            }
            if(!std.empty()){
                p=std.top();
                std.pop();
                if(p->data <key)
                    list[0]=p;
                if(p->data>key){
                    list[1] =p;
                    return list;
                }
                p=p->right;
            }
        }
       
        return list;
    }
};
