#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//�迭 �Է� �ޱ� 
	int n;
	scanf("%d",&n);
	int arr[n];
	
	int k;
	for(k=1; k<=n; k++)	scanf("%d",&arr[k]);
	
	/*
	for(k=1; k<=n; k++){
		printf("%d ",arr[k]);
	}
	 */
	 
	//�Ӹ���� Ȯ�� Ƚ��
	int m;
	scanf("%d",&m);
	
	int res[m+1]; //������� ���� �迭  
	for(k=1; k<=m; k++)
	{
		int h,t;		
		scanf("%d",&h);
		scanf("%d",&t);
		int length = (t-h)/2+1;
		
		//���ڿ� Ȯ��  
		int i;
		for(i=1; i<=length; i++)
		{
			if(arr[h] != arr[t]) {
				res[k]=0;
				//printf("oh\n");
				break;	
			
			} else if( i==length ) {
				res[k]=1;
				//printf("end\n");
				break;			
			}
			h++;
			t--;			
		}
		
		
					
	}
	for(k=1;k<=m;k++) printf("%d\n",res[k]);	
	  
	return 0;
}
