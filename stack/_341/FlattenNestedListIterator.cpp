//
// Created by fsindustry on 8/5/22.
//
#include <vector>
#include <stack>
#include <cassert>
#include <iostream>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
private:
    stack<NestedInteger> stack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        reverse(nestedList);
    }

    int next() {
        NestedInteger top = stack.top();
        stack.pop();
        return top.getInteger();
    }

    bool hasNext() {
        while (!stack.empty()) {
            NestedInteger top = stack.top();
            if (!top.isInteger()) {
                stack.pop();
                reverse(top.getList());
            } else {
                assert(top.isInteger());
                return true;
            }
        }

        return false;
    }

private:
    void reverse(const vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            stack.push(nestedList[i]);
        }
    }
};


class NestedIterator1 {
private:
    vector<int> data;
    int i;
public:
    NestedIterator1(vector<NestedInteger> &nestedList) {
        recursion(nestedList);
        i = 0;
    }

    int next() {
        return data[i++];
    }

    bool hasNext() {
        return i < data.size();
    }

private:
    void recursion(const vector<NestedInteger> &nestedList) {
        for (const NestedInteger &integer: nestedList) {
            if (integer.isInteger()) {
                data.push_back(integer.getInteger());
            } else {
                recursion(integer.getList());
            }
        }
    }
};