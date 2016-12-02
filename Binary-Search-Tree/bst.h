// Binary search tree node 
typedef struct tree_node *tree_pointer; 
typedef struct tree_node { 
	int key; 
	char data; 
	tree_pointer left; 
	tree_pointer right; 
} tree_node; 

tree_pointer root;   // BST�� root�� ����Ű�� ������ (��������)

// Ʈ���� (key, data) �ڷ� ���� 
void bst_insert(int key, char data){
	
	tree_pointer cur=root;
	
	if(root==NULL){
		
		tree_pointer new = (tree_node*)malloc(sizeof(tree_node));
		new->key = key;
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		//root insert
		root = new;
	
	
	} else {	
		
		
		while(1) {	
		
			if(cur->key > key) { // insert���� �� �۴�. 
				//printf("\ncur->key : %d > key : %d",cur->key,key);		
				if(cur->left==NULL){ //left�� ����ִ�.  
										
					tree_pointer new = (tree_node*)malloc(sizeof(tree_node));
					new->key = key;
					new->data = data;	
					new->left = NULL;
					new->right = NULL;				
					//���� 
					cur->left = new; 
					break;
					 
				} else { //left�� ���� ���ִ�-�ݺ� 
					 cur = cur->left;
				}
			
			} else { //insert���� �� ũ��.	
				//printf("\ncur->key : %d < key : %d",cur->key,key);			
				if(cur->right==NULL){ //left�� ����ִ�.  
					
					tree_pointer new = (tree_node*)malloc(sizeof(tree_node));
					new->key = key;
					new->data = data;
					new->left = NULL;
					new->right = NULL;					
					//���� 
					cur->right = new; 
					break;
					 
				} else { //left�� ���� ���ִ�-�ݺ�				  
					 cur = cur->right;
				}  			
			} 		
		}	
			
	}
	return;
}

// Ʈ������ Ű���� key�� �ڷḦ �˻�, data�� ��ȯ 
char bst_search(int key){
	
	tree_pointer cur;
	cur = root;
	while(1){
		if(cur->key==key) {			
			return(cur->data);
			
		} else {
			
			if(key<cur->key) cur=cur->left;
			else cur = cur->right;			
		}
	}
	
}


// Ʈ���� �ڷ���� inorder�� ��� 
void bst_show_inorder(tree_pointer ptr){
	if(ptr){
		if(ptr->left) bst_show_inorder(ptr->left);
		printf(" %d %c \n",ptr->key,ptr->data);
		if(ptr->right) bst_show_inorder(ptr->right);
	}
}


