#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 51
#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;
Element stack[MAX_SIZE];
int top = -1;


//)(() = NO
void push (Element e){
	stack[++top] = e;
}

Element peek(){
	return stack[top];
}

Element pop(){	
	return stack[top--]; 
}


int main(int argc, char *argv[]) {
		
	int n;
	scanf("%d",&n);
	fflush(stdin);
	
	int i;
	for( i=0; i<n; i++){
		
		//scanf("%[^\n]\n",s); 
		//fgets(tmp,sizeof(tmp),stdin);
		top=-1;
		char tmp[51];				
		scanf("%s", tmp);		
		fflush(stdin);		
		
		int j = 0;
		while(tmp[j]=='(' || tmp[j]==')'){			
			
						
			if(j==0 || top==-1 ){
				push(tmp[j]);
				
			}  else if ( peek()=='(' && tmp[j]==')' ) {
				pop();
			
			}else {
				push(tmp[j]);
			
			}
			j++;			
		}
		
		if(top!=-1){
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	
	return 0;	
}








