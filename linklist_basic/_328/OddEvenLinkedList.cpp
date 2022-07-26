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
    ListNode *oddEvenList(ListNode *head) {

        if (!head || !head->next) {
            return head;
        }

        ListNode *oddHead = new ListNode(0);
        ListNode *evenHead = new ListNode(0);

        ListNode *odd = oddHead, *even = evenHead;
        ListNode *cur = head;
        int idx = 1;
        while (cur) {
            if (idx % 2 == 0) {
                even->next = cur;
                even = even->next;
            } else {
                odd->next = cur;
                odd = odd->next;
            }

            cur = cur->next;
            idx++;
        }

        odd->next = evenHead->next;
        even->next = nullptr;
        ListNode *result = oddHead->next;
        delete oddHead;
        delete evenHead;
        return result;
    }
};

void test1() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = s.oddEvenList(build(arr));
    cout << print(head) << endl;
    deleteNode(head);
}

int main() {
    test1();
}