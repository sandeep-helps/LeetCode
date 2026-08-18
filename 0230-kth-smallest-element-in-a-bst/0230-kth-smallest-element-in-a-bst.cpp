class Solution {
public:
    int preorder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return -1;
        }
        if(root->left != NULL){
            int leftans = kthSmallest(root->left, k);
            if(leftans != -1){
                return leftans;
            }
        }
            preorder++;
        if(preorder == k){
            return root->val;
        }
        if(root->right != NULL){
            int rightans = kthSmallest(root->right, k);
            if(rightans != -1){
                return rightans;
            }
        }
        return -1;
    }
};