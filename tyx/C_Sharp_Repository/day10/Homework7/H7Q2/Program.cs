using System;
class Vehicle
{
    double Weight;
    int Number;
    public Vehicle(double weight, int number)
    {
        Weight = weight;
        Number = number;
    }
    public void Showme()
    {
        Console.WriteLine("重量:" + Weight);
        Console.WriteLine("轮数:" + Number);
    }
}
class Car : Vehicle
{
    int Passenger_load;
    public Car(double weight, int number, int passenger_load)
        : base(weight, number)
    {
        Passenger_load = passenger_load;
    }
    new public void Showme()
    {
        base.Showme();
        Console.WriteLine("车载数:" + Passenger_load);
    }
}
class Trunk : Vehicle
{
    int Passenger_load;
    double Pay_load;
    public Trunk(double weight, int number, int passenger_load, double pay_load)
        : base(weight, number)
    {
        Passenger_load = passenger_load;
        Pay_load = pay_load;
    }
    new public void Showme()
    {
        base.Showme();
        Console.WriteLine("车载数:" + Passenger_load);
        Console.WriteLine("承重:" + Pay_load);
    }
}
class My
{
    static int Main()
    {
        Car emp1 = new Car(124, 4, 5);
        emp1.Showme();
        Trunk emp2 = new Trunk(200.1, 4, 6, 2000.2);
        emp2.Showme();
        return 0;
    }
}
