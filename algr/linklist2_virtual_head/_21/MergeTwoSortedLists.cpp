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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

        if (!list1 && !list2) {
            return nullptr;
        }

        ListNode *dummy = new ListNode(INT32_MIN);
        ListNode *cur = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        if (list1) {
            cur->next = list1;
        } else {
            cur->next = list2;
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};


void test1() {
    Solution s;
    vector<int> arr1{1, 2, 4};
    vector<int> arr2{1, 3, 4};
    ListNode *head = s.mergeTwoLists(build(arr1), build(arr2));
    cout << print(head) << endl;
    deleteNode(head);
}


int main() {
    test1();
}