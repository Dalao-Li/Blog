#include<iostream>
#include<string.h>
#define MAX_SIZE 26
#define LENGTH 6
using namespace std;

//用以进行哈夫曼编码
int code[20];

string huffman[LENGTH];

typedef struct logSheet {
	char character[MAX_SIZE];
	int occurrenceNumber[MAX_SIZE];
    
} logSheet;



typedef struct Tree {
	int data;  //哈夫曼树中节点的权值
	Tree * leftChild;
	Tree * rightChild;
} Tree,*TreeList;

TreeList createTree(logSheet sheet) {
	//建立一个指针数组用来保存节点信息
	TreeList leaves[LENGTH];
	TreeList leaf;
	//建立一个节点作为哈夫曼树的根节点
	TreeList root = NULL;
	for (int i = 0; i < LENGTH; i++) { //初始化结构体指针数组,数组中每一个元素为一个结构体指针类型
		leaf = new Tree;

		leaf->data = sheet.occurrenceNumber[i];
		leaf->leftChild = leaf->rightChild = NULL;
		leaves[i] = leaf;
	}
	//进行 n-1 次循环建立哈夫曼树
	for(int i = 1; i < LENGTH; i++) {
		//min1表示森林中具有最小权值的树根结点的下标,min2为次最小的下标
		int min1 = -1, min2;
		for(int j = 0; j < LENGTH; j++) {
			if (leaves[j] != NULL && min1 == -1) {
				min1 = j;
				continue;
			}
			if (leaves[j] != NULL) {
				min2 = j;
				break;
			}
		}
		//将指针数组中的指针指向的最小值赋值给索引号为min1的,次小值赋值给索引号为min2的
		for (int j = min2; j < LENGTH; j++) {
			if(leaves[j] != NULL) {
				if(leaves[j]->data < leaves[min1]->data) {
					min2 = min1;
					min1 = j;
				} else if(leaves[j]->data < leaves[min2]->data) {
					min2 = j;
				}
			}
		}
		//由最小权值树和次最小权值树建立一棵新树,root指向树根结点
		root = new Tree;
		//更新新节点权值
		root->data = leaves[min1]->data + leaves[min2]->data;
		root->leftChild = leaves[min1];
		root->rightChild = leaves[min2];
		//将指向新树的指针赋给leaves指针数组中min1位置,节约空间
		leaves[min1] = root;
		//min2位置为空
		leaves[min2] = NULL;
	}
	return root;
}

//递归进行哈夫曼树编码函数
void huffmanCoding(TreeList &root,int len,logSheet sheet) {
	//当这个节点不为空
	if(root != NULL) {
		//到了叶子节点
		if(root->leftChild == NULL && root->rightChild == NULL) {
			//确定这是哪一个字符的哈夫曼码
			int index;
			for(int i = 0; i<LENGTH; i++) {
				//依据权值确定字符
				if(root->data == sheet.occurrenceNumber[i]) {
					index = i;
					break;
				}
			}
			for(int i = 0; i < len; i++) {
				//保存哈夫曼编码
				huffman[index].push_back(code[i]+'0');
			}
		}
		//否则继续进行哈夫曼编码的操作
		else {
			//左边分支都记为零
			code[len] = 0;
			huffmanCoding(root->leftChild,len+1,sheet);
			//右侧分支都记为1
			code[len] = 1;
			huffmanCoding(root->rightChild,len+1,sheet);
		}
	}
}


//A3B9C5D12E6F15
int main() {
	int arr[LENGTH] = {3,9,5,12,6,15};
	char alph[LENGTH] = {'A','B','C','D','E','F'};
	
	logSheet sheet;
	
	for(int i = 0; i<LENGTH; i++) {
		sheet.character[i] = alph[i];
		sheet.occurrenceNumber[i] = arr[i];
	}
	
	//返回指向哈夫曼树根节点的指针
	TreeList root = createTree(sheet);
	
	//进行哈夫曼编码
	huffmanCoding(root,0,sheet);
	for(int i = 0; i<LENGTH; i++) {
		cout<<sheet.character[i]<<"的哈夫曼编码是"<<huffman[i]<<endl;
	}
	return 0;
}
