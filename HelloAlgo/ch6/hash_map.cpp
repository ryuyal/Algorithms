
//
// Created by Yao on 2023/11/6.
// Description:
//

#include <iostream>
#include<unordered_map>
using namespace std;

int main()
{
    /* 初始化哈希表 */
    unordered_map<int, string> map;

    /* 添加操作 */
    // 在哈希表中添加键值对 (key, value)
    map[12836] = "Hello";
    map[15937] = "Algo";
    map[16750] = "Elena";
    map[13276] = "Rybakina";
    map[10583] = "Saba";

    string name = map[15937];
    cout << name << endl;

    /* 遍历哈希表 */
    // 遍历键值对 key->value
    for (auto kv: map) {
        cout << kv.first << " -> " << kv.second << endl;
    }
    cout << "-------------------" << endl;
    // 使用迭代器遍历 key->value
    for (auto iter = map.begin(); iter != map.end(); iter++) {
        cout << iter->first << "->" << iter->second << endl;
    }
}
