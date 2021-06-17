using System;

namespace Test
{
    class Program
    {
        static void Main()
        {
            double x, y;
            x = Convert.ToDouble(Console.ReadLine());
            y = Math.Asin(x * x) / (1 - Math.Acos(x));
            Console.WriteLine(y);
        }
    }
}
