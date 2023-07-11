//
// Created by Liu on 2023/7/11.
// Description: 
//

#include<iostream>
#include<vector>
using namespace std;

string simplifyPath(string path) {
    vector<string> stk;
    int len = path.size();

    int i = 0;
    while( i < len){
        if(path[i] == '/'){
            ++i;
        }else{
            int start = i;

            while(i < len && path[i] != '/'){
                ++i;
            }

            string temp = path.substr(start, i-start);

            if(temp == ".." && ! stk.empty()){
                stk.pop_back();
            }else if(temp != "." && temp != ".."){
                stk.push_back(temp);
            }
        }
    }

    string res = "";
    if(stk.empty()){
        return "/";
    }
    for(auto s : stk){
        res += "/" + s;
    }
    return res;
}

int main(){
    string s;
    getline(cin, s);

    string res = simplifyPath(s);

    cout << res << endl;
}
