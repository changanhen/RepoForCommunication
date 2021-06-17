using System;

namespace ConsoleApp1
{
    interface IMyInterface
    {
        void MethodToImplement();
    }
    class InterfaceImplementer : IMyInterface
    {
        static void Main(string[] args)
        {
            InterfaceImplementer iImp = new InterfaceImplementer();
            iImp.MethodToImplement();
        }
        public void MethodToImplement()
        {
            Console.WriteLine("MethodToImplement() called.");
        }
    }
}
