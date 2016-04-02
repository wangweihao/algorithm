/*======================================================
    > File Name: EotateTheArray.cpp
    > Author: wwh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月02日 星期六 12时42分54秒
 =======================================================*/

#include <iostream>

int findRotateTheArray(int* a, int length) {
    if (a == NULL || length <= 0) {
        return -1;
    }

    int start = 0;
    int end = length-1;
    int middle;

    while (start < end) {
        if (end - start == 1) {
            middle = end;
            break;
        }
        middle = start + (end-start)/2;
        if (a[middle] < a[start]) {
            end = middle;
        }else {
            start = middle;
        }
    }

    return a[middle];
}

int main() {
    int a[16] = {7, 8, 9, 10, 11, 12, 13, 13, 14, 0, 1, 2, 3, 4, 5, 6};

    int result = findRotateTheArray(a, 16);
    std::cout << "min:" << result << std::endl; 
}
