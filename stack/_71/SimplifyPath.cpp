//
// Created by fsindustry on 8/1/22.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        for (int start = 1, i = 1; i <= path.length(); i++) {
            if (i == path.length() || path[i] == '/') {
                string words = path.substr(start, i - start);
                if (!words.empty() && words == ".." && !stack.empty()) {
                    stack.pop_back();
                } else if (!words.empty() && words != "..") {
                    if (words != ".") {
                        stack.push_back(words);
                    }
                }
                start = i + 1;
            }
        }

        string res = "";
        for (string &s: stack) {
            res += "/" + s;
        }
        return res == "" ? "/" : res;
    }
};


void test1() {
    Solution s;
    string input = "/home/";
    cout << "Output: " << s.simplifyPath(input) << endl;
}

void test2() {
    Solution s;
    string input = "/../";
    cout << "Output: " << s.simplifyPath(input) << endl;
}

void test3() {
    Solution s;
    string input = "/a//b////c/d//././/..";
    cout << "Output: " << s.simplifyPath(input) << endl;
}

int main() {
//    test1();
//    test2();
    test3();
}