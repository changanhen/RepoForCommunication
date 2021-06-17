using System;

namespace H3Q3
{
    class Program
    {
        static void Main(string[] args)
        {
            Arcsin arcsin = new Arcsin();
            Console.WriteLine("*****arcsinx按级数展开计算近似值*****\n请输入x的值：");
            double x = Convert.ToDouble(Console.ReadLine());
            double arcsinx = 0;
            for (int n = 0; Math.Abs(arcsin.Series(n, x)) > 1e-14; n++)
            {
                arcsinx = arcsinx + arcsin.Series(n, x);
            }
            Console.WriteLine("arcsin({0}) = {1}", x, arcsinx);
        }
    }
    class Arcsin
    {
        public double Series(int n, double x)
        {
            if (n == 0)
                return x;
            else
                return Factorial(2 * n) * Math.Pow(x, 2 * n + 1) / (Math.Pow(2, 2 * n) * Math.Pow(Factorial(n), 2) * (2 * n + 1));
        }
        public double Factorial(int n)
        {
            if (n == 1)
                return 1;
            return n * Factorial(n - 1);
        }
    }
}
