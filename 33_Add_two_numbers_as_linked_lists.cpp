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
    
    Node* addTwoLists(Node* head1, Node* head2) {
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        Node *res = NULL, *tail = NULL;
        int carry = 0;
        
        while (head1 || head2 || carry) {
            int sum = carry;
            if (head1) sum += head1->data, head1 = head1->next;
            if (head2) sum += head2->data, head2 = head2->next;
            
            carry = sum / 10;
            Node* node = new Node(sum % 10);
            
            if (!res) res = tail = node;
            else tail->next = node, tail = node;
        }
        return reverse(res);
    }
};

void print(Node* head){
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* h1 = new Node(1);
    h1->next = new Node(2);
    h1->next->next = new Node(3);
    
    Node* h2 = new Node(9);
    h2->next = new Node(9);
    h2->next->next = new Node(9);
    
    Solution s;
    Node* ans = s.addTwoLists(h1, h2);
    print(ans);
    return 0;
}
