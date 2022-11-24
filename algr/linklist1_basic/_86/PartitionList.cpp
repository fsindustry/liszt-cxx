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
    ListNode *partition(ListNode *head, int x) {

        if (!head) {
            return nullptr;
        }

        ListNode *lHead = new ListNode(0);
        ListNode *geHead = new ListNode(0);

        ListNode *l = lHead, *ge = geHead;
        ListNode *cur = head;
        while (cur) {
            if (cur->val < x) {
                l->next = cur;
                l = l->next;
            } else {
                ge->next = cur;
                ge = ge->next;
            }
            cur = cur->next;
        }

        l->next = geHead->next;
        ge->next = nullptr;
        ListNode *result = lHead->next;
        delete geHead;
        delete lHead;
        return result;
    }
};

void test1() {
    Solution s;
    vector<int> arr = {1, 4, 3, 2, 5, 2};
    ListNode *head = s.partition(build(arr), 3);
    cout << print(head) << endl;
    deleteNode(head);
}

void test2() {
    Solution s;
    vector<int> arr = {2, 1};
    ListNode *head = s.partition(build(arr), 2);
    cout << print(head) << endl;
    deleteNode(head);
}

int main() {
    test1();
    test2();
}
