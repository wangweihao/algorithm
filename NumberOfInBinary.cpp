/*======================================================
    > File Name: NumberOfInBinary.cpp
    > Author: wwh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月02日 星期六 15时21分10秒
 =======================================================*/

#include <iostream>

/* 防止负数的情况，让 flag 移位 */
int NumberOf1(int n) {
    int count = 0;
    unsigned int flag = 1;

    while(flag) {
        if(n & flag) {
            count++;
        } 
        flag = (flag << 1);
    }

    return count;
}

/* 每次仅计算位为 1 的地方 */
int NumberOf2(int n) {
    int count = 0;

    while(n) {
        count++;
        n = n & (n-1);
    }

    return count;
}

int main() {
    int n = 127;
//    int n = 128;
    std::cout << NumberOf1(n) << std::endl;
    std::cout << NumberOf2(n) << std::endl;
}
