using System;

namespace H5Q4
{
    class Program
    { 
        static int Main(string[] args)
        {
            double lwr, upr, err = 1e-14, tmp;
            Console.WriteLine("This ia a program for extratcing the solution of x*e^x-1=0");
            do
            {
                Console.WriteLine("Please enter the interval");
                lwr = Convert.ToDouble(Console.ReadLine());
                upr = Convert.ToDouble(Console.ReadLine());
            } while (F(lwr) * F(upr) > 0);
            do
            {
                tmp = lwr - (lwr - upr) / (F(lwr) - F(upr)) * F(lwr);
                if (F(tmp) * F(lwr) > 0)
                    lwr = tmp;
                if (F(tmp) * F(upr) > 0)
                    upr = tmp;
                if (tmp == 0)
                {
                    Console.WriteLine("Claimed solution: {0}", tmp);
                    return 0;
                }
            } while (Math.Abs(F(tmp)) > err);
            Console.WriteLine("Claimed solution: {0}", tmp);
            return 0;
        }
        static double F(double x)
        {
            return x * Math.Exp(x) - 1;
        }
    }
}
