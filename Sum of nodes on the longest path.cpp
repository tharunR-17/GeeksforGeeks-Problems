void solve(Node* root , int sumtillcurrentNode, int heighttillcurrentNode, pair<int,int>&p){

        if(root==NULL)return ;
              
            heighttillcurrentNode++;
            sumtillcurrentNode+=root->data;
            if(p.first<heighttillcurrentNode)//NOTE: p.first===>the height of the tree, p.second==>corresponds to the sum 
            {
                p.first=heighttillcurrentNode;
                p.second=sumtillcurrentNode;
            }
            else if(p.first==heighttillcurrentNode){
                p.second=max(p.second, sumtillcurrentNode);
            }
            solve(root->left,sumtillcurrentNode,heighttillcurrentNode,p );
            solve(root->right,sumtillcurrentNode,heighttillcurrentNode,p );
        
    }
    int sumOfLongRootToLeafPath(Node *root) {
       pair<int,int>p={0,0};
       solve(root ,0,0,p );
       return p.second;
    }
