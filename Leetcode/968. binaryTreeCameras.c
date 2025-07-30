/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 int cameraTotal( struct TreeNode* root, int *cameraCount ){
        if( root == NULL ) return 2;

    int leftNode = cameraTotal( root->left, cameraCount );
    int rightNode = cameraTotal( root->right, cameraCount );

    if( leftNode == 1 | rightNode == 1 ){
        ( *cameraCount )++;
        return 3;
    }else if( leftNode == 3 | rightNode == 3 ){
        return 2;
    }

    return 1;
}

int minCameraCover( struct TreeNode* root ) {
    int cameraCount = 0;

    int rootState = cameraTotal( root, &cameraCount );
    if( rootState == 1 ){
        cameraCount++;
    }

    return cameraCount;
}

