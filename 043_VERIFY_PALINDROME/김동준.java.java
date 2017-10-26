package verify_palindrome_04;

import java.util.Scanner;

/**
 * Created by dongjunekim on 2017-10-26.
 */
public class Main {
    public Main() {
        Scanner s = new Scanner(System.in);
        String str = s.next();
        System.out.println(solution(str));
    }

    public static void main(String args[]) {
        new Main();
    }

    public int solution(String s) {
        char sArr[] = new char[s.length()];
        int cnt = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            sArr[cnt++] = s.charAt(i);
        }

        for (int i = 0; i < sArr.length; i++) {
            if (sArr[i] != s.charAt(i)) {
                return 0;
            }
        }
        return 1;
    }

}
