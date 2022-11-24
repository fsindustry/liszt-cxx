//
// Created by fsindustry on 7/26/22.
//
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct ListNode {

    int val;

    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *build(vector<int> &arr) {

    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }

    return head;
}


void deleteNode(ListNode *head) {

    if (nullptr == head) {
        return;
    }

    ListNode *cur = head, *del = nullptr;
    while (cur) {
        del = cur;
        cur = cur->next;
        delete del;
    }
}

string print(ListNode *head) {

    ostringstream s;
    if (nullptr == head) {
        s << "[]";
    }

    ListNode *cur = head;
    while (cur) {
        s << cur->val << " ";
        cur = cur->next;
    }

    return s.str();
}

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {

        if (!head || !head->next) {
            return head;
        }

        ListNode *dummy = new ListNode(INT32_MIN, head);
        ListNode *pre = dummy, *cur = head, *con = nullptr, *tail = nullptr;
        while (left > 1) {
            pre = cur;
            cur = cur->next;
            left--;
            right--;
        }

        con = pre;
        tail = pre->next;
        pre = cur;
        cur = cur->next;

        ListNode *next = nullptr;
        while (right > 1) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            right--;
        }

        con->next = pre;
        tail->next = cur;
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }

};

void test1() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = s.reverseBetween(build(arr), 2, 4);
    cout << print(head) << endl;
    deleteNode(head);
}

void test2() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = s.reverseBetween(build(arr), 1, 3);
    cout << print(head) << endl;
    deleteNode(head);
}

void test3() {
    Solution s;
    vector<int> arr = {5};
    ListNode *head = s.reverseBetween(build(arr), 1, 1);
    cout << print(head) << endl;
    deleteNode(head);
}

int main() {
    test1();
    test2();
    test3();
}