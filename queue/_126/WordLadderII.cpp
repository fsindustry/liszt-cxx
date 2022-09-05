//
// Created by fsindustry on 2022/8/26.
//
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

// leetcode不认
class Solution {
public:

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {

        unordered_map<string, unordered_set<string>> graph;
        vector<vector<string>> res;

        // 通过BFS获取最短路径，同时建图
        // 注：广度优先遍历，求出最短路径后，则上层的图都构建完成
        int depth = minDepth(beginWord, endWord, wordList, graph);
        if (depth == 0) {
            return {};
        }

        // 通过DFS收集最短路径
        vector<string> path;
        unordered_set<string> visited;
        dfs(beginWord, endWord, path, visited, depth, graph, res);
        return res;
    }

private:
    void dfs(const string &beginWord, const string &endWord, vector<string> &path,
             unordered_set<string> &visited, int depth,
             unordered_map<string, unordered_set<string>> &graph,
             vector<vector<string>> &res) {

        if (beginWord == endWord) {
            path.push_back(endWord);
            res.push_back(path);
            path.pop_back();
            return;
        }

        if (depth == 0) {
            return;
        }

        path.push_back(beginWord);
        visited.insert(beginWord);
        for (const auto &s : graph[beginWord]) {
            if (!visited.count(s)) {
                dfs(s, endWord, path, visited, depth - 1, graph, res);
            }
        }
        visited.erase(beginWord);
        path.pop_back();
    }

    static int minDepth(string &beginWord, string &endWord, vector<string> &wordList,
                        unordered_map<string, unordered_set<string>> &graph) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<string> queue;
        queue.push(beginWord);
        if (wordSet.find(beginWord) != wordSet.end()) {
            wordSet.erase(beginWord);
        }

        int depth = 0;
        vector<string> visited;
        while (true) {

            int count = queue.size();
            if (0 == count) {
                break;
            }
            depth++;
            visited.clear();
            while (count--) {
                string &front = queue.front();
                queue.pop();

                if (front == endWord) {
                    return depth;
                }

                for (const string &s: wordSet) {
                    if (matched(front, s)) {
                        queue.push(s);
                        graph[front].insert(s);
                        visited.push_back(s);
                    }
                }
            }

            for (string &word : visited) {
                wordSet.erase(word);
            }
        }

        return depth;
    }

    static bool matched(const string &s1, const string &s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
                if (diff > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};

void test1() {
    Solution s;
    string begin = "qa";
    string end = "sq";
    vector<string> wordList = {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av",
                               "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr",
                               "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as",
                               "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz",
                               "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st",
                               "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr",
                               "pa", "he", "lr", "sq", "ye"};
    vector<vector<string>> res = s.findLadders(begin, end, wordList);
    for (const auto &a : res) {
        for (const auto &b : a) {
            cout << b << "->";
        }
        cout << endl;
    }
}

int main() {
    test1();
}