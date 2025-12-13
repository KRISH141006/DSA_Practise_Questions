#include <iostream>
#include <vector>
using namespace std;

class kStacks {
    
    // main array to store elements
    int *arr;    
    
    // stores top index for each stack
    int *top;    
    
    // size of each segment
    int segSize; 

public:
    kStacks(int n, int k) {
        segSize = n / k;
        arr = new int[n];
        top = new int[k];

        // initialize top pointers
        for (int i = 0; i < k; i++)
            top[i] = i * segSize - 1;
    }

    // push element x into stack i
    void push(int x, int i) {
        int end = (i + 1) * segSize - 1;

        if (top[i] == end) {
            cout << "Stack " << i << " overflow" << endl;
            return;
        }

        top[i]++;
        arr[top[i]] = x;
    }

    // pop element from stack i
    int pop(int i) {
        int start = i * segSize;

        if (top[i] < start) {
            cout << "Stack " << i << " underflow" << endl;
            return -1;
        }

        int val = arr[top[i]];
        top[i]--;
        return val;
    }
};

int main() {
    int n = 4, k = 2;
    kStacks st(n, k);

    // Each operations has the following format:
    // 1. Push operation → {1, value, stackNumber}
    // 2. Pop operation  → {2, stackNumber}
    vector<vector<int>> operations = {
        {1, 5, 0},  
        {1, 9, 0},
        {1, 10, 0}, 
        {1, 15, 1}, 
        {2, 0},
        {2, 1},
        {2, 1}
    };

    for (auto &op : operations) {
        
        if (op[0] == 1) { 
            int x = op[1], m = op[2];
            st.push(x, m);
        } else if (op[0] == 2) { 
            int m = op[1];
            int res = st.pop(m);
            if (res != -1)
                cout << "Popped Element: " << res << endl;
        }
    }

    return 0;
}