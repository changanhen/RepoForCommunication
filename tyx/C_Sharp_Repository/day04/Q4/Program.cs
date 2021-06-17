using System;

namespace Q4
{
    class Program
    {
        static void Main(string[] args)
        {
            Number num = new Number();
            Console.WriteLine("请输入一个100以下的数：");
            int getyuan = Convert.ToInt32(Console.ReadLine());
            num.Getyuan(getyuan);
            Int32[] array = { 50, 20, 10, 5, 1 };
            for (int i = 0; i < 5; i++)
            {
                int j = num.MoneyNumber(array[i]);
                Console.WriteLine("面值{0}的纸币张数为：{1}", array[i], j);
            }
        }
    }
    class Number
    {
        private int yuan;
        public void Getyuan(int getyuan)
        {
            yuan = getyuan;
        }
        public int MoneyNumber(int money)
        {
            int number = 0;
            while (yuan - money >= 0)
            {
                yuan -= money;
                number++;
            }
            return number;
        }
    }
}
