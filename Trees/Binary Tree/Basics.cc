//The Most basic type of tree, binary tree with 2 or less than 2 noes, a perfect binary tree will be of either 2 or none children,
//but a binary tree can have at most 2 childrens.


struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};



int main(){

    //First 2 Children and root
    TreeNode* root = new TreeNode();
    root -> val = 0;

    TreeNode* left = new TreeNode();
    left -> val = 1;
    root -> left = left;
    
    TreeNode* right = new TreeNode();
    right -> val = 2;
    root -> right = right;

}

//Next Up