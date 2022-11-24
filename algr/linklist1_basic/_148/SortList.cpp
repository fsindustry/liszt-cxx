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
    ListNode *getMid(ListNode *head) {
        ListNode *dummy = new ListNode(INT32_MIN, head);
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

    ListNode *merge(ListNode *l1, ListNode *l2) {

        if (!l1 && !l2) {
            return nullptr;
        }

        auto *dummy = new ListNode(INT32_MIN);
        auto *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        if (l1) {
            cur->next = l1;
        } else {
            cur->next = l2;
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }

    ListNode *sortList(ListNode *head) {

        if (!head || !head->next) {
            return head;
        }

        ListNode *mid = getMid(head);
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(mid);
        return merge(l1, l2);
    }
};

void test1() {
    Solution s;
    vector<int> arr{4, 2, 1, 3};
    ListNode *head = s.sortList(build(arr));
    cout << print(head) << endl;
    deleteNode(head);
}

int main() {
    test1();
}