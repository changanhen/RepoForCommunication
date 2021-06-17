using System;
class My
{
    static void num(int n)
    {
        try
        {
            if (n < 0 || n >= 13)
                throw new Exception("n必须在1~13之间");

            int u = 1;
            for (int i = 1; i <= n; i++)
            {
                u = u * i;
                Console.WriteLine(i + "阶乘的结果为" + u);
            }
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }

    }
    static void Main()
    {
        Console.WriteLine("请输入n!中的n值：");
        int n = Convert.ToInt32(Console.ReadLine());
        num(n);
    }
}
