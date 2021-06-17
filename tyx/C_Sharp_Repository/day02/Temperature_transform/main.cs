using System;
class My
{
    static int Main()
    {
        double c, f;
        Console.WriteLine("请输入一个华氏温度：");
        f = Convert.ToDouble(Console.ReadLine());
        c = 5 / 9 * (f - 32);
        Console.WriteLine("对应于华氏温度" + f + "的摄氏温度为" + c);
        return 0;
    }
}