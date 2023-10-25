//
// Created by Liu on 2023/7/12.
// Description:
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// Definition for a Node.
class Node
{
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL)
    {
    }

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL)
    {
    }

    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next)
    {
    }
};

Node *connect(Node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return root;
    }

    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; ++i)
        {
            Node *tempNode = que.front();
            que.pop();
            Node *next;
            if (i == size - 1)
            {
                next = nullptr;
            }
            else
            {
                next = que.front();
            }
            tempNode->next = next;

            if (tempNode->left != nullptr)
            {
                que.push(tempNode->left);
            }
            if (tempNode->right != nullptr)
            {
                que.push(tempNode->right);
            }
        }
    }
    return root;
}
int main()
{
}