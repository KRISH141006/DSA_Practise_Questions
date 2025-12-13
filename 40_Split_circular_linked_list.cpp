#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    pair<Node*, Node*> splitList(Node* head) {
        Node *slow = head, *fast = head;
        
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast->next->next == head)
            fast = fast->next;
        
        Node* head1 = head;
        Node* head2 = slow->next;
        
        slow->next = head1;
        fast->next = head2;
        
        return {head1, head2};
    }
};

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    // Circular linked list: 10 -> 4 -> 9 -> 10
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(9);
    head->next->next->next = head;

    Solution s;
    auto res = s.splitList(head);

    printList(res.first);   // First half
    printList(res.second);  // Second half

    return 0;
}
