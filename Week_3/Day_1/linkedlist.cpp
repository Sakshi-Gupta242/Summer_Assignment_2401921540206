#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

bool hasCycle(ListNode* head) {

    if (head == NULL || head->next == NULL)
        return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {

    // Create nodes
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create cycle (tail -> second node)
    fourth->next = second;

    if (hasCycle(head))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}