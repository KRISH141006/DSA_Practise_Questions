#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    int intersectPoint(Node* head1, Node* head2) {
        Node* a = head1;
        Node* b = head2;
        
        while (a != b) {
            a = (a == NULL) ? head2 : a->next;
            b = (b == NULL) ? head1 : b->next;
        }
        return a->data;   // guaranteed intersection
    }
};

int main() {
    // Common part
    Node* common = new Node(15);
    common->next = new Node(30);

    // First list: 10 -> 15 -> 30
    Node* head1 = new Node(10);
    head1->next = common;

    // Second list: 3 -> 6 -> 9 -> 15 -> 30
    Node* head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(9);
    head2->next->next->next = common;

    Solution s;
    cout << s.intersectPoint(head1, head2);

    return 0;
}
