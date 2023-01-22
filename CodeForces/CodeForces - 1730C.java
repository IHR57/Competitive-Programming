import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        FastScanner fastScanner = new FastScanner();
        int test = fastScanner.nextInt();
        while (--test >= 0) {
            String str = fastScanner.next();
            char[] charArray = str.toCharArray();

            int lastVis = -1;
            for (int i = 0; i <= 9; i++) {
                int prev = lastVis;
                for (int j = lastVis + 1; j < charArray.length; j++) {
                    if (charArray[j] - '0' == i) {
                        lastVis = j;
                    }
                }
                if (prev != lastVis) {
                    for (int j = prev + 1; j < lastVis; j++) {
                        if (charArray[j] - '0' != i) {
                            charArray[j] = Character.forDigit(Math.min((charArray[j] - '0') + 1, 9), 10);
                        }
                    }
                }
            }

            Arrays.sort(charArray);

            for (Character ch : charArray) {
                System.out.print(ch);
            }

            System.out.println();
        }
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}