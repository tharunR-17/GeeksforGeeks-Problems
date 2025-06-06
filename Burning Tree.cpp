/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) {
        // parents needed because tree burn upward direction  also
        map<Node*, Node*>parents;
        queue<Node*>q1;
        q1.push(root);
        Node* targetnode = NULL;
        while(!q1.empty())
        {
            int s = q1.size();
            for(int i=0;i<s;i++)
            {
                
                Node* node = q1.front();
                q1.pop();
                
                // get here target node by using target value
                if(node->data == target)targetnode = node;
                
                if(node->left)
                {
                    parents[node->left] = node;
                    q1.push(node->left);
                }
                if(node->right)
                {
                    parents[node->right] = node;
                    q1.push(node->right);
                }
                
            }
            
        }
            
        map<Node*, bool>burned;
        queue<Node*>q2;
        q2.push(targetnode);
        burned[targetnode] = true;
        int required_sec = -1;
            
        while(!q2.empty())
        {
            int s = q2.size();
            required_sec++;
            for(int i=0;i<s;i++)
            {
                Node* current = q2.front();
                q2.pop();
                
                if(!burned[current->left]&&current->left)
                {
                    q2.push(current->left);
                    burned[current->left] = true;
                }
                
                if(!burned[current->right]&&current->right)
                {
                    q2.push(current->right);
                    burned[current->right] = true;
                }
                
                if(!burned[parents[current]]&&parents[current])
                {
                    q2.push(parents[current]);
                    burned[parents[current]] = true;
                }
            }
        }
                
        return required_sec;  
    }
};
