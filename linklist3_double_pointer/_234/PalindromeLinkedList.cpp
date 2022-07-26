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

    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode *head2 = getMid(head);
        head2 = reverse(head2);

        while (head && head2) {
            if (head->val != head2->val) {
                return false;
            } else {
                head = head->next;
                head2 = head2->next;
            }
        }

        return true;
    }

    ListNode *getMid(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        auto *dummy = new ListNode(0, head);
        ListNode *fast = dummy, *slow = dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *result = slow->next;
        slow->next = nullptr;
        delete dummy;
        return result;
    }

    ListNode *reverse(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *cur = head, *pre = nullptr, *next = nullptr;
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
    vector<int> arr{1, 2, 2, 1};
    ListNode *head = build(arr);
    cout << s.isPalindrome(head) << endl;
    deleteNode(head);
}

void test2() {
    Solution s;
    vector<int> arr{1, 2};
    ListNode *head = build(arr);
    cout << s.isPalindrome(head) << endl;
    deleteNode(head);
}


int main() {
    test1();
    test2();
}