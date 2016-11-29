/**************************************
	30 Nov. 2016
	Haeseong Jeon

	5639. Binary Search Tree
    https://www.acmicpc.net/problem/5639
***************************************/
#include <iostream> // std::cin, cout
using namespace std;

typedef class Node {
private:
	int _data;
	class Node* _leftChild;
	class Node* _rightChild;
public:
	Node(int aData);
	void setData(int aData);
	void setLeftChild(class Node* lc);
	void setRightChild(class Node* rc);
	int data();
	class Node* leftChild();
	class Node* rightChild();
}Node;

typedef class Tree {
private:
	Node* _root;
public:
	void setRoot();
	bool isEmpty();
	Tree();
	int insert(int aData);
	int insert(int aData, Node* pNode);
	void postorder();
	void postorder(Node* pNode);
}Tree;

Node::Node(int aData) {
	_data = aData;
	_leftChild = NULL;
	_rightChild = NULL;
}

void Node::setData(int aData) {
	_data = aData;
}

void Node::setLeftChild(Node* lc) {
	_leftChild = lc;
}

void Node::setRightChild(Node* rc) {
	_rightChild = rc;
}

int Node::data() {
	return _data;
}

Node* Node::leftChild() {
	return _leftChild;
}

Node* Node::rightChild() {
	return _rightChild;
}

Tree::Tree() {
	_root = NULL;
}

bool Tree::isEmpty() {
	if(_root==NULL)
		return true;
	else
		return false;
}

int Tree::insert(int aData) {	
	if(_root)
		return insert(aData, _root);
	else {
		_root = new Node(aData);
		return 0;
	}
}

int Tree::insert(int aData, Node* pNode) {
	if(pNode->data() == aData)
		return -1;
	else if(pNode->data() > aData) {
		if(pNode->leftChild())
			return insert(aData, pNode->leftChild());
		else {
			Node* tempNode = new Node(aData);
			pNode->setLeftChild(tempNode);
			return 0;
		}
	}
	else {
		if(pNode->rightChild())
			return insert(aData, pNode->rightChild());
		else {
			Node* tempNode = new Node(aData);
			pNode->setRightChild(tempNode);
			return 0;
		}
	}
}


void Tree::postorder() {
	postorder(_root);
}

void Tree::postorder(Node* pNode) {
	if(pNode) {		
		//cout << "postorder()" << endl;
		postorder(pNode->leftChild());
		postorder(pNode->rightChild());
		cout << pNode->data() << '\n';
	}
}

int main()
{
	//freopen("input_haeseong.txt", "r", stdin);

	Tree* pBST = new Tree();
	int n;

	while(scanf("%d", &n) == 1) {
		pBST->insert(n);	
	}
	pBST->postorder();
	
	return 0;
}
