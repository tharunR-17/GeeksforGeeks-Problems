/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
	public:
	int minDiff(Node *root, int k) {
		// code here
		int result = INT_MAX;
		Node *node = root;
		while (node != nullptr) {
			result = min(result, abs(node->data - k));
			if (node->data<k)node = node->right;
			else
				node = node->left;
		}
		return result;
	}
};
