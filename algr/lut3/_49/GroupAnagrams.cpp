//
// Created by fsindustry on 7/13/22.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {

        unordered_map<string, vector<string>> anagramMap;
        for (string &str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            anagramMap[key].push_back(str);
        }

        vector<vector<string>> result;
        // allocate appointted space for result;
        result.reserve(anagramMap.size());
        for (auto &p: anagramMap) {
            result.push_back(p.second);
        }
        return result;
    }
};