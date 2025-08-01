/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void errorSpotter( struct TreeNode* root, struct TreeNode **swap, struct TreeNode **swap2, struct TreeNode **prev ){
    if( root == NULL ) return;
    
    errorSpotter( root->left, swap, swap2, prev );

    if( (*prev) != NULL && ( *prev )->val > root->val ){
        if( *swap == NULL ){
            *swap = *prev;
        }
        *swap2 = root;
    }
    *prev = root;
    errorSpotter( root->right, swap, swap2, prev );
}
void recoverTree( struct TreeNode* root ) {
    struct TreeNode *swap = NULL;
    struct TreeNode *swap2 = NULL;
    struct TreeNode *prev = NULL;
    int temp = 0;
    int flag = 0;
    errorSpotter( root, &swap, &swap2, &prev );


    if (swap != NULL && swap2 != NULL) {
        temp = swap->val;
        swap->val = swap2->val;
        swap2->val = temp;
    }
    
    return;
}