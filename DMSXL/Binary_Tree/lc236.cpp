
//
// Created by Yao on 2023/9/22.
// Description:     
//

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
 * 方法1
 */
// 在以root为根节点的树中找node节点
bool find(TreeNode * root, TreeNode * node){
    if(root == nullptr){
        return false;
    }
    if(root == node){
        return root;
    }

    return find(root->left, node) || find(root->right, node);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q || root == nullptr){
        // 只要当前根节点是p和q中的任意一个 就返回
        return root;
    }

    // 如果 p q都在左子树 就到左子树中找最近公共祖先
    if(find(root->left, p) && find(root->left, q)){
        return lowestCommonAncestor(root->left, p, q);
    }

    // 如果 p q都在右子树 就到右子树中找最近公共祖先
    if(find(root->right, p) && find(root->right, q)){
        return lowestCommonAncestor(root->right, p, q);
    }

    // 否则 说明 p q分属两侧 公共祖先为root
    return root;
}


/*
 * 方法2：
 */
// 给定两个节点p和q
//1. 如果p和q都存在 则返回其公共祖先
//2. 如果只存在一个 则返回存在的一个
//3. 如果p和q都不存在 则返回nullptr
// 时间复杂度 O(n)  空间复杂度 O(n)
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL)
        return NULL;
    if(root == p || root == q)
        return root;

    TreeNode* left =  lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    if(left && right) // p和q在两侧
        return root;

    return NULL; // 必须有返回值
}
//lowestCommonAncestor这个函数不要理解为找公共祖先，而就理解为帮两个节点找祖先
//传入的值是root, p, q，帮p和q找到一个祖先就行，找到两个就更好了，
//如果找不到就返回NULL 在root->left里面找一次，root->right里面再找一次，
//如果某一边返回值是NULL， 那么说明两个值都在另一边
//由于找的时候，一定是找的最近的祖先返回，所以这里直接返回前面的返回值就行了，
//可以保证是最近的公共祖先 如果左右的返回值都不是NULL，那说明p和q分别在两边，
//则当前节点就是最近公共祖先 左右都找不到就直接返回NULL

int main() {

}
