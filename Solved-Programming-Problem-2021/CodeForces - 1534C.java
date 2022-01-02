import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int test = sc.nextInt();
        while (test-- > 0) {
            int n = sc.nextInt();
            int [] a = new int[n];
            int [] b = new int[n];
            for (int i = 0; i < n; i++) 
                a[i] = sc.nextInt() - 1;
            for (int i = 0; i < n; i++) 
                b[i] = sc.nextInt() - 1;
            int cnt = 0;
            int [] mp = new int[n];
            for (int i = 0; i < n; i++) 
                mp[a[i]] = b[i];
            boolean [] vis = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (vis[i]) continue;
                int cur = i;
                while (!vis[cur]) {
                    vis[cur] = true;
                    cur = mp[cur];
                }
                cnt++;
            }
            long ans = powmod(2, cnt);

            out.println(ans);
        }
        out.close();
    }

    static long MOD = 1000000007;

    static long powmod(long a, long b) {
        long ans = 1;
        while(b > 0) {
            if(b % 2 == 1) {
                ans = (ans * a) % MOD;
            }
            b >>= 1;
            a = (a * a) % MOD;
        }

        return ans;
    }

    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;
 
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
 
 
    }
}