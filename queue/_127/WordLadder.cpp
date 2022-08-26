//
// Created by fsindustry on 2022/8/26.
//
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        if (wordSet.find(beginWord) != wordSet.end()) {
            wordSet.erase(beginWord);
        }
        vector<string> visited;

        while (!q.empty()) {
            string word1 = q.front().first;
            int step = q.front().second;
            q.pop();

            visited.clear();
            for (string word2 : wordSet) {
                if (matched(word1, word2)) {
                    if (word2 == endWord) {
                        return step + 1;
                    }

                    q.push(make_pair(word2, step + 1));
                    visited.push_back(word2);
                }
            }

            for (string &word : visited) {
                wordSet.erase(word);
            }
        }

        return 0;
    }

    static bool matched(string &word1, string &word2) {
        int diff = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                diff++;
                if (diff > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};