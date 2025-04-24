#include <iostream>
#include <vector>
using namespace std;

class MinStack {
    // design a stack which can return minimum element in O(1) time complexity
    // approach : use two stacks , one for storing elements and other for storing minimum element till that point
    // time complexity : O(1)
    public:
        vector<int> mystack;
        vector<int> minstack;
        MinStack() {
        }
    
        void push(int val) {
            mystack.push_back(val);
            if(minstack.empty()){
                minstack.push_back(val);
            }
            else{
                int val2 = min(minstack.back(),val);
                minstack.push_back(val2);
            }
        }
    
        void pop() { mystack.pop_back();minstack.pop_back(); }
    
        int top() { return mystack.back(); }
    
        int getMin() { return minstack.back(); }
    };

int main(){
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->push(2);
    obj->push(-1);
    cout<<"min of stack :"<<obj->getMin()<<endl;
    cout<<"popped from stack"<<endl;
    obj->pop();
    cout<<"top of stack :"<<obj->top()<<endl;
    cout<<"min of stack :"<<obj->getMin()<<endl;
    return 0;
}