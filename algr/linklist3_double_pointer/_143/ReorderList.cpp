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
    void reorderList(ListNode *head) {
        ListNode *head2 = getMid(head);
        head2 = reverse(head2);

        auto *dummy = new ListNode(INT32_MIN);
        ListNode *cur = dummy;
        while (head && head2) {
            cur->next = head;
            head = head->next;
            cur = cur->next;

            cur->next = head2;
            head2 = head2->next;
            cur = cur->next;
        }

        if(head){
            cur->next = head;
        } else {
            cur->next = head2;
        }

        head = dummy->next;
        delete dummy;
    }

    ListNode *getMid(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        auto *dummy = new ListNode(INT32_MIN, head);
        ListNode *fast = dummy, *slow = dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *mid = slow->next;
        slow->next = nullptr;
        delete dummy;
        return mid;
    }

    ListNode *reverse(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *pre = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};


void test1() {
    Solution s;
    vector<int> arr{1, 2, 3, 4};
    ListNode *head = build(arr);
    s.reorderList(head);
    cout << print(head) << endl;
    deleteNode(head);
}

void test2() {
    Solution s;
    vector<int> arr{1, 2, 3, 4, 5};
    ListNode *head = build(arr);
    s.reorderList(head);
    cout << print(head) << endl;
    deleteNode(head);
}


int main() {
    test1();
    test2();
}