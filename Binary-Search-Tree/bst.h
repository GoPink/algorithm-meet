// Binary search tree node 
typedef struct tree_node *tree_pointer; 
typedef struct tree_node { 
	int key; 
	char data; 
	tree_pointer left; 
	tree_pointer right; 
} tree_node; 

tree_pointer root;   // BST의 root를 가리키는 포인터 (전역변수)

// 트리에 (key, data) 자료 삽입 
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
		
			if(cur->key > key) { // insert값이 더 작다. 
				//printf("\ncur->key : %d > key : %d",cur->key,key);		
				if(cur->left==NULL){ //left가 비어있다.  
										
					tree_pointer new = (tree_node*)malloc(sizeof(tree_node));
					new->key = key;
					new->data = data;	
					new->left = NULL;
					new->right = NULL;				
					//삽입 
					cur->left = new; 
					break;
					 
				} else { //left에 뭔가 차있다-반복 
					 cur = cur->left;
				}
			
			} else { //insert값이 더 크다.	
				//printf("\ncur->key : %d < key : %d",cur->key,key);			
				if(cur->right==NULL){ //left가 비어있다.  
					
					tree_pointer new = (tree_node*)malloc(sizeof(tree_node));
					new->key = key;
					new->data = data;
					new->left = NULL;
					new->right = NULL;					
					//삽입 
					cur->right = new; 
					break;
					 
				} else { //left에 뭔가 차있다-반복				  
					 cur = cur->right;
				}  			
			} 		
		}	
			
	}
	return;
}

// 트리에서 키값이 key인 자료를 검색, data를 반환 
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


// 트리의 자료들을 inorder로 출력 
void bst_show_inorder(tree_pointer ptr){
	if(ptr){
		if(ptr->left) bst_show_inorder(ptr->left);
		printf(" %d %c \n",ptr->key,ptr->data);
		if(ptr->right) bst_show_inorder(ptr->right);
	}
}


