#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    Node* getTail(Node* cur) {
        while (cur && cur->next)
            cur = cur->next;
        return cur;
    }

    Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
        Node* pivot = end;
        Node *prev = NULL, *cur = head, *tail = pivot;

        while (cur != pivot) {
            if (cur->data < pivot->data) {
                if (!(*newHead))
                    *newHead = cur;
                prev = cur;
                cur = cur->next;
            } else {
                if (prev)
                    prev->next = cur->next;
                Node* tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if (!(*newHead))
            *newHead = pivot;

        *newEnd = tail;
        return pivot;
    }

    Node* quickSortRecur(Node* head, Node* end) {
        if (!head || head == end)
            return head;

        Node *newHead = NULL, *newEnd = NULL;
        Node* pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {
            Node* tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = NULL;

            newHead = quickSortRecur(newHead, tmp);

            tmp = getTail(newHead);
            tmp->next = pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd);
        return newHead;
    }

    Node* quickSort(Node* head) {
        return quickSortRecur(head, getTail(head));
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
    Node* head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(3);
    head->next->next->next = new Node(8);

    Solution s;
    head = s.quickSort(head);
    print(head);

    return 0;
}
