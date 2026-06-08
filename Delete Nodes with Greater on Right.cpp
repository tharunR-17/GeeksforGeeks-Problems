/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        // code here
        stack<Node*> s;
        
        while(head != nullptr) {
            if(s.empty() || head->data < s.top()->data) {
                if(!s.empty()) {
                    s.top()->next = head;   
                }
                s.push(head);
            } else {
                while(!s.empty() && head->data > s.top()->data) {
                    s.pop();
                }
                if(!s.empty()) {
                    s.top()->next = head;   
                }
                s.push(head);
            }
            head = head->next;
        }
        
        Node* ans = nullptr;
        while(!s.empty()) {
            ans = s.top();
            s.pop();
        }
        
        return ans;
    }
};
