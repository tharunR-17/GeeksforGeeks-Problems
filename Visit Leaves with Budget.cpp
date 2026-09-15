/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        queue<pair<Node*,int>>q;
        q.push({root,1});
        int ans = 0;

        while(!q.empty()){

            Node*temp = q.front().first;
            int level = q.front().second;
            q.pop();

            if(!temp->left && !temp->right){
                if(level>k)return ans;
                ans++;
                k-=level;
                continue;
            }

            if(temp->left)q.push({temp->left,level+1});
            if(temp->right)q.push({temp->right,level+1});

        }

        return ans;
    }
};
