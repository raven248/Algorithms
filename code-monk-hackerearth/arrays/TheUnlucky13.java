package arrays;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class TheUnlucky13 {
    static final int MOD = 1000000009;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bf.readLine());
        Map<Integer, Integer> cache = new HashMap<>();
        int n;

        while(t-- > 0) {
            n = Integer.parseInt(bf.readLine());
            System.out.println(countStrings(n, cache));
        }
    }

    private static int countStrings(int n, Map<Integer, Integer> cache) {
        if(cache.containsKey(n))
            return cache.get(n);

        if(n == 0)
            return 1;

        long[][] A = {{9, 1}, {8, 1}};

        A = pow(A, n);
        int res = (int)((A[0][0]+A[0][1])%MOD);

        cache.put(n, res);
        return res;
    }

    private static long[][] multiply(long[][] a, long[][] b) {
        long[][] c = new long[2][2];

        c[0][0] = ((a[0][0]*b[0][0])%MOD + (a[0][1]*b[1][0])%MOD)%MOD;
        c[0][1] = ((a[0][0]*b[0][1])%MOD + (a[0][1]*b[1][1])%MOD)%MOD;
        c[1][0] = ((a[1][0]*b[0][0])%MOD + (a[1][1]*b[1][0])%MOD)%MOD;
        c[1][1] = ((a[1][0]*b[0][1])%MOD + (a[1][1]*b[1][1])%MOD)%MOD;

        return c;
    }

    private static long[][] pow(long[][] a, int n) {
        long[][] res = new long[2][2];

        if((n&1) == 1) {
            res[0][0] = a[0][0];
            res[1][1] = a[1][1];
            res[0][1] = a[0][1];
            res[1][0] = a[1][0];
        }
        else {
            res[0][0] = 1;
            res[1][1] = 0;
            res[0][1] = 0;
            res[1][0] = 1;
        }

        n = (n >> 1);
        while(n > 0) {
            a = multiply(a, a);
            if((n&1) == 1)
                res = multiply(res, a);
            n = (n >> 1);
        }

        return res;
    }
}
