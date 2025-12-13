#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(NULL), next(NULL) {}
};

class Solution {
public:
    Node* reverseDLL(Node* head) {
        Node* curr = head;
        Node* temp = NULL;
        
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        
        if (temp)
            head = temp->prev;
        
        return head;
    }
};

void print(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(3);
    Node* second = new Node(4);
    Node* third = new Node(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    Solution s;
    head = s.reverseDLL(head);
    print(head);

    return 0;
}
