import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        String []files = new String[number];
        String answer = "";
        
        for(int i = 0; i < number; i++) {
            files[i] = scan.next();
        }
        
        answer = files[0];
        
        for(int i = 1; i < number; i++) {
            for(int j = 0; j < answer.length(); j++) {
                if(answer.charAt(j) != files[i].charAt(j)) {
                    answer = answer.substring(0,j) + "?" + answer.substring(j+1,answer.length());
                }
            }
        }
        System.out.println(answer);
    }
}