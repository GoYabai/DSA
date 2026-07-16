#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int half = s.size() / 2;
        int b = 0;
        int e = s.size() - 1;
        while (b < half)
        {
            swap(s[b], s[e]);
            b++;
            e--;
        }
    }
};