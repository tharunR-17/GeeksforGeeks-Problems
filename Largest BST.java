// class Node
// {
//     int data;
//     Node left, right;

//     public Node(int d)
//     {
//         data = d;
//         left = right = null;
//     }
// }

class Solution {
    static class Info{
        boolean isBST;
        long min;
        long max;
        int size;
        
        Info(boolean isBST, long min, long max, int size){
            this.isBST = isBST;
            this.min = min;
            this.max = max;
            this.size = size;
        }
    }
    
    static int maxBST = 0;  // Global variable jo ab tak mile largest BST ka size track karega
    
    static Info isValidBST(Node root){
        if(root==null){   //  empty tree hamesha BST hota hai
            // isBST = true, size = 0, min = +∞, max = -∞
            return new Info(true, Long.MAX_VALUE, Long.MIN_VALUE, 0);
        }   

        //  Get the Info for Left and Right Subtree
        Info leftInfo = isValidBST(root.left);
        Info rightInfo = isValidBST(root.right);
        
        //  Har node apne subtree ka size return kar deta hai.
        //  Jab parent node pe recursion wapas aata hai,
        //  to usko dono children ka size already mil chuka hota hai.
        //  Parent fir +1 karke apna size calculate karta hai.
        //  Is tarah size bottom se top propagate hota hai.
        int size = leftInfo.size+rightInfo.size+1;  // left ka + right ka + 1 (khud ka)
        long min = Math.min(root.data, Math.min(leftInfo.min, rightInfo.min));   // to check for BST (Global rule)
        long max = Math.max(root.data, Math.max(leftInfo.max, rightInfo.max));   // to check for BST (Global rule)

        //  Current root ka value (min, max) range ke andar agar nahi hai to ye BST nahi hai
        if (root.data <= leftInfo.max || root.data >= rightInfo.min){
            return new Info(false, min, max, 0);  // BST ka size sirf tabhi count krenge jab wo valid BST ho. Agar valid BST nahi hai to size ko propagate nahi krenge 0 kr denge
        }
        
        if (leftInfo.isBST && rightInfo.isBST && root.data > leftInfo.max && root.data < rightInfo.min){
            maxBST = Math.max(maxBST, size);
            return new Info(true, min, max, size);
        }
        
        return new Info(false, min, max, 0);  // Size propogated will be 0, as invalid BST
    }
    
    static int largestBst(Node root) {
        maxBST = 0;
        isValidBST(root);
        return maxBST;
    }
}
