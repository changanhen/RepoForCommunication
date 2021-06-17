using System;

namespace H3Q4
{
    class Program
    {
        static void Main(string[] args)
        {
            double x = 1.5;
            while (2 * Math.Pow(x, 3) - 4 * Math.Pow(x, 2) + 3 * x - 6 != 0)
                x = x - Program.F(x);
            Console.WriteLine("方程2x^3-4x^2+3x-6=0在1.5附近的根是：" + x);
        }
        static double F(double x)
        {
            return (2 * Math.Pow(x, 3) - 4 * Math.Pow(x, 2) + 3 * x - 6) / (6 * Math.Pow(x, 2) - 8 * x + 3);
        }
    }
}
