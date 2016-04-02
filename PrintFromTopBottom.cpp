/*======================================================
    > File Name: PrintFromTopBottom.cpp
    > Author: wwh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月02日 星期六 22时53分37秒
 =======================================================*/

#include <iostream>
#include <deque>

void PrintFromTopBottom(BinaryTreeNode* pTreeRoot) {
    if(pTreeRoot == NULL) {
        return;
    }

    std::deque<BinaryTreeNode*> dequeTreeNode;

    dequeTreeNode.push_back(pTreeRoot);

    while(!dequeTreeNode.empty()) {
        BinaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();

        printf("%d\n", pNode->mValue);
        
        if(pNode->left != NULL) {
            dequeTreeNode.push_back(pNode->left);
        }
        if(pNode->right != NULL) {
            dequeTreeNode.push_back(pNode->right);
        }
    }
}

int main() {

}
