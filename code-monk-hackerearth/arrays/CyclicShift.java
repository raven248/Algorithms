package arrays;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CyclicShift {
    public static int compare(final char[] str, int i, int j) {
        int len = str.length;

        while(len > 0) {
            if(str[i] > str[j])
                return 1;
            else if(str[i] < str[j])
                return -1;

            i = (i+1)%str.length;
            j = (j+1)%str.length;
            len--;
        }

        return 0;
    }

    public static long getShifts(final char[] str, int k) {
        int maxIndex = 0;
        int period = str.length;

        for(int i=1;i<str.length;i++) {
            int compRes = compare(str, maxIndex, i);

            if(compRes < 0)
                maxIndex = i;
            else if(compRes == 0) {
                period = i-maxIndex;
                break;
            }
        }

        return maxIndex+(long)(k-1)*period;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        int k;
        String s;

        while(t > 0) {
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            k = Integer.parseInt(st.nextToken());
            s = br.readLine();

            System.out.println(getShifts(s.toCharArray(), k));
            t--;
        }
    }
}
