class Solution {
public:
    int preorder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return -1;
        }
        int leftans = kthSmallest(root->left, k);
        if(root->left != NULL){
            if(leftans != -1){
                return leftans;
            }
        }
        preorder++;
        if(preorder == k){
            return root->val;
        }
        int rightans = kthSmallest(root->right, k);
        if(root->right != NULL){
            if(rightans != -1){
                return rightans;
            }
        }
        return -1;
    }
};