//
// Created by fsindustry on 2022/8/26.
//
#include <string>
#include <queue>
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }

        priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> q(mycmp);
        for (ListNode *l : lists) {
            if (l) {
                q.push(l);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (!q.empty()) {
            ListNode *top = q.top();
            q.pop();
            cur->next = top;
            cur = cur->next;
            if(top->next){
                q.push(top->next);
            }
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }

    static bool mycmp(const ListNode *l1, const ListNode *l2) {
        return l1->val > l2->val;
    }
};