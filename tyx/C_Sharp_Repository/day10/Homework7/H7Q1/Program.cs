using System;
class Person
{
    string Name;
    char Sex;
    int Age;
    public Person(string name, int age, char sex)
    {
        Name = name;
        Age = age;
        Sex = sex;
    }
    public void Showme()
    {
        Console.WriteLine("name:" + Name);
        Console.WriteLine("age:" + Age);
        Console.WriteLine("sex:" + Sex);
    }
}
class Teacher : Person
{
    string Major;
    string Title;
    string Lesson;
    public Teacher(string name, int age, char sex, string major, string professor, string lesson)
        : base(name, age, sex)
    {
        Major = major;
        Title = professor;
        Lesson = lesson;
    }
    new public void Showme()
    {
        base.Showme();
        Console.WriteLine("Major:" + Major);
        Console.WriteLine("Title:" + Title);
        Console.WriteLine("Lesson:" + Lesson);
    }
}
class My
{
    static int Main()
    {
        Teacher emp1 = new Teacher("张早校", 38, 'm', "chemical", "professor", "math");
        emp1.Showme();
        return 0;
    }
}
