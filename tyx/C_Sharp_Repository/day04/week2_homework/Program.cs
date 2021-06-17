using System;

namespace q1
{
    class Program
    {
        static void Main(string[] args)
        {
            double f, c;
            Console.WriteLine("请输入一个华氏温度：");
            f = Convert.ToDouble(Console.ReadLine());
            t = 5 * (f - 32) / 9;
            Console.WriteLine("对应的摄氏温度是：" + t);
        }
    }
}
