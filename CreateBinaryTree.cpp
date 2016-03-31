/*======================================================
    > File Name: CreateBinaryTree.cpp
    > Author: wwh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月31日 星期四 17时36分10秒
 =======================================================*/

#include <iostream>
#include <exception>


struct BinaryTreeNode;
BinaryTreeNode* Construct(int* preorder, int* inorder, int length);
BinaryTreeNode* ConstructCore(
            int* startPreorder, int* endPreorder,
            int* startInorder,  int* endInorder
        );

struct BinaryTreeNode {
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
    if (preorder == NULL || inorder == NULL || length <= 0) {
        return nullptr;
    }
    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BinaryTreeNode* ConstructCore(
            int* startPreorder, int* endPreorder,
            int* startInorder,  int* endInorder
        ) {
    /* 从先序遍历获取并创建根节点 */
    int rootValue = startInorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->value = rootValue;
    root->left = root->right = nullptr;

    /* 将每一个节点都当作一颗子树的根，直到遍历完先序 
     * 说明遍历完了 */
    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        }else {
            //throw std::exception("input value error");
            printf("error\n");
            exit(1);
        }
    }

    /* 找到根节点在中序遍历中的位置，然后平分中序遍历 */
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        ++rootInorder;
    }

    if (rootInorder == endInorder && *rootInorder != rootValue) {
        //throw std::exception("input value error");
        printf("error\n");
        exit(1);
    }

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0) {
        root->left = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder) {
        root->right = ConstructCore(leftPreorderEnd + 1, endInorder, rootInorder + 1, endInorder);
    }

    return root;
}


int main() {
    int a[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int b[8] = {4, 7, 2, 1, 5, 3, 8, 6};

    BinaryTreeNode *root = Construct(a, b, 8);   
}
