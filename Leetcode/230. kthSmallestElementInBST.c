/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void countIncrement( struct TreeNode* root, int k, int *count, int *result ){
    if( root == NULL || *result != -1 ){
        return;
    }

    countIncrement( root->left, k, count, result );

    if( *result != -1 ){
        return;
    }

    ( *count )++;
    if( *count == k ){
        *result = root->val;
    }

    countIncrement( root->right, k, count, result );
}
int kthSmallest( struct TreeNode* root, int k ) {
    int count = 0;
    int result = -1;
    countIncrement( root, k, &count, &result );

    return result;
}