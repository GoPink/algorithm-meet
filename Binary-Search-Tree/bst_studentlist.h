// 학생정보 구조체 
typedef struct student *student_pointer; 
typedef struct student { 
int num; 
int grade; 
char name[20]; 
char major[20]; 
student_pointer left; 
student_pointer right; 
} student_node; 

student_pointer root;// 학생리스트(BST) 루트노드
int i=0;


// BST에 학생정보 자료 삭제 
void bst_delete(int num){
	
		student_node *p, *child, *succ, *succ_p, *t;
		p = NULL; //t는 p의 부모 
		t = root; 
		//num을 갖는 t 탐색 
		while( t!=NULL && t->num != num){
			p=t ;
			t= (num < t->num )? t->left : t->right;
		} 
		
		if(t==NULL){ //탐색트리에 없는 num 
			printf("없는 학생입니다.");
			return; 
		}
		
		//case 0, 1, 2
		if(t->left==NULL&&t->right==NULL){
			if( p != NULL ) {
				if(p->left==t) p->left=NULL;
				else p->right = NULL;
			} else
				root = NULL; //부모노드가 NULL이면 루트를 삭제 
		}
		
		else if (t->left==NULL || t->right==NULL){
			child = (t->left != NULL)? t->left : t->right;
			
			if(p!=NULL){ //t가 root가 아니라는 뜻 
				if(p->left==t) p->left = child;
				else p->right = child;
			}
			else root = child;
		}
		
		else {
			//t의 오른쪽 트리에서 가장 작은 값을 찾는다. 
			succ_p=t;
			succ=t->right;
			
			//후계자를 찾아서 가장 왼쪽으로 이동
			while(succ->left!=NULL){
				succ_p=succ;
				succ=succ->left;
			}
			
			//후계자의 부모와 자식을 연결 
			//1. null이면 링크삭제 2.right자식있으면 연결 
			if(succ_p->left==succ) succ_p->left = succ->right;
			else succ_p->right = succ->right;//오른편의 노드의 가장 작은 값이 없는 경우, 자신 
		
			t->num = succ->num; //왜 이해가 안가지  
			t = succ;
		}
		
		free(t);
	
}

// BST에 학생정보 자료 삽입 
void bst_insert(int num, int grade, char *name, char *major){
	
	student_pointer cur = root;
	
	if( root == NULL) {
		student_pointer newNode = (student_node*)malloc(sizeof(student_node));
		newNode->num = num;
		newNode->grade = grade;
		strcpy(newNode->name,name);
		strcpy(newNode->major,major);
		newNode->left = NULL;
		newNode->right = NULL;	
		
		root = newNode;
	} else {
		
		while(1) {	
		
			if(cur->num > num) { // insert값이 더 작다. 
				//printf("\ncur->key : %d > key : %d",cur->key,key);		
				if(cur->left==NULL){ //left가 비어있다.  
										
					student_pointer newNode = (student_node*)malloc(sizeof(student_node));
					newNode->num = num;
					newNode->grade = grade;
					strcpy(newNode->name,name);
					strcpy(newNode->major,major);
					newNode->left = NULL;
					newNode->right = NULL;				
					//삽입 
					cur->left = newNode; 
					break;
					 
				} else { //left에 뭔가 차있다-반복 
					 cur = cur->left;
				}
			
			} else { //insert값이 더 크다.	
				//printf("\ncur->key : %d < key : %d",cur->key,key);			
				if(cur->right==NULL){ //left가 비어있다.  
					
					student_pointer newNode = (student_node*)malloc(sizeof(student_node));
					newNode->num = num;
					newNode->grade = grade;
					strcpy(newNode->name,name);
					strcpy(newNode->major,major);
					newNode->left = NULL;
					newNode->right = NULL;									
					//삽입 
					cur->right = newNode; 
					break;
					 
				} else { //right에 뭔가 차있다-반복				  
					 cur = cur->right;
				}  			
			} 		
		}	
			
	}
	return;

}

// BST에서 학번(키)이 num인 학생정보를 검색, 해당 학생정보의 노드 주소를 반환 
student_pointer bst_search(int num){
	
	student_pointer cur = root;
	while(cur){
		if( cur->num == num ){
			return cur;
		} else if ( cur->num < num ){
			cur= cur->right;			
		} else {
			cur = cur->left;
		}
	}	
	
	
} 


// BST의 자료들을 inorder로 출력 
void bst_show_inorder(student_pointer ptr){	
		
	if(ptr){
		bst_show_inorder(ptr->left);
		printf(" \n %d ... %s",i,ptr->name);
		i++;
		bst_show_inorder(ptr->right);	
	}	
}

void test (){
	printf("\n %s",root->name);
	printf("\n %s",root->major);
}


// bst의 노드수를 계산 
int bst_node_count(student_pointer ptr){
	
	int i=0;
	if(ptr != NULL) i=1+bst_node_count(ptr->left)+bst_node_count(ptr->right);
	
	return i;
			
}




