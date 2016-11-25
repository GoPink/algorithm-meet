/**************************************
	21 Nov. 2016
	Haeseong Jeon

	BST(Binary Search Tree) 
   
***************************************/
#include <iostream> // std::cin, cout
#include <stack>	// std::stack
using namespace std;

typedef class Node {
private:
	int  _data;
	bool _isVisited;
	class Node* _leftChild;
	class Node* _rightChild;
public:
	Node(int aData);
	void setData(int aData);
	void setVisited(bool aVisited);
	void setLeftChild(class Node* lc);
	void setRightChild(class Node* rc);
	int  data();
	bool isVisited();
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
	int remove(int aData);
	int remove(int aData, Node* pNode, Node* pParent);
	void visit(Node* pNode);
	void visitReset();
	void visitReset(Node* pNode);
	void preorder();
	void preorder(Node* pNode);
	void preorder_iter();
	void inorder();
	void inorder(Node* pNode);
	void inorder_iter();
	void postorder();
	void postorder(Node* pNode);
	void postorder_iter();
}Tree;

Node::Node(int aData) {
	_data = aData;
	_isVisited = false;
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

void Node::setVisited(bool aVisited) {
	_isVisited = aVisited;
}

int Node::data() {
	return _data;
}

bool Node::isVisited() {
	return _isVisited;
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

int Tree::remove(int aData) {
	if(!_root)
		return -1;
	else if(_root->data() == aData) {
		if(!_root->leftChild() && !_root->rightChild()) {
			// 자식노드 0
			delete(_root);
			_root = NULL;
			return 0;
		}
		else if(!_root->leftChild() || !_root->rightChild()) {
			// 자식노드 1
			Node* tempNode = _root;
			if(!_root->leftChild())
				_root = _root->rightChild();
			else
				_root = _root->leftChild();
			delete(tempNode);
			return 0;
		}
		else {
			// 자식노드 2
			Node* parentNode = NULL;
			Node* tempNode = _root->leftChild();
			while(tempNode->rightChild()) {
				parentNode = tempNode;
				tempNode = tempNode->rightChild();
			}
			_root->setData(tempNode->data());
			parentNode->setLeftChild(tempNode->rightChild());
			delete(tempNode);
			return 0;
		}
	}
	else if(_root->data() > aData) 
		return remove(aData, _root->leftChild(), _root);
	else if(_root->data() < aData)
		return remove(aData, _root->rightChild(), _root);
	else
		return -1;
}

int Tree::remove(int aData, Node* pNode, Node* pParent) {
	if(!pNode)
		return -1;
	else if(pNode->data() == aData) {
		if(!pNode->leftChild() && !pNode->rightChild()) {
			// no child node
			if(pParent->data() < aData)
				pParent->setRightChild(NULL);
			else
				pParent->setLeftChild(NULL);
			delete(pNode);
			return 0;
		}
		else if(!pNode->leftChild() || !pNode->rightChild()) {
			// only one child node
			if(!pNode->leftChild()) {
				pParent->setRightChild(pNode->rightChild());
				delete(pNode);
			}
			else {
				pParent->setLeftChild(pNode->leftChild());
				delete(pNode);
			}
			return 0;
		}
		else {
			// two child nodes
			Node* parentNode = NULL;
			Node* tempNode = pNode->leftChild();
			while(tempNode->rightChild()) {
				parentNode = tempNode;
				tempNode = tempNode->rightChild();
			}
			pNode->setData(tempNode->data());
			parentNode->setLeftChild(tempNode->rightChild());
			delete(tempNode);
			return 0;
		}
	}
	else if(pNode->data() > aData)
		return remove(aData, pNode->leftChild(), pNode);
	else if(pNode->data() < aData)
		return remove(aData, pNode->rightChild(), pNode);
	else
		return -1;
}

void Tree::visit(Node* pNode) {
	cout << pNode->data() << " ";
	pNode->setVisited(true);
}

void Tree::visitReset() {
	if(!_root)
		return;
	else
		visitReset(_root);
}

void Tree::visitReset(Node* pNode) {
	if(pNode) {
		pNode->setVisited(false);
		visitReset(pNode->leftChild());
		visitReset(pNode->rightChild());
	}
}

void Tree::preorder() {
	preorder(_root);
}

void Tree::preorder(Node* pNode) {
	if(pNode) {
		cout << pNode->data() << " ";
		preorder(pNode->leftChild());
		preorder(pNode->rightChild());
	}
}

void Tree::preorder_iter() {
	stack<Node*> s;
	if(!_root)
		return;
	else
		s.push(_root);

	Node* pNode;
	while(!s.empty()) {
		pNode = s.top();
		
		visit(pNode);
		s.pop();	

		if(pNode->rightChild() && !pNode->rightChild()->isVisited()) {
			s.push(pNode->rightChild());
		}
		if(pNode->leftChild() && !pNode->leftChild()->isVisited()) {
			s.push(pNode->leftChild());
		}
	}
	visitReset();
}

void Tree::inorder() {
	inorder(_root);
}

void Tree::inorder(Node* pNode) {
	if(pNode) {
		inorder(pNode->leftChild());
		cout << pNode->data() << " ";
		inorder(pNode->rightChild());
	}
}

void Tree::inorder_iter() {
	stack<Node*> s;
	if(!_root)
		return;
	else
		s.push(_root);

	Node* pNode;
	while(!s.empty()) {
		pNode = s.top();
		
		if(pNode->leftChild() && !pNode->leftChild()->isVisited()) {
			s.push(pNode->leftChild());
			continue;
		}
		visit(pNode);
		s.pop();
		if(pNode->rightChild() && !pNode->rightChild()->isVisited()) {
			s.push(pNode->rightChild());
		}
	}
	visitReset();
}

void Tree::postorder() {
	postorder(_root);
}

void Tree::postorder(Node* pNode) {
	if(pNode) {
		postorder(pNode->leftChild());
		postorder(pNode->rightChild());
		cout << pNode->data() << " ";
	}
}

void Tree::postorder_iter() {
	stack<Node*> s;
	if(!_root)
		return;
	else
		s.push(_root);

	Node* pNode;
	while(!s.empty()) {
		pNode = s.top();
		
		if(pNode->rightChild() && !pNode->rightChild()->isVisited()) {
			s.push(pNode->rightChild());
		}
		if(pNode->leftChild() && !pNode->leftChild()->isVisited()) {
			s.push(pNode->leftChild());
			continue;
		}
		visit(pNode);
		s.pop();
		
	}
	visitReset();
}

int main()
{
	char c;
	int n;
	Tree* pBST = new Tree();

	do {	
		cout << "BST(Binary Search Tree)" << endl;
		cout << "1. insert" << endl;
		cout << "2. remove" << endl;
		cout << "3. preorder (recursive)" << endl;
		cout << "4. inorder  (recursive)" << endl;
		cout << "5. postorder(recursive)" << endl;
		cout << "6. isEmpty" << endl;
        cout << "7. preorder (iterative)" << endl;
        cout << "8. inorder  (iterative)" << endl;
        cout << "9. postorder(iterative)" << endl;
		cout << "0. exit" << endl;
		cout << ">> ";
		cin >> c;

		switch(c) {
		case '1':
			cout << "input n for insert." << endl;
			cout << ">> ";
			cin >> n;
			if(pBST->insert(n)==0)
				cout << "insert successed. " << endl;
			else
				cout << "insert failed. " << endl;
			break;
		case '2':
			cout << "input n for remove." << endl;
			cout << ">> ";
			cin >> n;
            if(pBST->remove(n) == 0)
                cout << "remove successed." << endl;
            else
                cout << "remove failed. " << endl;
			break;
		case '3':
			pBST->preorder();
			cout << endl;
			break;
		case '4':
			pBST->inorder();
			cout << endl;
			break;
		case '5':
			pBST->postorder();
			cout << endl;
			break;
		case '6':
			if(pBST->isEmpty())
				cout << "tree is empty. " << endl;
			else
				cout << "tree is not empty. " << endl;
			break;
		case '7':
			pBST->preorder_iter();
			cout << endl;
			break;
		case '8':
			pBST->inorder_iter();
			cout << endl;
			break;
		case '9':
			pBST->postorder_iter();
			cout << endl;
			break;
		case '0':
			break;
		default:
			break;
		}
	}while(c!='0');
	
	return 0;
}
