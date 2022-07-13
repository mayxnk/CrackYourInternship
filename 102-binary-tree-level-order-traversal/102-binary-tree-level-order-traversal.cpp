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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        if(root == NULL)
            return ans;
        queue<TreeNode*> wn;
        wn.push(root);
        wn.push(NULL);
        while(wn.size()!=0)
        {
           TreeNode* curr;
            if(wn.front()!=NULL)
            {
                curr = wn.front();
                temp.push_back(curr->val);
                if(curr->left)
                    wn.push(curr->left);
                if(curr->right)
                    wn.push(curr->right);
                wn.pop();
            }
            else
            {
                ans.push_back(temp);
                temp.clear();
                wn.pop();
                if(wn.size())
                    wn.push(NULL);
            }
        }
        return ans;
    }
};