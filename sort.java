import java.io.*;
import java.util.*;
class CmpString implements Comparator{
    public int compare(Object a, Object b)
    {
        String as = (String)a;
        String bs = (String)b;
        return calc_score(as) - calc_score(bs);
    }

    int calc_score(String s)
    {
        int score = 0;
        for(int i = 0; i < s.length(); i++)
            for(int j = i; j < s.length(); j++)
                if(s.charAt(i) > s.charAt(j))
                    score++;
        return score;
    }
}
public class sort{
    public static void main(String args[])
    {
        int i;
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), m = cin.nextInt();
        String[] a = new String[m];
        for(i = 0; i < m; i++)
            a[i] = cin.next();
        Arrays.sort(a, new CmpString());
        for(i = 0; i < m; i++)
            System.out.println(a[i]);
    }
}
