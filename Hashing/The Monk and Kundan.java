import java.util.*;
class Main
{
	public static void main(String args[])
	{
		int t;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		String str = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		HashMap <Character,Integer> hm = new HashMap <Character,Integer> ();
		for (int i = 0; i < str.length(); i++)
		{
			hm.put(str.charAt(i),i);
		}
		sc.nextLine();
		while (t-- > 0)
		{
			String s = sc.nextLine();
			StringTokenizer st = new StringTokenizer(s);
			int ans = 0;
			int n = 0;
			while (st.hasMoreTokens())
			{
			    n++;
				String temp = st.nextToken();
				int len = temp.length();
				for (int i = 0; i < len; i++)
				{
					ans += (i + hm.get(temp.charAt(i)));
				}
			}
			System.out.println(n * ans);
		}
	}
}