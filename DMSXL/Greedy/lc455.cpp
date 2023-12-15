
//
// Created by Yao on 2023/12/14.
// Description:
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end()); // 胃口
    sort(s.begin(), s.end()); // 饼干

    int index = 0;

    for(int i = 0; i < s.size(); ++i){
        if(index < g.size() && g[index] <= s[i]){
            index++;
        }
    }

    return index;
}
int main()
{
    vector<int> g {1,2};
    vector<int> s {1,2,3};

    int res = findContentChildren(g, s);
    cout << res ;

}
