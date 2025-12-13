// C++ program to find a pair with given sum x
// using map
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to find pairs in the doubly linked list
// whose sum equals the given value x
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
    vector<pair<int, int>> ans;
    unordered_map<int, Node *> visited;
    Node *currNode = head;

    // Traverse the doubly linked list
    while (currNode != nullptr) {
      
        int x = target - currNode->data;

        // Check if the target exists in the map
        if (visited.find(x) != visited.end()) {
          
            // Pair found
            ans.push_back({x, currNode->data});
        }

        // Store the current node's value in the map
        visited[currNode->data] = currNode;
        currNode = currNode->next;
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
  
    // Create a doubly linked list: 1 <-> 2 <-> 4 <-> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    int target = 7;
    vector<pair<int, int>> pairs = findPairsWithGivenSum(head, target);

    if (pairs.empty()) {
        cout << "No pairs found." << endl;
    }
    else {
        for (auto &pair : pairs) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    return 0;
}