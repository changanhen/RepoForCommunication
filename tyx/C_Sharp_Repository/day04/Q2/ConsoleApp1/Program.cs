using System;

namespace Q2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入x的值：");
            double x = Convert.ToDouble(Console.ReadLine());
            double y = Math.Sin(Math.Pow(x, 2)) / (1 - Math.Cos(x));
            Console.WriteLine("y({0})的值是：{1}", x, y);
        }
    }
}
