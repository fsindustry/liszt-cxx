//
// Created by fsindustry on 8/1/22.
//
#include <string>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> operands;
        for (string &s: tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                operands.push(atoi(s.c_str()));
            } else {
                int o1 = operands.top();
                operands.pop();
                int o2 = operands.top();
                operands.pop();

                switch (s[0]) {
                    case '+':
                        operands.push(o1 + o2);
                        break;
                    case '-':
                        operands.push(o2 - o1);
                        break;
                    case '*':
                        operands.push(o1 * o2);
                        break;
                    default:
                        assert(s[0] == '/');
                        operands.push(o2 / o1);
                        break;
                }
            }
        }
        return operands.top();
    }
};