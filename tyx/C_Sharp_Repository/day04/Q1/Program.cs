using System;

namespace Q1
{
    class ProgramMain
    {
        static void Main(string[] args)
        {
            double c, f;
            Console.WriteLine("请输入一个华氏温度：");
            f = Convert.ToDouble(Console.ReadLine());
            c = 5.0 / 9.0 * (f - 32);
            Console.WriteLine("对应的摄氏温度：" + c);
        }
    }
}
