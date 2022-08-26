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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        if (!l1 && !l2) {
            return nullptr;
        }

        auto *dummy = new ListNode(0);
        ListNode *cur = dummy;
        int carry = 0, sum = 0, val = 0;
        while (l1 || l2) {
            if (l1 && l2) {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                sum = l1->val + carry;
                l1 = l1->next;
            } else if (l2) {
                sum = l2->val + carry;
                l2 = l2->next;
            }

            carry = sum / 10;
            val = sum % 10;
            cur->next = new ListNode(val);
            cur = cur->next;
        }

        if (carry > 0) {
            cur->next = new ListNode(carry);
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

void test1() {
    Solution s;
    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};
    ListNode *l1 = build(arr1);
    ListNode *l2 = build(arr2);
    ListNode *head = s.addTwoNumbers(l1, l2);
    cout << print(head) << endl;
    deleteNode(l1);
    deleteNode(l2);
    deleteNode(head);
}

void test2() {
    Solution s;
    vector<int> arr1 = {9, 9, 9, 9, 9, 9, 9};
    vector<int> arr2 = {9, 9, 9, 9};
    ListNode *l1 = build(arr1);
    ListNode *l2 = build(arr2);
    ListNode *head = s.addTwoNumbers(l1, l2);
    cout << print(head) << endl;
    deleteNode(l1);
    deleteNode(l2);
    deleteNode(head);
}

int main() {
    test1();
    test2();
}