/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 int checkBalanceAndHeight( struct TreeNode* root ){
      if( root == NULL ) return 0;

    int leftNode = checkBalanceAndHeight( root->left );
    if( leftNode == -1 ) return -1;

    int rightNode = checkBalanceAndHeight( root->right );
    if( rightNode == -1 ) return -1;

    int height = 0;
    if( abs(leftNode - rightNode ) > 1 ){
        return -1;
    }else if( leftNode > rightNode ){
        height = 1 + leftNode;
    }else{
        height = 1 + rightNode;
    }

    return height;
}

bool isBalanced(struct TreeNode* root) {
  return ( checkBalanceAndHeight( root ) != -1);
}

