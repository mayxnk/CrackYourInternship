/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,int inS,int inE,int preS,int preE)
    {
        if(inS > inE or preS > preE)
            return NULL;
        int rootIndex,rootData = preorder[preS];
        for(int i = inS;i<inE;++i)
            if(inorder[i] == rootData)
            {
                rootIndex = i;
                break;
            }
        int lpS = preS+1;
        int linS = inS,linE = rootIndex-1;
        int lpE = (linE-linS) + lpS;
        
        int rpS = lpE + 1,rpE = preE;
        int rinS = rootIndex + 1,rinE = preE;
        
        TreeNode* root = new TreeNode(rootData);
        root->left = buildTreeHelper(preorder,inorder,linS,linE,lpS,lpE);
        root->right = buildTreeHelper(preorder,inorder,rinS,rinE,rpS,rpE);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = inorder.size();
        TreeNode* root = buildTreeHelper(preorder,inorder,0,n-1,0,n-1);
        return root;
    }
};