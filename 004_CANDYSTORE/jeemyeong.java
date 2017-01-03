import java.util.Scanner;
import java.util.HashMap;
import java.util.Arrays;
public class jeemyeong {
	public static void main(String[] args) {
		String testSource = "2 8.00\n" +
							"700 7.00\n" +
							"199 2.00\n" +
							"3 8.00\n" +
							"700 7.00\n" +
							"299 3.00\n" +
							"499 5.00\n" +
							"0 0.00";

		// testRun(testSource);
		run();
	}

	static void run() {
		Scanner scan = new Scanner(System.in);
		while(true)
		{
			int time = Integer.parseInt(scan.next());
			float money = Float.parseFloat(scan.next());
			int cent = (int)(100 * money);
			if (time == 0 && cent ==0)
			{	
				break;
			}
			scan.nextLine();
			int[][] candyArray = new int[time][2];
			for (int i=0; i<time; i++) 
			{
                int calory = scan.nextInt();
                int centPrice = (int)(scan.nextDouble()*100 + .5);
				candyArray[i][0] = centPrice;
				candyArray[i][1] = calory;
			}
			System.out.println(candyEval(candyArray, cent));

		}
		scan.close();	
	}

	static void testRun(String testSource) {
		String[] lines = testSource.split("\n");
		int turn = 0;
		while(true)
		{
			String firstLine = lines[turn];
			if (firstLine.equals("0 0.00"))
			{
				break;
			}
			turn++;
			int time = Integer.parseInt(firstLine.split(" ")[0]);
			float money = Float.parseFloat(firstLine.split(" ")[1]);
			int cent = (int)(100 * money);
			int[][] candyArray = new int[time][2];
			for (int i=0; i<time; i++) 
			{
				int calory = Integer.parseInt(lines[turn].split(" ")[0]);
				float price = Float.parseFloat(lines[turn].split(" ")[1]);
				int centPrice = (int)(100 * price);
				candyArray[i][0] = centPrice;
				candyArray[i][1] = calory;
				turn++;
			}

			System.out.println(candyEval(candyArray, cent));
		}
	}

	static int candyEval(int[][] candyArray, int cent) {
		HashMap<Integer, Integer> calDic = new HashMap<Integer, Integer>();
		calDic.put(0,0);
		for (int i=1; i<=cent; i++) 
		{
			calDic.put(i,calDic.get(i-1));
			for (int[] e : candyArray)
			{
				int price = e[0];
				int calorie = e[1];
				if (i-price>=0 && calDic.get(i) < calDic.get(i-price)+calorie)
				{
					calDic.put(i, calDic.get(i-price)+calorie);
				}
			}
		}
		return calDic.get(cent);
	}
}
