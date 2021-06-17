using System;

namespace H3Q5
{
    class Program
    {
        static void Main(string[] args)
        {
            int a, n, sum = 0;
            Console.WriteLine("请输入a, n的值：");
            a = Convert.ToInt32(Console.ReadLine());
            n = Convert.ToInt32(Console.ReadLine());
            while (n != 0)
            {
                sum = sum + Program.an(a, n);
                n--;
            }
            Console.WriteLine("和是：" + sum);
        }
        static int an(int a, int n)
        {
            if (n == 0)
                return 0;
            return a * (int)Math.Pow(10, n - 1) + an(a, n - 1);
        }
    }
}
