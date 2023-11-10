
//
// Created by Yao on 2023/11/7.
// Description:
//

#include <iostream>
#include<vector>
using namespace std;
struct Pair{
  public:
    int key;
    string val;
    Pair(int key, string val){
        this->key = key;
        this->val = val;
    }
};

/* 基于数组简易实现的哈希表 */
class ArrayHashMap{
  private:
    vector<Pair*> buckets;

  public:
    ArrayHashMap(){
        buckets = vector<Pair*>(100);

    }

    ~ArrayHashMap(){
        for(const auto & bucket : buckets){
            delete bucket;
        }

        buckets.clear();
    }

    int hashFunc(int key){
        int index = key % 100;
        return index;
    }

    string get(int key){
        int index = hashFunc(key);
        Pair * pair = buckets[index];
        if(pair == nullptr){
            return "";
        }
        return pair->val;
    }

    void put(int key, string val){
        int index = hashFunc(key);
        Pair * pair = new Pair(key, val);
        buckets[index] = pair;
    }

    void remove(int key){
        int index = hashFunc(key);
        Pair * temp = buckets[index];
        buckets[index] = nullptr;
        delete temp;
        temp = nullptr;
    }

    vector<Pair *> getPairSet(){
        vector<Pair *> pairs;
        for(Pair * pair : buckets){
            if (pair != nullptr){
                pairs.push_back(pair);
            }
        }
        return pairs;
    }

    vector<int> getKeySet(){
        vector<int> keys;
        for(Pair * pair : buckets){
            if(pair != nullptr){
                keys.push_back(pair->key);
            }
        }
        return keys;
    }

    vector<string> getValSet(){
        vector<string> vals;
        for(Pair * pair : buckets){
            if(pair != nullptr){
                vals.push_back(pair->val);
            }
        }
        return vals;
    }

    void print(){
        for(Pair * kv : getPairSet()){
            cout << kv->key << "->" << kv->val << endl;
        }
    }
};
int main()
{
    ArrayHashMap * arrayHashMap = new ArrayHashMap();
    arrayHashMap->put(102, "elena");
    arrayHashMap->put(105, "aryna");
    arrayHashMap->put(109, "jelena");
    arrayHashMap->put(119, "iga");

    arrayHashMap->print();

    string name = arrayHashMap->get(102);
    cout << name << endl;

    arrayHashMap->remove(119);
    arrayHashMap->print();

    auto keyset = arrayHashMap->getKeySet();
    for(auto key : keyset){
        cout << key << " ";
    }
    cout << endl;

    auto valset = arrayHashMap->getValSet();
    for(auto val : valset){
        cout << val << " ";
    }
}
