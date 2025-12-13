#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        
        if (a->data <= b->data) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }
    
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;
        
        Node* mid = getMid(head);
        Node* right = mid->next;
        mid->next = NULL;
        
        Node* left = mergeSort(head);
        right = mergeSort(right);
        
        return merge(left, right);
    }
};

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(60);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(40);
    head->next->next->next->next->next = new Node(30);

    Solution s;
    head = s.mergeSort(head);
    print(head);

    return 0;
}
