#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        while (head) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        head = reverse(head);
        Node* curr = head;
        int carry = 1;
        
        while (curr && carry) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            
            if (!curr->next && carry) {
                curr->next = new Node(carry);
                carry = 0;
            }
            curr = curr->next;
        }
        return reverse(head);
    }
};

void printList(Node* head){
    while (head) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(6);
    
    Solution s;
    head = s.addOne(head);
    printList(head);
    return 0;
}
