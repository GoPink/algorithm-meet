package cycle_word_042;

import java.util.*;
import java.util.Scanner;

/**
 * Created by dongjunekim on 2017-10-26.
 */
public class Main {

    public Main() {
        Scanner s = new Scanner(System.in);
        String input[] = new String[50];
        HashSet<String> set = new HashSet<>();
        int n = s.nextInt();
        for (int i = 0; i < n; i++) {
            input[i] = s.next();
        }
        set.add(input[0]);
        for (int i = 1; i < n; i++) {
            isRotation(set, input[i]);
        }
        System.out.println(set.size());
    }


    public static void main(String args[]) {
        new Main();
    }

    public void isRotation(HashSet<String> set, String compareWord) {
        StringBuilder sb;
        int len = compareWord.length();
        for (String str : set) {
            sb = new StringBuilder(str);
            for (int i = 0; i < len; i++) {
                if (compareWord.equals(sb.toString())) {
                    return;
                } else {
                    sb = sb.append(sb.charAt(0)).deleteCharAt(0);
                }
            }
        }
        set.add(compareWord);
    }
}
