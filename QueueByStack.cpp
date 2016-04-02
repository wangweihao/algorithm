/*======================================================
  > File Name: QueueByStack.cpp
  > Author: wwh
  > E-mail:  
  > Other :  
  > Created Time: 2016年03月31日 星期四 21时32分38秒
  =======================================================*/

#include <iostream>
#include <stack>

template <typename T> 
class CQueue {
    public:
        CQueue();
        ~CQueue();

        void appendTail(const T& node);
        T deleteHead();

    private:
        std::stack<T> stack1;
        std::stack<T> stack2;
};

template <typename T> 
CQueue<T>::CQueue() {

}

template <typename T>
CQueue<T>::~CQueue() {

}

template <typename T>
void
CQueue<T>::appendTail(const T& node) {
    stack1.push(node);   
}

template <typename T>
T
CQueue<T>::deleteHead() {
    if (stack2.empty()) {
        int size = stack1.size();
        for (int i = 0; i < size; ++i) {
            T& t = stack1.top();
            stack1.pop();
            stack2.push(t);
        }
    }


    if (stack2.size() == 0) {
        return -1;
    }
    T& ret = stack2.top();
    stack2.pop();

    return ret;
}

int main() {
    CQueue<int> queue;

    queue.appendTail(1);
    queue.appendTail(2);
    queue.appendTail(3);
    queue.appendTail(4);
    queue.appendTail(5);
    std::cout << queue.deleteHead() << std::endl;
    std::cout << queue.deleteHead() << std::endl;
    std::cout << queue.deleteHead() << std::endl;
    std::cout << queue.deleteHead() << std::endl;
    std::cout << queue.deleteHead() << std::endl;
    std::cout << queue.deleteHead() << std::endl;
}
