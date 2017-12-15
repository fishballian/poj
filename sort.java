import java.util.Arrays;
import java.util.Comparator;
class CmpString implements Comparator{
    public int compare(Object a, Object b)
    {
        String as = (String)a;
        String bs = (String)b;
        return as.length() - bs.length(); 
    }
}
public class sort{
    public static void main(String args[])
    {
        String[] a = {"dfe", "aaa", "defg", "dd"};
        Arrays.sort(a, new CmpString());
        for(int i = 0; i < 4; i++)
            System.out.println(a[i]);
    }
}
