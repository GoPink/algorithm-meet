// �л����� ����ü 
typedef struct student *student_pointer; 
typedef struct student { 
int num; 
int grade; 
char name[20]; 
char major[20]; 
student_pointer left; 
student_pointer right; 
} student_node; 

student_pointer root;// �л�����Ʈ(BST) ��Ʈ���
int i=0;


// BST�� �л����� �ڷ� ���� 
void bst_delete(int num){
	
		student_node *p, *child, *succ, *succ_p, *t;
		p = NULL; //t�� p�� �θ� 
		t = root; 
		//num�� ���� t Ž�� 
		while( t!=NULL && t->num != num){
			p=t ;
			t= (num < t->num )? t->left : t->right;
		} 
		
		if(t==NULL){ //Ž��Ʈ���� ���� num 
			printf("���� �л��Դϴ�.");
			return; 
		}
		
		//case 0, 1, 2
		if(t->left==NULL&&t->right==NULL){
			if( p != NULL ) {
				if(p->left==t) p->left=NULL;
				else p->right = NULL;
			} else
				root = NULL; //�θ��尡 NULL�̸� ��Ʈ�� ���� 
		}
		
		else if (t->left==NULL || t->right==NULL){
			child = (t->left != NULL)? t->left : t->right;
			
			if(p!=NULL){ //t�� root�� �ƴ϶�� �� 
				if(p->left==t) p->left = child;
				else p->right = child;
			}
			else root = child;
		}
		
		else {
			//t�� ������ Ʈ������ ���� ���� ���� ã�´�. 
			succ_p=t;
			succ=t->right;
			
			//�İ��ڸ� ã�Ƽ� ���� �������� �̵�
			while(succ->left!=NULL){
				succ_p=succ;
				succ=succ->left;
			}
			
			//�İ����� �θ�� �ڽ��� ���� 
			//1. null�̸� ��ũ���� 2.right�ڽ������� ���� 
			if(succ_p->left==succ) succ_p->left = succ->right;
			else succ_p->right = succ->right;//�������� ����� ���� ���� ���� ���� ���, �ڽ� 
		
			t->num = succ->num; //�� ���ذ� �Ȱ���  
			t = succ;
		}
		
		free(t);
	
}

// BST�� �л����� �ڷ� ���� 
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
		
			if(cur->num > num) { // insert���� �� �۴�. 
				//printf("\ncur->key : %d > key : %d",cur->key,key);		
				if(cur->left==NULL){ //left�� ����ִ�.  
										
					student_pointer newNode = (student_node*)malloc(sizeof(student_node));
					newNode->num = num;
					newNode->grade = grade;
					strcpy(newNode->name,name);
					strcpy(newNode->major,major);
					newNode->left = NULL;
					newNode->right = NULL;				
					//���� 
					cur->left = newNode; 
					break;
					 
				} else { //left�� ���� ���ִ�-�ݺ� 
					 cur = cur->left;
				}
			
			} else { //insert���� �� ũ��.	
				//printf("\ncur->key : %d < key : %d",cur->key,key);			
				if(cur->right==NULL){ //left�� ����ִ�.  
					
					student_pointer newNode = (student_node*)malloc(sizeof(student_node));
					newNode->num = num;
					newNode->grade = grade;
					strcpy(newNode->name,name);
					strcpy(newNode->major,major);
					newNode->left = NULL;
					newNode->right = NULL;									
					//���� 
					cur->right = newNode; 
					break;
					 
				} else { //right�� ���� ���ִ�-�ݺ�				  
					 cur = cur->right;
				}  			
			} 		
		}	
			
	}
	return;

}

// BST���� �й�(Ű)�� num�� �л������� �˻�, �ش� �л������� ��� �ּҸ� ��ȯ 
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


// BST�� �ڷ���� inorder�� ��� 
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


// bst�� ������ ��� 
int bst_node_count(student_pointer ptr){
	
	int i=0;
	if(ptr != NULL) i=1+bst_node_count(ptr->left)+bst_node_count(ptr->right);
	
	return i;
			
}




