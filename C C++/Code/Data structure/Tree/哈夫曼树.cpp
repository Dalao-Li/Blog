/*
        Name: Huffman tree coding
        Copyright:
        Author: YuanHao Li
        Date: 04/12/18 15:22
        Description:
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define LENGTH 6
//用以进行哈夫曼编码
int code[20];
//用以保存哈夫曼编码
string huffman[LENGTH];

int arr[LENGTH] = {12,24,35,67,46,55}; 

char alph[LENGTH] = {'A','B','C','D','E','F'}; 

typedef struct Tree {
	//节点的权值 
	int data;
	Tree* leftChild;
	Tree* rightChild;
} Tree, *TreeList;

//建哈夫曼树,返回根节点
TreeList createTree(int arr[]) {
	//建立指针数组用来保存节点信息
	TreeList leaves[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		TreeList leaf = new Tree;
		leaf->data = arr[i];
		leaf->leftChild = leaf->rightChild = NULL;
		leaves[i] = leaf;
	}
	//建立一个节点作为哈夫曼树的根节点
	TreeList root = NULL;
	//建立哈夫曼树 
	for (int i = 1; i < LENGTH; i++) {
		// min1表示最小权值的树根结点的下标,min2为次小权值节点的下标
		int min1 = -1, min2;
		//初始化min1与min2 
		for (int j = 0; j < LENGTH; j++) {
			if (leaves[j] != NULL && min1 == -1) {
				min1 = j;
				continue;
			}
			if (leaves[j] != NULL) {
				min2 = j;
				break;
			}
		}
		//找出最小值和次小值节点的下标
		for (int j = min2; j < LENGTH; j++) {
			if (leaves[j] != NULL) {
				if (leaves[j]->data < leaves[min1]->data) {
					min2 = min1;
					min1 = j;
				} else if (leaves[j]->data < leaves[min2]->data) {
					min2 = j;
				}
			}
		}
		//用最小权值树和次小权值树建立一棵新树,root指向树根结点
		root = new Tree;
		root->data = leaves[min1]->data + leaves[min2]->data;
		root->leftChild = leaves[min1];
		root->rightChild = leaves[min2];
		//将指向新树的指针赋给leaves指针数组中min1位置
		leaves[min1] = root;
		// min2位置为空
		leaves[min2] = NULL;
	}
	return root;
}

//根据权值获取下标 
int getIndex(int weight){
	for(int i = 0 ;i<LENGTH;i++){
		if(weight == arr[i]){
			return i;
		}
	}
} 

//递归进行哈夫曼树编码,len是当前树的层数
void huffmanCoding(TreeList& root, int len) {
	if (root == NULL) {
		return;
	}
	//若到叶子节点
	if (root->leftChild == NULL && root->rightChild == NULL) {
		//获取该节点权值对应的字符下标 
		int index = getIndex(root->data);
		//保存该字符的哈夫曼编码
		for (int i = 0; i < len; i++) {
			huffman[index].push_back(code[i] + '0');
		}
	}
	//否则继续进行哈夫曼编码的操作
	else {
		//左侧分支都记为零
		code[len] = 0;
		huffmanCoding(root->leftChild, len + 1);
		//右侧分支都记为一
		code[len] = 1;
		huffmanCoding(root->rightChild, len + 1);
	}
}

int main() {
	TreeList root = createTree(arr);
	huffmanCoding(root, 0);
	for (int i = 0; i < LENGTH; i++) {
		cout << alph[i] << "的哈夫曼编码是 : " << huffman[i] << endl;
	}
	return 0;
}
