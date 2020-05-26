#include <vector>

//节点c++写法
struct TreeNode{  
    int val;
    TreeNode* left;
    TreeNode* right;
    ListNode(int x) : val(x), left(nullptr), right(nullptr) {}
};






/****************************************************/
// 1、二叉树结点统计
int CountingNode(TreeNode* root){
    if(!root)
        return 0;
    return CountingNode(root->left) + CountingNode(root->right) + 1;
}



/****************************************************/
// 2、二叉树高度
int CountingHeight(TreeNode* root){
    if(!root)
        return 0;
    int left = CountingHeight(root->left);
    int right = CountingHeight(root->right);
    return left > right ? left : right;
}




/****************************************************/
// 3、先序遍历
// 根 -> 左 -> 右
void PreOrderRecursive(TreeNode* root){
    if(!root)
        return;
    process();
    PreOrderRecursive(root->left);
    PreOrderRecursive(root->right);
}

void PreOrder(TreeNode* root){
    if(!root) return;
    std::stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty()){
        TreeNode* node = stack.top();
        process();
        stack.pop();
        if(node->left)
            stack.push(node->left);
        if(node->right)
            stack.push(node->right);
    }
}

/****************************************************/
// 4、 中序遍历
// 左 -> 根 -> 右
void MidOrderRecursive(TreeNode* root){
    if(!root)
        return;
    MidOrderRecursive(root->left);
    process();
    MidOrderRecursive(root->right);
}

void MidOrder(TreeNode* root){
    if(!root) return;
    s

}



/****************************************************/
// 5、 后序遍历
// 左 -> 右 -> 根



/****************************************************/
//




/****************************************************/
//




/****************************************************/
//

