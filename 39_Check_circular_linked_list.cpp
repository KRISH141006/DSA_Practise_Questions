#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    bool isCircular(Node* head) {
        if (!head) return true;
        
        Node* temp = head->next;
        while (temp && temp != head) {
            temp = temp->next;
        }
        return (temp == head);
    }
};

int main() {
    // Circular linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;

    Solution s;
    cout << s.isCircular(head);   // Output: 1 (true)

    return 0;
}
