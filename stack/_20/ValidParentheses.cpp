//
// Created by fsindustry on 8/1/22.
//
#include <string>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if ('(' == s[i] || '[' == s[i] || '{' == s[i]) {
                stack.push(s[i]);
            } else {

                if (stack.empty()) {
                    return false;
                }

                char matched;
                switch (s[i]) {
                    case ')':
                        matched = '(';
                        break;
                    case ']':
                        matched = '[';
                        break;
                    default:
                        assert(s[i] == '}');
                        matched = '{';
                        break;
                }

                if (matched != stack.top()) {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.empty();
    }
};