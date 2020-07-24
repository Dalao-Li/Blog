- [一、概念](#一概念)
- [二、实现](#二实现)
  - [节点定义](#节点定义)
  - [1. 获取节点信息](#1-获取节点信息)
  - [2. 判断](#2-判断)
  - [3. 旋转](#3-旋转)
    - [3.1 左旋](#31-左旋)
    - [3.2 右旋](#32-右旋)
    - [3.3 先右旋后左旋](#33-先右旋后左旋)
    - [3.4 先左旋后右旋](#34-先左旋后右旋)
# 一、概念
平衡二叉树 
> - 树中任意结点的平衡因子(`左子树高度 - 右子树高度`)绝对值不超过1  
> - 树中的每个左子树和右子树都是AVL树  
> - AVL树是特殊的二叉搜索树
> - AVL树的旋转操作是指在平衡因子大于1时, 会通过旋转来调整树的结构, 以重新满足平衡因子不超过1  

![](http://cdn.hurra.ltd/img/20200715102437.png)

标记平衡因子

![](http://cdn.hurra.ltd/img/20200715102536.png)

该树为AVL树

# 二、实现

## 节点定义
```c
template <class T>
struct AVLNode{
    T value;
    AVLNode<T> *leftSon;
    AVLNode<T> *rightSon;
    int height;
    AVLNode(T value,AVLNode<T> *leftSon,AVLNode<T> *rightSon,int height){
        this->value = value;
        this->leftSon = leftSon;
        this->rightSon = rightSon;
        this->height = height;
    }
};
```

## 1. 获取节点信息
```c
//获取某节点的高度
template <class T>
int getHeight(AVLNode<T> *root){
    if(root == nullptr){
        return 0;
    }
    return root->height;
}

//获取节点的平衡因子
template <class T>
int getBalanceFactor(AVLNode<T> *root){
    if(root == nullptr){
        return 0;
    }
    return getHeight(root->leftSon) - getHeight(root->rightSon);
}
```


## 2. 判断
```c
//判断是否平衡
template <class T>
bool isBalance(AVLNode<T> *root){
    if(root == nullptr){
        return true;
    }
    if(abs(getBalanceFactor(root)) > 1){
        return false;
    }
    return isBalance(root->leftSon) && isBalance(root->rightSon);
}
```

## 3. 旋转

### 3.1 左旋

> - AVL树若在`右子树`插入右孩子导致失衡时,需进行单左旋调整  
> - 旋转围绕最小失衡子树的根节点进行

图示

![](http://cdn.hurra.ltd/img/20200715151943.png)

原本平衡的AVL树插入节点7后导致不平衡;最小失衡子树的根节点为节点5

实现代码:
```c
//左旋;root为最小失衡子树的根节点
template <class T>
AVLNode<T> *leftRotation(AVLNode<T> *root){
    AVLNode<T> *p = root->rightSon;
    root->rightSon = p->leftSon;
    p->leftSon = root;
    //改变指向后,更新结点对应的高度
    root->height = max(getHeight(root->leftSon),getHeight(root->rightSon))+1;
    p->height = max(getHeight(p->leftSon),getHeight(p->rightSon))+1;
    return p;
}
```
代码过程图示:

![](http://cdn.hurra.ltd/img/20200715222000.png)

---

### 3.2 右旋

> - AVL树若在`左子树`插入`左孩子`导致失衡时,需进行单右旋调整  
> - 旋转围绕最小失衡子树的根节点进行

图示

![](http://cdn.hurra.ltd/img/20200715154814.png)

实现代码:
```c
template <class T>
AVLNode<T>* rightRotation(AVLNode<T>* root){
    AVLNode<T> *p = root->leftSon;
    root->leftSon = p->rightSon;
    p->rightSon = root;
    root->height = max(getHeight(root->leftSon), getHeight(root->rightSon)) + 1;
    p->height = max(getHeight(p->leftSon), getHeight(p->rightSon)) + 1;
    return p;
}
```

代码过程图示:

![](http://cdn.hurra.ltd/img/20200715212605.png)
### 3.3 先右旋后左旋
> - AVL树在`右子树`上插入`左孩子`导致失衡时,需进行先右旋后左旋调整

```c
template <class T>
AVLNode<T>* rightLeftRotation(AVLNode<T> *root){
    root->rightSon = rightRotation(root->rightSon);
    return leftRotation(root);
}
```

图示:

![](http://cdn.hurra.ltd/img/20200715220529.png)

其中,红色为插入节点;绿色为最小失衡子树的根节点



---

### 3.4 先左旋后右旋
> - AVL树在`左子树`上插入`右孩子`导致失衡时,需进行先左旋后右旋调整

```c
template <class T>
AVLNode<T>* leftRightRotation(AVLNode<T> *root){
    root->leftSon = leftRotation(root->leftSon);
    return rightRotation(root);
}
```

图示:

![](http://cdn.hurra.ltd/img/20200715221154.png)

其中,红色为插入节点;绿色为最小失衡子树的根节点




![](http://cdn.hurra.ltd/img/赞赏码.png)
