//
// Created by fsindustry on 7/4/22.
//
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> sMap;
        for (char c: s) {
            sMap[c]++;
        }

        string result;
        priority_queue<pair<int, char>> queue;
        for (auto p: sMap) {
            queue.push({p.second, p.first});
        }
        while (!queue.empty()) {
            pair<int, char> pair = queue.top();
            for (int i = 0; i < pair.first; i++) {
                result += pair.second;
            }
            queue.pop();
        }
        return result;
    }
};