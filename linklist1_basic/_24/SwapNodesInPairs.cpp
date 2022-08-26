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
    ListNode *swapPairs(ListNode *head) {

        if (!head || !head->next) {
            return head;
        }

        ListNode *dummy = new ListNode(INT32_MIN, head);
        ListNode *pre = dummy, *cur = head, *next = nullptr;
        while (cur && cur->next) {
            next = cur->next;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
            pre = cur;
            cur = cur->next;
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

void test1() {
    Solution s;
    vector<int> arr{1, 2, 3, 4};
    ListNode *head = s.swapPairs(build(arr));
    cout << print(head) << endl;
    deleteNode(head);
}


int main() {
    test1();
}