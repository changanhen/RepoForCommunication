using System;

namespace Q3
{
    class Program
    {
        static void Main(string[] args)
        {
            Function function = new Function();
            Console.WriteLine("请输入三个整数：");
            double integer1 = Convert.ToDouble(Console.ReadLine());
            double integer2 = Convert.ToDouble(Console.ReadLine());
            double integer3 = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("这三个数的和是：{0}\n这三个数的平均值是：{1}\n平均值四舍五入后的值是：{2}", function.Sum(integer1, integer2, integer3), function.Avg(integer1, integer2, integer3), function.Signif(integer1, integer2, integer3));
        }
    }
    class Function
    {
        public double Avg(double integer1, double integer2, double integer3)
        {
            return this.Sum(integer1, integer2, integer3) / 3;
        }
        public double Sum(double integer1, double integer2, double integer3)
        {
            return integer1 + integer2 + integer3;
        }
        public int Signif(double integer1, double integer2, double integer3)
        {
            return Convert.ToInt32(this.Avg(integer1, integer2, integer3));
        }
    }
}
