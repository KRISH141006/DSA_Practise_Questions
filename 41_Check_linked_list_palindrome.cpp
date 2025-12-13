#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        while (head) {
            Node* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;
        
        Node *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* second = reverse(slow->next);
        Node* first = head;
        
        while (second) {
            if (first->data != second->data)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    Solution s;
    cout << s.isPalindrome(head);   // 1 = true, 0 = false
    return 0;
}
