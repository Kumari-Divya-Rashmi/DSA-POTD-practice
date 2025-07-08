#include <vector>
#include <iostream>
using namespace std;
class Solution {
  private:
    vector<int> stack;
    vector<int> minStack;

  public:
    // Constructor
    Solution() {
        // code here
        // No special initialization needed
    }

    // Add an element to the top of Stack
    void push(int x) {
        stack.push_back(x);

        if (minStack.empty() || x <= minStack.back()) {
            minStack.push_back(x);
        } else {
            minStack.push_back(minStack.back());
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
            minStack.pop_back();
        }
    }

    // Returns top element of the Stack
    int peek() {
        if (stack.empty()) {
            return -1;
        }
        return stack.back();
    }

    // Finds minimum element of Stack
    int getMin() {
        if (minStack.empty()) {
            return -1;
        }
        return minStack.back();
    }
};