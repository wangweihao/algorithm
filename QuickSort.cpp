/*======================================================
    > File Name: QuickSort.cpp
    > Author: wwh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月02日 星期六 08时45分35秒
 =======================================================*/

#include <iostream>
#include <stdlib.h>

int QuickSortCore(int* a, int length, int start, int end) {
    if (a == NULL || length <= 0 || start < 0 || end < 0) {
        std::cout << "input error" << std::endl;
        exit(1);
    }

    int middle = a[start];
    int index = start;

    if ((end-start) == 1) {
        if (a[start] > a[end]) {
            int t = a[start];
            a[start] = a[end];
            a[end] = t;
        }
    }else {
        start++;
        while (start != end) {
            if (index < start) {
                if (a[end] < middle) {
                    a[index] = a[end];
                    index = end;
                }
                end--;
            }else if (index > end) {
                if (a[start] > middle) {
                    a[index] = a[start];
                    index = start;
                }
                start++;
            }
        }
        a[index] = middle;
    }
    return index;
}

void QuickSort(int* a, int length, int start, int end) {
    if (a == NULL || length <= 0) {
        std::cout << "input error" << std::endl;
        exit(1);
    }

    if (start == end) {
        return;
    }
    int index = QuickSortCore(a, length, start, end);

    if (index > start) {
        QuickSort(a, length, start, index-1);
    }
    if (index < end) {
        QuickSort(a, length, index+1, end);
    }
}

int main() {
    int a[10] = {4, 7, 6, 8, 5, 1, 2, 3, 10, 9};
    QuickSort(a, 10, 0, 9);

    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
