using System;

namespace H6Q1
{
    class Program
    {
        static void Main(string[] args)
        {
            string name, sex;
            double age, weight;
            Console.WriteLine("What is the dog like?(name,age,sex,weight(kg))");
            name = Console.ReadLine();
            age = Convert.ToDouble(Console.ReadLine());
            sex = Console.ReadLine();
            weight = Convert.ToDouble(Console.ReadLine());
            Dog dog1 = new Dog(name, age, sex, weight);
            Console.WriteLine("Information of dog1: ");
            dog1.PrintDogInfo();
            Dog dog2 = new Dog("Lele", 6, "female", 6.0);
            Console.WriteLine("Information of dog2: ");
            dog2.PrintDogInfo();
        }
    }
    public class Dog
    {
        private string Name;
        private double Age;
        private string Sex;
        private double Weight;
        public Dog(string name, double age, string sex, double weight)
        {
            Name = name;
            Age = age;
            Weight = weight;
            Sex = sex;
        }
        public void PrintDogInfo()
        {
            Console.WriteLine("{0}\t{1}\t{2}\t{3}", Name, Age, Sex, Weight);
        }
    }

}
