using System;

namespace adder
{
    class My
    {
        static void Main(string[] args)
        {
            double a, b, c;
            Console.WriteLine("Please input two numbers:");
            a = Convert.ToDouble(Console.ReadLine());
            b = Convert.ToDouble(Console.ReadLine());
            c = a + b;
            //Console.WriteLine(a + "+" + b + "=" + c);//速度快
            Console.WriteLine("{0}+{1}={2}", a, b, c);//速度慢
        }
    }
}
