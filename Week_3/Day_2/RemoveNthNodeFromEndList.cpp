#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Create Linked List
ListNode* createList(int arr[], int n) {
    if (n == 0)
        return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print Linked List
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Count number of nodes
int countNodes(ListNode* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

// Remove Nth Node From End
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete node
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy.next;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, size);

    cout << "Original List: ";
    printList(head);

    int n;
    cout << "Enter n: ";
    cin >> n;

    // Input validation
    int totalNodes = countNodes(head);

    if (n < 1 || n > totalNodes) {
        cout << "Invalid value of n!" << endl;
        return 0;
    }

    head = removeNthFromEnd(head, n);

    cout << "Updated List: ";
    printList(head);

    return 0;
}