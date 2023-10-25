//
// Created by Liu on 2023/7/12.
// Description:
//

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
  public:
    int val;
    vector<Node *> children;

    Node()
    {
    }

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    queue<Node *> que;
    vector<vector<int>> res;

    if (root == nullptr)
    {
        return res;
    }
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();

        vector<int> tempV;
        for (int i = 0; i < size; ++i)
        {
            Node *tempNode = que.front();
            tempV.push_back(tempNode->val);
            que.pop();

            for (Node *node : tempNode->children)
            {
                if (node != nullptr)
                {
                    que.push(node);
                }
            }
        }
        res.push_back(tempV);
    }
    return res;
}

int main()
{
}
