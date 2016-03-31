/*======================================================
    > File Name: maxSumInInterval.c
    > Author: wwh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月27日 星期日 18时42分16秒
 =======================================================*/

#include <stdio.h>


int main() {
    int array[10] = {-1, -2, 3, 4, -5, 6, 7, -14, -2, 10};
    int max = 0;
    int sum = 0;

    for (int i = 0; i < 10; ++i) {
        if (sum < 0) {
            sum = 0;
        }
        sum += array[i];
        if(sum > max) {
            max = sum;
        }
    }
    printf("max:%d\n", max);
}
 
