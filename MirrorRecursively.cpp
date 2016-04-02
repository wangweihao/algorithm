/*======================================================
    > File Name: MirrorRecursively.cpp
    > Author: wwh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月02日 星期六 22时14分57秒
 =======================================================*/

#include <iostream>

void MirrorRecursively (BinaryTreeNode* pNode) {
    if(pNode == NULL) {
        return;
    }
    if(pNode->pLeft == NULL && pNode->pRight == NULL) {
        return;
    }

    BinaryTreeNode *pTemp;
    pTemp = pNode->pLeft;
    pNode->pLeft = pNode->pRight;
    pNode->pRight = pTemp;

    if(pNode->pLeft != NULL) {
        MirrorRecursively(pNode->pLeft);
    }
    if(pNode->pRight != NULL) {
        MirrorRecursively(pNode->pRight);
    }
}

int main() {

}
