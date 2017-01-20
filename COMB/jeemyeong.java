import java.util.*;
public class jeemyeong {
	public static void main(String[] args) 
	{
		String testSource = "5 6\n" +
							"1 1 1 2\n" +
							"2 2 3\n" +
							"2 3 4\n" +
							"1 -1 -1 3\n" +
							"2 0 0\n" +
							"2 3 -1";

		// testRun(testSource);
		run();
	}

	static void run() {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int q = scan.nextInt();
		int[][] combMap = new int[2*n+1][2*n+1];
		for (int i=0; i<2*n+1; i++) 
		{
			for (int j=0; j<2*n+1; j++) 
			{
				combMap[i][j] = 0;
			}
		}
		for (int i=0; i<q; i++) 
		{
			int typeOfOperation = scan.nextInt();
			if (typeOfOperation==1)
			{
				int x = scan.nextInt();
				int y = scan.nextInt();
				int r = scan.nextInt();
				plusValue(x,y,r,combMap,n);
			}
			if (typeOfOperation==2)
			{
				int x = scan.nextInt();
				int y = scan.nextInt();
				System.out.println(findValue(x,y,combMap,n));
			}
		}		
		scan.close();	
	}

	static void testRun(String testSource) 
	{
		String[] lines = testSource.split("\n");
		int turn = 0;
		String[] firstLine = lines[turn++].split(" ");
		int n = Integer.parseInt(firstLine[0]);
		int q = Integer.parseInt(firstLine[1]);
		int[][] combMap = new int[2*n+1][2*n+1];
		for (int i=0; i<2*n+1; i++) 
		{
			for (int j=0; j<2*n+1; j++) 
			{
				combMap[i][j] = 0;
			}
		}
		for (int i=0; i<q; i++) 
		{
			String[] operation = lines[turn++].split(" ");
			int typeOfOperation = Integer.parseInt(operation[0]);
			if (typeOfOperation==1)
			{
				int x = Integer.parseInt(operation[1]);
				int y = Integer.parseInt(operation[2]);
				int r = Integer.parseInt(operation[3]);
				plusValue(x,y,r,combMap,n);
			}
			if (typeOfOperation==2)
			{
				int x = Integer.parseInt(operation[1]);
				int y = Integer.parseInt(operation[2]);
				System.out.println(findValue(x,y,combMap,n));
			}
		}
	}

	static void plusValue(int x, int y, int r, int[][] combMap, int n)
	{
		for (int i=0; i<2*r+1; i++) 
		{
			for (int j=0; j<2*r+1; j++) 
			{
				if ((i-j<r+1) && (j-i<r+1))
				{
					combMap[n+y-r+i][n+x-r+j]++;
				}
			}
		}
	}
	static int findValue(int x, int y, int[][] combMap, int n)
	{
		return combMap[n+y][n+x];
	}

	static void pprint(int[][] combMap)
	{
		for (int[] i:combMap) 
		{
			for (int j:i)
			{
				System.out.print(j);
			}	
			System.out.println();
		}
	}
}
