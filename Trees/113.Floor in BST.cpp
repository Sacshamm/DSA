int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
     int floorVal = 0;
    while(root != NULL) {
        
        if(root -> val == X) {
            floorVal = root -> val;
            return floorVal;
        }
        else if(root -> val > X) {
            root = root -> left;
        }
        else {
            floorVal = root -> val;
            root = root -> right;
        }
    }
    return floorVal;
}
