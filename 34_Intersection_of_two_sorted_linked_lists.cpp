#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node dummy(0);
        Node* tail = &dummy;
        
        while (head1 && head2) {
            if (head1->data == head2->data) {
                tail->next = new Node(head1->data);
                tail = tail->next;
                head1 = head1->next;
                head2 = head2->next;
            }
            else if (head1->data < head2->data) {
                head1 = head1->next;
            }
            else {
                head2 = head2->next;
            }
        }
        return dummy.next;
    }
};

void print(Node* head){
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* h1 = new Node(1);
    h1->next = new Node(2);
    h1->next->next = new Node(3);
    h1->next->next->next = new Node(4);
    h1->next->next->next->next = new Node(6);
    
    Node* h2 = new Node(2);
    h2->next = new Node(4);
    h2->next->next = new Node(6);
    h2->next->next->next = new Node(8);
    
    Solution s;
    Node* ans = s.findIntersection(h1, h2);
    print(ans);
    return 0;
}
