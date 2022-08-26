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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy;
        ListNode *cur = head;
        ListNode *del = nullptr;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                del = cur;
                cur = cur->next;
                delete del;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};


void test1() {
    Solution s;
    vector<int> arr{1, 2, 6, 3, 4, 5, 6};
    ListNode *head = s.removeElements(build(arr), 6);
    cout << print(head) << endl;
    deleteNode(head);
}


int main() {
    test1();
}