#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        
        for (const string& s : strs) {
            // 1. Count the frequency of each character
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            
            // 2. Build a unique string key from the counts
            string key = "";
            for (int i = 0; i < 26; i++) {
                // We use '#' as a delimiter so counts like "1" and "11" don't blend together
                key += to_string(count[i]) + "#"; 
            }
            
            // 3. Add the original string to the map
            anagramMap[key].push_back(s);
        }
        
        // 4. Transfer results to the final array
        vector<vector<string>> ans;
        ans.reserve(anagramMap.size()); // Pre-allocate memory to avoid resizing
        
        for (auto& pair : anagramMap) {
            // Use std::move to transfer ownership rather than copying the vectors
            ans.push_back(move(pair.second)); 
        }
        
        return ans;
    }
};