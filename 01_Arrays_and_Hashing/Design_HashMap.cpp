#include <vector>
#include <algorithm>

using namespace std;

class MyHashMap {
public:
    vector<int> k;
    vector<int> v;
    
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto it = find(k.begin(), k.end(), key);
        if (it == k.end())
        {
            k.push_back(key);
            v.push_back(value);
        }
        else
        {
            int index = distance(k.begin(), it);
            v[index] = value;
        }
    }
    
    int get(int key) {
        auto it = find(k.begin(), k.end(), key);
        if (it == k.end())
        {
            return -1;
        }
        else
        {
            int index = distance(k.begin(), it);
            return v[index];
        }
    }
    
    void remove(int key) {
        auto it = find(k.begin(), k.end(), key);
        if (it != k.end())
        {
            int index = distance(k.begin(), it);
            k.erase(it);
            v.erase(v.begin() + index);
        }
    }
};