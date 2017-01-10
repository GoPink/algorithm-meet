package bj1260_dfsAndBfs;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class  Bj1260_dfsAndBfs {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
/*
4 5 1
1 2
1 3
1 4
2 4
3 4

1 2 4 3
1 2 3 4
*/ 		 
		
		Scanner sc = new Scanner(System.in);
		int v = sc.nextInt(); int e = sc.nextInt(); 
		int s = sc.nextInt();		
		sc.close();
		
		int matrix[][] = new int[v+1][v+1];
		for( int i=1; i<=e; i++)
		{
			int x = sc.nextInt(); int y = sc.nextInt();
			matrix[x][y]=1;
			matrix[y][x]=1;
		}
		
		int check[] = new int[matrix[0].length];
		//잘받았나 체크 
		/*for(int i=0; i<=v; i++)
		{
			for(int j=0; j<=v; j++)
			{
				System.out.print(matrix[i][j]+" ");
			}
			System.out.println(" ");
		}*/
		
		DFS(matrix, check, s);
		System.out.println("");
		check = new int[matrix[0].length];
		BFS(matrix, check, s);
	}
	
	
	public static void DFS( int m[][],int check[], int p){		
		
		System.out.print(p+" ");
		check[p]=1;
		
		for( int i=1; i<m[0].length; i++ )
		{
			if(m[p][i]==1 && check[i]==0){
				DFS(m, check, i);
			}
		}
		
	}
	public static void BFS( int m[][],int check[], int p){		
		
		Queue<Integer> q = new LinkedList<Integer>(); //스택이랑 다르네
		
		check[p]=1;
		q.add(p);
		
		while(!q.isEmpty())
		{
			int node = q.poll();
			System.out.print(node+" ");
			for( int i=0; i<m[0].length; i++)
			{
				if(m[node][i]==1 && check[i]==0){
					check[i]=1;
					q.add(i);
				}
			}
			
		}
		
		
		
		
		
	}
}

