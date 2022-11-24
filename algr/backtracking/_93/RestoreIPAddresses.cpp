//
// Created by fsindustry on 2022/9/19.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {

    vector<string> res;

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty() || s.length() > 12 || s.length() < 4) {
            return res;
        }

        vector<int> path;
        path.push_back(s[0] - '0');
        findAddress(s, 1, path);
        return res;
    }

    void findAddress(string &s, int idx, vector<int> &path) {
        if (s.length() == idx) {
            if (path.size() == 4) {
                res.push_back(toIp(path));
            }
            return;
        }

        // 遍历同一节点的子接点
        int cur = path.back();
        int next = cur * 10 + (s[idx] - '0');
        if (next <= 255 && cur != 0) {
            path.pop_back();
            path.push_back(next);
            findAddress(s, idx + 1, path);
            path.pop_back();
            path.push_back(cur);
        }

        // 递归遍历当前节点的下一级节点
        if (path.size() < 4) {
            path.push_back(s[idx] - '0');
            findAddress(s, idx + 1, path);
            path.pop_back();
        }
    }

    static string toIp(vector<int> &path) {
        string ip = to_string(path[0]);
        for (int i = 1; i < path.size(); i++) {
            ip += "." + to_string(path[i]);
        }
        return ip;
    }
};

void print_vec(const vector<string> &vec) {
    for (const string &e: vec)
        cout << e << " ";
    cout << endl;
}


void test1() {
    Solution s;
    string input = "101023";
    print_vec(s.restoreIpAddresses(input));
}

int main() {
    test1();
}