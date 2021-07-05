#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cctype>
#define SIZE 20

using namespace std;

//const int SIZE=20;
int i, j = 0;

typedef struct Student
{
    char ClassNum[SIZE]; //班级
    char Id[SIZE];       //学号
    char Name[SIZE];     //姓名
    int *Score;
} student;

void Input(student p[], string c_Name[], int s_Num, int c_Num);                 //输入学生的成绩信息， 包括学号、姓名、性别等基本信息和各科成绩
void ShowStuInfo(student p[], string c_Name[], int s_Num, int c_Num);           // 显示全部学生各科成绩信息；
void Statistic(student p[], string c_Name[], int s_Num, int c_Num);             //对各科分班进行成绩统计分析，计算总分、平均分、最高分、最低分、及格率等；
void Section(student p[], string c_Name[], int s_Num, int c_Num);               //统计各个科目各分数段人数及班级信息；
void Search(student p[], string c_Name[], int s_Num, int c_Num);                //按学号或姓名查找并显示某个学生的各科成绩；
void Sort(student p[], string c_Name[], int s_Num, int c_Num);                  //按课程成绩或总分由高到低排序显示；
void UpdateStuInfo(student p[], string c_Name[], int s_Num, int c_Num);         //更新某个学生的基本信息或课程成绩；
void QuickSort(int s[], int l, int r);                                          //快速排序
//void FileOut(student p[], string c_Name[], int s_Num, int c_Num, int Semester); //文件形式输出

int main()
{
    cout << setw(25) << " "
         << " 欢 迎 使 用 本 系 统 ！" << endl;
    cout << "********************************************************************************" << endl
         << endl;
    cout << "****************************《学生成绩管理系统》********************************" << endl
         << endl;
    cout << "********************************************************************************" << endl;
    int n = 0;
    int StudentNum; //学生数
    int Semester;   //学期
    int CourseNum;  //课程数
    cout << "是否从文档中读取基础信息？（Y/N）：";
    char fs;
    cin >> fs;
    cin.get();
    while (tolower(fs) != 'y' && tolower(fs) != 'n')
    {
        cout << "输入有误，请重新输入（Y/N）：";
        cin >> fs;
        cin.get();
    }
    if (tolower(fs) == 'y')
    {
        ifstream fin;
        n = 1;
        cout << "****************说明：****************" << endl;
        cout << "****************如上次保存的文档名为 student.txt****************" << endl;

        cout << "****************则读取的文档名为 basic_student.txt****************" << endl;
        cout << "请输入基本信息文档名：";
        char FileName[SIZE];
        cin.getline(FileName, SIZE);
        fin.open(FileName);
        while (!fin.is_open())
        {
            cout << "不能打开此文档名的文档，请重新输入：";
            cin.getline(FileName, SIZE);
            fin.open(FileName);
        }
        fin >> StudentNum;
        fin.get();
        fin >> Semester;
        fin.get();
        fin >> CourseNum;
        fin.get();
    }
    else
    {
        system("pause");
        system("cls");

        cout << setfill('=') << setw(32);
        cout << "请输入学生人数：";
        cin >> StudentNum;
        while (!cin.good())
        {

            cin.clear();
            cin.sync();
            cout << "输入有误！请重新输入学生个数: ";
            cin >> StudentNum;
            cin.get();
        }
        cout << "================";
        cout << "请输入学期（以数字形式）：";
        cin >> Semester;
        while (!cin.good())
        {
            cin.clear();
            cin.sync();
            cout << "输入有误！请重新输入学期: ";
            cin >> StudentNum;
            cin.get();
        }
        cout << setfill('=') << setw(25);
        cout << "请输入第 " << Semester << " 学期的课程数目: ";
        cin >> CourseNum;
        cin.get();
        while (!cin.good())
        {
            cin.clear();
            cin.sync();
            cout << "输入有误！请重新输入第 " << Semester << " 学期的课程数目: ";
            cin >> CourseNum;
            cin.get();
        }
    }
    student *p = new student[StudentNum];
    string *CourseName = new string[CourseNum];

    if (tolower(fs) == 'y')
    {
        ifstream fin;
        cout << "****************	说明：******************" << endl;
        cout << "****************	如上次保存的文档名为 student.txt******************" << endl;
        cout << "****************	则读取的文档名为 course_student.txt******************" << endl;
        cout << "请输入课程信息文档名：";
        char FileName[SIZE];
        cin.getline(FileName, SIZE);
        fin.open(FileName);
        while (!fin.is_open())
        {
            cout << "不能打开此文档名的文档，请重新输入：";
            cin.getline(FileName, SIZE);
            fin.open(FileName);
        }
        for (int i = 0; i < CourseNum; i++)
        {
            getline(fin, CourseName[i]);
        }
    }
    else
    {

        system("pause");
        system("cls");

        for (int i = 0; i < CourseNum; i++)
        {
            cout << setfill('=') << setw(25);
            cout << "请输入第 " << i + 1 << " 个课程名：";
            cin >> CourseName[i];
            cin.get();
        }
    }
    int i;
    int **all_score = new int *[StudentNum];
    for (i = 0; i < StudentNum; i++)
        all_score[i] = new int[CourseNum];

    for (i = 0; i < StudentNum; i++)
        p[i].Score = &all_score[i][0];

    if (tolower(fs) == 'y')
    {
        ifstream fin;
        cout << "******************	说明：******************" << endl;
        cout << "******************	如上次保存的文档名为 student.txt******************" << endl;
        cout << "******************	则读取的文档名为 student_student.txt******************" << endl;
        cout << "请输入学生信息文档名：";
        char FileName[SIZE];
        cin.getline(FileName, SIZE);
        fin.open(FileName);
        while (!fin.is_open())
        {
            cout << "不能打开此文档名的文档，请重新输入：";
            cin.getline(FileName, SIZE);
            fin.open(FileName);
        }
        int i;
        for (i = 0; i < StudentNum; i++)
        {
            fin.get(p[i].ClassNum, SIZE);
            fin.get();
            fin.get(p[i].Id, SIZE);
            fin.get();
            fin.getline(p[i].Name, SIZE);
            for (int j = 0; j < CourseNum; j++)
            {
                fin >> *(p[i].Score + j);
                fin.get();
            }
        }
        fin.close();
    }
    system("pause");
    system("cls");
    char Select = 'a';
    while (Select != 'q')
    {

        cout << "********************************************************************************" << endl;

        cout << "请输入选择：" << endl;
        cout << "【1】输入基本信息	"
             << "【2】显示成绩信息	"
             << "【3】成绩统计分析" 
             << endl;
        cout << "【4】统计各科各分数段人数 "
             << "【5】查找某个学生的各科成绩 "
             << "【6】由高到低显示成绩" 
             << endl;
        cout << "【7】更新学生成绩	"
             << "【8】保存学生与成绩信息	"
             << "【9】结束" 
             << endl
             << endl;

        cout << "********************************************************************************" << endl;
        cout << " 输 入 ：";
        cin.get(Select);
        cin.get();
        while (n == 0 && Select != '1')
        {
            cout << "输入有误，请先输入基本信息！" << endl;
            Select = '1';
        }
        if (Select == '1')
            Input(p, CourseName, StudentNum, CourseNum);
        else if (Select == '2')
            ShowStuInfo(p, CourseName, StudentNum, CourseNum);
        else if (Select == '3')
            Statistic(p, CourseName, StudentNum, CourseNum);
        else if (Select == '4')
            Section(p, CourseName, StudentNum, CourseNum);
        else if (Select == '5')
            Search(p, CourseName, StudentNum, CourseNum);
        else if (Select == '6')
            Sort(p, CourseName, StudentNum, CourseNum);
        else if (Select == '7')
            UpdateStuInfo(p, CourseName, StudentNum, CourseNum);
        else if (Select == '8')
            ;//FileOut(p, CourseName, StudentNum, CourseNum, Semester);
        else if (Select == '9')
        {

            cout << "********************************************************************************" << endl;
        }
        else

            cout << "欢迎使用，再见!" << endl;
        return 0;

        cout << "输入有误，请重新输入： " << endl;

        n++;
    }
    delete p;
    delete CourseName;
    for (i = 0; i < StudentNum; i++)
        delete[] all_score[i];
    delete all_score;
    system("pause");
    return 0;
}
void Input(student p[], string c_Name[], int s_Num, int c_Num)
{
    for (int i = 0; i < s_Num; i++)
    {
        if (i > 0)
        {
            cout << "《****************************************************************************》";
            cout << "《****************************************************************************》";
            cout << "《********************************请继续输入**********************************》";
            cout << "《****************************************************************************》";
            cout << "《****************************************************************************》";
            cout << endl;
        }
        cout << setfill('=') << setw(25);
        cout << "请输入第 " << i + 1 << "个学生的班级：";
        cin.get(p[i].ClassNum, SIZE);
        cin.get();
        while (!cin.good())
        {
            cin.clear();
            cin.sync();
            cout << "输入有误！请重新输入: ";
            cin.get(p[i].ClassNum, SIZE);
            cin.get();
        }
        cout << setfill('=') << setw(24);
        cout << "请输入" << i + 1 << "个学生的学号：";
        cin.get(p[i].Id, SIZE);
        cin.get();

        while (!cin.good())
        {
            cin.clear();
            cin.sync();
            cout << "输入有误！请重新输入: ";
            cin.get(p[i].Id, SIZE);
            cin.get();
        }
        for (int k = 0; k < s_Num; k++)
        {
            if (k == i)
                k++;
            if (strcmp(p[k].Id, p[i].Id) == 0)
            {
                cout << setfill('=') << setw(25);
                cout << "与已有学生的学号重复，请重新输入：";
                cin.get(p[i].Id, SIZE);
                cin.get();
                while (!cin.good())
                {
                    cin.clear();
                    cin.sync();
                    cout << "输入有误！请重新输入: ";
                    cin.get(p[i].Id, SIZE);
                    cin.get();
                }
            }
        }
        cout << setfill('=') << setw(32);
        cout << "请输入其姓名：";
        cin.getline(p[i].Name, SIZE);
        while (!cin.good())
        {
            cin.clear();
            cin.sync();
            cout << "输入有误！请重新输入: ";
            cin.getline(p[i].Name, SIZE);
        }
        for (int j = 0; j < c_Num; j++)
        {
            cout << setfill('=') << setw(24);
            cout << "请输入" << c_Name[j] << "的成绩：";
            cin >> *(p[i].Score + j);
            cin.get();

            while (!cin.good())
            {
                cin.clear();
                cin.sync();
                cout << "输入有误！请重新输入: ";
                cin >> *(p[i].Score + j);
                cin.get();
            }
            while (*(p[i].Score + j) > 100 || *(p[i].Score + j) < 0)
            {
                cout << setfill('=') << setw(25);
                cout << "输入有误，请输入 0 到 100 之内的数：";
                cin >> *(p[i].Score + j);
                cin.get();
                while (!cin.good())
                {
                    cin.clear();
                    cin.sync();
                    cout << "输入有误！请重新输入: ";
                    cin >> *(p[i].Score + j);
                    cin.get();
                }
            }
        }
        system("pause");
        system("cls");
    }
}
void ShowStuInfo(student p[], string c_Name[], int s_Num, int c_Num)
{
    cout << "********************************************************************************";
    cout << " 科 目 ：\t\t";
    for (int j = 0; j < c_Num; j++)
        cout << "\t" << c_Name[j];
    cout << endl;
    cout << "********************************************************************************";
    for (int i = 0; i < s_Num; i++)
    {
        cout << p[i].ClassNum << "班：" << p[i].Name << ":";
        if (isalpha(p[i].Name[0]))
            cout << "\t\t";
        else

            cout << "\t";
        for (int j = 0; j < c_Num; j++)
            cout << *(p[i].Score + j) << "\t";
        cout << endl;

        cout << "********************************************************************************";
    }
    system("pause");
    system("cls");
}
void Statistic(student p[], string c_Name[], int s_Num, int c_Num)
{
    int sum, ave, max, min, pass, trigger, cl_num;
    double PassRate;
    for (int i = 0; i < c_Num; i++)
    {
        cout << "【" << c_Name[i] << "科目】" << endl;
        for (int k = 0; k < s_Num; k++)
        {
            sum = 0;    //总分trigger=0; ave=0; //平均分
            cl_num = 0; //各班级总人数pass_rate=0;
            pass = 0;
            max = *(p[k].Score + i); //最高分min=*(p[k].Score+i); // 最低分int j;
            for (j = 0; j < k; j++)
                if (strcmp(p[k].ClassNum, p[j].ClassNum) == 0)
                    trigger = 1;
            if (trigger == 1)
                continue;
            for (j = k; j < s_Num; j++)
            {
                if (strcmp(p[k].ClassNum, p[j].ClassNum) == 0)
                {
                    sum += *(p[j].Score + i);
                    cl_num++;
                    if ((*p[j].Score + i) > max)
                        max = *(p[j].Score + i);
                    if ((*p[j].Score + i) < min)
                        min = *(p[j].Score + i);

                    if (*(p[j].Score + i) >= 60)
                        pass++;
                }
            }
            cout << p[k].ClassNum << "班" << endl;
            cout << " 总 分 为 ：" << sum << " ";
            ave = sum / cl_num;
            cout << "平均分为：" << ave << " ";
            cout << "最高分为：" << max << " ";
            cout << "最低分为：" << min << " ";
            PassRate = (1.0 * pass) / cl_num;
            cout << "及格率为：" << PassRate * 100 << "%" << endl;
        }
    }
    system("pause");
    system("cls");
}
void Section(student p[], string c_Name[], int s_Num, int c_Num)
{
    int s_nopass, s_60, s_70, s_80, s_90, trigger;
    for (int i = 0; i < c_Num; i++)
    {
        cout << endl;
        cout << endl;
        cout << "【" << c_Name[i] << "】" << endl;
        for (int k = 0; k < s_Num; k++)
        {
            trigger = 0;
            s_nopass = 0;
            s_60 = 0;
            s_70 = 0;
            s_80 = 0;
            s_90 = 0;
            for (int j = 0; j < k; j++)
                if (strcmp(p[k].ClassNum, p[j].ClassNum) == 0)
                    trigger = 1;
            if (trigger == 1)
                continue;
            for (int j = k; j < s_Num; j++)
            {
                if (strcmp(p[k].ClassNum, p[j].ClassNum) == 0)
                {
                    if (*(p[j].Score + i) >= 90)
                        s_90++;

                    else if (*(p[j].Score + i) >= 80)
                        s_80++;
                    else if (*(p[j].Score + i) >= 70)
                        s_70++;
                    else if (*(p[j].Score + i) >= 60)
                        s_60++;
                    else if (*(p[j].Score + i) < 60)
                        s_nopass++;
                }
            }
            cout << endl;
            cout << p[k].ClassNum << "班" << endl;
            cout << " 不 及 格 ：" << s_nopass << " 人 ";
            cout << "60 至 70 分 ：" << s_60 << " 人 ";
            cout << "70 至 80 分 ：" << s_70 << " 人 ";
            cout << "80 至 90 分 ：" << s_80 << " 人 ";
            cout << "90 至 100 分：" << s_90 << " 人 " << endl;

            cout << "********************************************************************************";
        }
    }
    system("pause");
    system("cls");
}
void Search(student p[], string c_Name[], int s_Num, int c_Num)
{
    char Name_or_id[SIZE];
    cout << "请输入学号或名字：";
    cin.get(Name_or_id, SIZE);
    cin.get();
    while (!cin.good())
    {
        cin.clear();
        cin.sync();
        cout << "输入有误！请重新输入: ";
        cin.get(Name_or_id, SIZE);
        cin.get();
    }
    cout << "********************************************************************************" << endl;
    int n = 0;
    for (int i = 0; i < s_Num; i++)
    {

        if (strcmp(p[i].Name, Name_or_id) == 0 || strcmp(p[i].Id, Name_or_id) == 0)
        {
            n++;
            cout << "学号" << p[i].Id << "的" << p[i].Name << "同学的成绩如下：" << endl;
            for (int j = 0; j < c_Num; j++)
                cout << c_Name[j] << "科目：" << *(p[i].Score + j) << "分" << endl;
            cout << endl;
        }
    }
    if (n == 0)
        cout << "没有这名同学的信息。" << endl;
    system("pause");
    system("cls");
}
void Sort(student p[], string c_Name[], int s_Num, int c_Num)
{
    int *score_s = new int[s_Num];
    for (int i = 0; i < c_Num; i++)
    {
        for (int j = 0; j < s_Num; j++)
            score_s[j] = *(p[j].Score + i);
        QuickSort(score_s, 0, s_Num - 1);

        cout << "********************************************************************************" << endl;
        cout << "【" << c_Name[i] << "】由高到低的分数排序如下：" << endl;
        for (j = 0; j < s_Num; j++)
            cout << score_s[j] << "分 ";
        cout << endl;

        cout << "********************************************************************************" << endl;
    }
    system("pause");
    system("cls");
    delete[] score_s;
}
void UpdateStuInfo(student p[], string c_Name[], int s_Num, int c_Num)
{
    char Name_or_id[SIZE];
    cout << "请输入学号或名字：";
    cin.get(Name_or_id, SIZE);
    cin.get();
    char ch;

    int n = 0;
    for (int i = 0; i < s_Num; i++)
    {
        if (strcmp(p[i].Name, Name_or_id) == 0 || strcmp(p[i].Id, Name_or_id) == 0)
        {
            n++;
            cout << "请选择要执行的操作：" << endl;

            cout << "********************************************************************************" << endl;
            cout << "(a)更新学生的基本信息 (b)更新学生的成绩 (q)结束" << endl;

            cout << "********************************************************************************" << endl;
            cout << "输入：";
            cin.get(ch);
            cin.get();
            if (ch != 'q')
            {
                if (ch == 'a')
                {
                    cout << " 请 输 入 其 班 级 ";
                    cin.get(p[i].ClassNum, SIZE);
                    cin.get();
                    while (!cin.good())
                    {
                        cin.clear();
                        cin.sync();
                        cout << "输入有误！请重新输入: ";
                        cin.get(p[i].ClassNum, SIZE);
                        cin.get();
                    }
                    cout << "请输入其学号：";
                    cin.get(p[i].Id, SIZE);
                    cin.get();
                    while (!cin.good())
                    {
                        cin.clear();
                        cin.sync();
                        cout << "输入有误！请重新输入: ";
                        cin.get(p[i].Id, SIZE);
                        cin.get();
                    }
                    for (int k = 0; k < s_Num; k++)

                    {
                        if (k == i)
                            k++;
                        if (strcmp(p[k].Id, p[i].Id) == 0)
                        {
                            cout << "与已有学生的学号重复，请重新输入：" << endl;
                            cin.get(p[i].Id, SIZE);
                            cin.get();

                            cout << "********************************************************************************";
                            while (!cin.good())
                            {
                                cin.clear();
                                cin.sync();
                                cout << "输入有误！请重新输入: ";
                                cin.get(p[i].Id, SIZE);
                                cin.get();

                                cout << "********************************************************************************";
                            }
                        }
                    }
                    cout << "请输入其姓名：";
                    cin.getline(p[i].Name, SIZE);
                    while (!cin.good())
                    {
                        cin.clear();
                        cin.sync();
                        cout << "输入有误！请重新输入: ";
                        cin.getline(p[i].Name, SIZE);

                        cout << "********************************************************************************";
                    }
                }
                else if (ch == 'b')
                {
                    for (int j = 0; j < c_Num; j++)
                    {
                        cout << "请输入" << c_Name[j] << "的成绩：";
                        cin >> *(p[i].Score + j);
                        cin.get();

                        while (!cin.good())
                        {
                            cin.clear();
                            cin.sync();
                            cout << "输入有误！请重新输入: ";
                            cin >> *(p[i].Score + j);
                            cin.get();
                        }
                        while (*(p[i].Score + j) > 100 || *(p[i].Score + j) < 0)
                        {
                            cout << "输入有误，请输入 0 到 100 之内的数：";
                            cin >> *(p[i].Score + j);
                            cin.get();
                            while (!cin.good())
                            {
                                cin.clear();
                                cin.sync();
                                cout << "输入有误！请重新输入: ";
                                cin >> *(p[i].Score + j);
                                cin.get();
                            }
                        }
                    }
                }
                else
                {

                    cout << "输入有误，请重新输入：";
                    cin.get(ch);
                    cin.get();
                }
            }
        }
    }
    if (n == 0)
    {
        cout << "没有这名同学。" << endl;
    }
    system("pause");
    system("cls");
}

/*
void FileOut(student p[], string c_Name[], int s_Num, int c_Num, int Semester)
{
    ofstream fout;
    char fName[SIZE];

    char _fName1[SIZE] = "basic_";
    char _fName2[SIZE] = "course_";
    char _fName3[SIZE] = "student_";
    cout << "请输入要保存的文件名(需要加上后缀.txt)：";
    cin.getline(fName, SIZE);
    strcat(_fName1, fName);
    strcat(_fName2, fName);
    strcat(_fName3, fName);
    fout.open(fName);
    for (int i = 0; i < s_Num; i++)
    {

        fout << "********************************************************************************" << endl;
        fout << "【个人信息】";
        fout << "姓名：" << p[i].Name << " "
             << "班级：" << p[i].ClassNum << "班 "
             << "学号： " << p[i].Id << endl;

        fout << "********************************************************************************" << endl;
        fout << " 【 成 绩 】 ";
        for (int j = 0; j < c_Num; j++)
            fout << c_Name[j] << "：" << *(p[i].Score + j) << " ";
        fout << endl;
        fout << "********************************************************************************" << endl;
        fout << endl;
    }
    fout.close();
    fout.open(_fName1);
    fout << s_Num << endl;
    fout << Semester << endl;
    fout << c_Num << endl;
    fout.close();
    fout.open(_fName2);
    for (i = 0; i < c_Num; i++)
        fout << c_Name[i] << endl;
    fout.close();
    fout.open(_fName3);
    for (i = 0; i < s_Num; i++)
    {

        fout << p[i].ClassNum << endl;
        fout << p[i].Id << endl;
        fout << p[i].Name << endl;
        for (int j = 0; j < c_Num; j++)
            fout << *(p[i].Score + j) << endl;
    }

    cout << "已输出到" << fName << "中。" << endl;
    system("pause");
    system("cls");
}
*/
void QuickSort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] <= x)
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] >= x)
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        QuickSort(s, l, i - 1);
        QuickSort(s, i + 1, r);
    }
}