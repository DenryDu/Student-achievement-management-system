/**
  *本学生成绩管理系统需在D盘根目录下放置名为user.txt的空文件
  *第20-186行代码是用来美化和格式化输出的，在读代码时可忽略，调用时可以视为cout的美化版
 **/
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#define M 16
#define N 14
#define K 3
using namespace std;

//定义form系列函数用以美化&格式化输出
void form_head()
{
	system("cls");
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 102; i++)
	{
		cout << "-";
	}
}
void form_title(string a)
{
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
	cout << "|";
	for (int i = 0; i < (100 - a.length() - 18) / 2; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 9; i++)
	{
		cout << "-";
	}
	cout << a;
	for (int i = 0; i < 9; i++)
	{
		cout << "-";
	}
	for (int i = 0; i < (100 - a.length() - 18 - ((100 - a.length() - 18) / 2)); i++)
	{
		cout << " ";
	}
	cout << "|";
	cout << endl;
}
void form_choice(string a)
{
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
	cout << "|";
	cout << a;
	for (int i = 0; i < 100 - a.length(); i++)
	{
		cout << " ";
	}
	cout << "|" << endl;
}
void form_body(string a)
{
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
	cout << "|";
	for (int i = 0; i < (100 - a.length()) / 2; i++)
	{
		cout << " ";
	}
	cout << a;
	for (int i = 0; i < (100 - a.length() - ((100 - a.length()) / 2)); i++)
	{
		cout << " ";
	}
	cout << "|" << endl;
}
void form_input(string s)
{
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
	cout << "|";
	cout << s;
}
int form_int_input(string s)
{
	int ret;
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
	cout << "|";
	cout << s;
	cin >> ret;
	return ret;
}
void combo(string a, int n)
{
	stringstream bstream;
	string b;
	bstream << n;
	bstream >> b;
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
	cout << "|";
	cout << a;
	cout << n;
	for (int i = 0; i < (100 - a.length() - b.size()); i++)
	{
		cout << " ";
	}
	cout << "|" << endl;
}
void combo(string a, double n)
{
	stringstream bstream;
	string b;
	bstream << n;
	bstream >> b;
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
	cout << "|";
	cout << a;
	cout << n;
	for (int i = 0; i < (100 - a.length() - b.length()); i++)
	{
		cout << " ";
	}
	cout << "|" << endl;
}
void combo(string a, string b)
{
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
	cout << "|";
	cout << a;
	cout << b;
	for (int i = 0; i < (100 - a.length() - b.length()); i++)
	{
		cout << " ";
	}
	cout << "|" << endl;
}
void divideline()
{
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 102; i++)
	{
		cout << "-";
	}
	cout << endl;
}


//主菜单：
int main_menu()
{
	int ret;
	form_head();
	form_title("学生成绩管理");
	form_choice("请选择以下功能：    ");
	form_body("1 - 增改记录");
	form_body("2 - 修改记录");
	form_body("3 - 删除记录");
	form_body("4 - 查找    ");
	form_body("5 - 排序    ");
	form_body("6 - 显示记录");
	form_body("7 - 全删    ");
	form_body("0 - 退出    ");
	form_body("请输入选择：");
	ret = form_int_input("请输入选择：");
	return ret;
}



//学生类：
class Student     //类的定义，包括学生信息
{
	char num[N];        //学号
	char name[M];		//姓名
	int score[K];		//分数
	double gpa[K];		//gpa
	double agpa;        //平均gpa
public:
	Student() {
		/*
		for (int i = 0; i < N; i++)
		{
			num[i] = 0;
		}
		for (int i = 0; i < N; i++)
		{
			name[i] = '_';
		}
		for (int i = 0; i < K; i++)
		{
			score[i] = 0;
		}
		for (int i = 0; i < K; i++)
		{
			gpa[i] = 0;
		}
		agpa = 0;
		*/
	}
	char *getnum();					//获取学号
	char *getname();				//获取姓名
	void setname(char na[]);
	void setnum(char nu[]);			//设置学号
	void setscore(int sc[]);		//设置学生成绩
	void setgpa(double g[]);		//设置学生成绩相应绩点
	void setagpa(double ag);		//设置学生的平均绩点
	void computegpa();				//求学生的相应绩点
	void computeagpa();				//求学生的平据绩点
	void getscore(int ascore[]);	//取出学生的成绩
	void getgpa(double agpa[]);		//取出学生的绩点
	void getagpa(double &g);		//取出学生的平均绩点  
	void copy(Student &p);
	void disp();					//输出学生的信息
};

//学生类
//方法体实现：
char* Student::getnum()
{
	return num;
}
char* Student::getname()
{
	return name;
}
void Student::setname(char na[])
{
	strcpy(name, na);
}
void Student::setnum(char nu[])
{
	strcpy(num, nu);
}
void Student::setscore(int sc[])
{
	for (int i = 0; i < K; i++)
	{
		score[i] = sc[i];
	}
}
void Student::setgpa(double g[])
{
	for (int i = 0; i < K; i++)
	{
		gpa[i] = g[i];
	}
}
void Student::setagpa(double ga)
{
	agpa = ga;
}
void Student::computegpa()  //求绩点
{
	for (int i = 0; i < K; i++)
	{
		if (score[i] < 60)
		{
			gpa[i] = 0.0;
		}
		else
		{
			gpa[i] = (score[i] - 60.0) / 10.0 + 1.0;
		}
	}
}
void Student::computeagpa()  //求平均绩点
{
	double sum = 0.0;
	for (int i = 0; i < K; i++)
	{
		sum += gpa[i];
	}
	agpa = sum / K;
}
void Student::getscore(int ascore[])
{
	for (int i = 0; i < K; i++)
	{
		ascore[i] = score[i];
	}
}
void Student::getgpa(double agpa[])
{
	for (int i = 0; i < K; i++)
	{
		agpa[i] = gpa[i];
	}
}
void Student::getagpa(double &g)
{
	g = agpa;
}
void Student::copy(Student &p)
{
	int temp_score[K];
	double temp_gpa[K];
	double temp_agpa;
	this->setnum(p.getnum());
	this->setname(p.getname());

	p.getscore(temp_score);
	this->setscore(temp_score);
	p.getgpa(temp_gpa);
	this->setgpa(temp_gpa);
	p.getagpa(temp_agpa);
	this->setagpa(temp_agpa);
}
void Student::disp()
{
	int i;
	form_head();
	form_title("信息展示");
	combo("学号：", num);
	combo("姓名", name);
	combo("高数成绩：", score[0]);
	combo("高数绩点：", gpa[0]);
	combo("物理成绩：", score[1]);
	combo("物理绩点：", gpa[1]);
	combo("程序设计成绩：", score[2]);
	combo("程序设计绩点：", gpa[2]);
}
void swap(Student &a, Student &b)
{

	Student temp;
	int temp_score[K];
	double temp_gpa[K];
	double temp_agpa;
	temp.setnum(a.getnum());
	temp.setname(a.getname());
	a.getscore(temp_score);
	temp.setscore(temp_score);
	a.getgpa(temp_gpa);
	temp.setgpa(temp_gpa);
	a.getagpa(temp_agpa);
	temp.setagpa(temp_agpa);

	a.setnum(b.getnum());
	a.setname(b.getname());
	b.getscore(temp_score);
	a.setscore(temp_score);
	b.getgpa(temp_gpa);
	a.setgpa(temp_gpa);
	b.getagpa(temp_agpa);
	a.setagpa(temp_agpa);

	b.setnum(temp.getnum());
	b.setname(temp.getname());
	temp.getscore(temp_score);
	b.setscore(temp_score);
	temp.getgpa(temp_gpa);
	b.setgpa(temp_gpa);
	temp.getagpa(temp_agpa);
	b.setagpa(temp_agpa);
}


//用户数据基础类
class UserDatabase {
	int nElem;			//学生信息表中的元素个数
	int Maxu;			//最多的学生
	Student *user;		//指向学生信息的指针
public:
	UserDatabase(int n = 30);		//构造函数，将user.txt读到User[]
	~UserDatabase();				//析构函数，将user[]写入user.txt文件中
	void clear();					//删除所有学生信息
	void add_record(char *nu, char *na, int sc[]);	//添加学生信息，插入学生后仍按升序排列
	void delete_record(Student *p);					//删除学生信息
	void modify_record(Student *p, int sc[]);		//删除学生信息
	Student * query(char *nu);						//按学号查找（顺序查找），这里也可以用二分法查找
	void sorta_num();								//按学号升序排序（选择排序法）
	void sorta_name();								//按姓名升序排序（插入排序法）
	void sorta_agpa();								//按平均绩点升序排序（冒泡排序法）
	void sort_num();								//按学号降序排序（选择排序法）
	void sort_name();								//按姓名排序降序，将排成升序的对象数组逆向放置
	void sort_agpa();								//按平均绩点降序排序（冒泡排序法）
	int disp(int begin);							//输出所有学生的信息
};
UserDatabase::UserDatabase(int n)//构造函数，初始化学生信息表，将user.txt读到User[]中
{
	int i, sc[K];
	double g[K], ag;
	char num[N], na[M];
	ifstream infile;						//定义文件对象
	infile.open("D:/user.txt", ios::in);	//打开该数据文件
	if (!infile)							//打开文件发生错误，程序退出
	{
		cout << "打开文件错误" << endl;
		exit(0);
	}
	nElem = 0;
	Maxu = n;
	if (n) {
		user = new Student[n];
	}
	else {
		user = 0;
	}
	for (int i = 0; i < 9; i++)
	{
		infile >> num;
	}
	while (infile >> num)
	{
		infile >> na;
		for (i = 0; i < K; i++) {
			infile >> sc[i];
		}
		for (i = 0; i < K; i++)
		{
			infile >> g[i];
		}
		infile >> ag;
		if (nElem == Maxu)						//如果实际空间不够
		{
			Student *newptr;
			newptr = new Student[Maxu + 10];    //申请一新表空间
			for (i = 0; i < nElem; i++)
			{
				newptr[i] = user[i];			//将原表中的元素拷贝到新表中
			}
			delete []user;					//释放原表空间 delete[Maxu]user; 
			Maxu += 10;
			user = newptr;
		}

		//增加元素：
		user[nElem].setnum(num);
		user[nElem].setname(na);
		user[nElem].setscore(sc);
		user[nElem].setgpa(g);
		user[nElem].setagpa(ag);
		nElem++;
	}
	infile.close();
}

UserDatabase::~UserDatabase()
{
	ofstream ofile;
	int temp_score[K];
	double temp_gpa[K];
	double temp_agpa;
	fstream file("D:/user.txt", ios::out);
	ofile.open("D:/user.txt");
	ofile << "学号             姓名            高数          物理          程序设计          绩点1          绩点2          绩点3          平均绩点" << endl;
	for (int i = 0; i < nElem; i++)
	{
		user[i].getscore(temp_score);
		user[i].getgpa(temp_gpa);
		user[i].getagpa(temp_agpa);
		ofile << user[i].getnum() << "    " << user[i].getname();
		for (int j = 0; j < K; j++)
		{
			ofile << "              " << temp_score[j];
		}
		for (int j = 0; j < K; j++)
		{
			ofile << "                " << temp_gpa[j];
		}
		ofile << "                " << temp_agpa << endl;
	}
	ofile.close();
	nElem = 0;
	Maxu = 30;
	user = new Student[Maxu];
}

void UserDatabase::clear()
{
	nElem = 0;
	Maxu = 30;
	user = new Student[Maxu];
	ofstream f("D:/user.txt", ios::trunc);
	f.close();

}
void UserDatabase::add_record(char * num, char *name, int score[])
{
	if (nElem == Maxu)
	{
		Student *newptr;
		newptr = new Student[Maxu + 10];
		for (int i = 0; i < nElem; i++)
			newptr[i] = user[i];
		for (int i = 0; i < Maxu; i++)   //删除原来占用的空间
		{
			Student* temp;
			temp = user;
			user++;
			delete temp;
		}
		Maxu += 10;
		user = newptr;
	}
	user[nElem].setnum(num);
	user[nElem].setname(name);
	user[nElem].setscore(score);
	user[nElem].computegpa();
	user[nElem].computeagpa();
	nElem++;
}
void UserDatabase::delete_record(Student *p)
{
	int i, j;
	int temp_score[K];
	double temp_gpa[K];
	double temp_agpa;
	for (i = 0; i < nElem; i++)
	{
		if (strcmp(p->getnum(), user[i].getnum()) == 0)
		{
			for (j = i; j < nElem - 1; j++)
			{
				user[i].setnum(user[i + 1].getnum());
				user[i].setname(user[i + 1].getname());
				user[i + 1].getscore(temp_score);
				user[i].setscore(temp_score);
				user[i + 1].getgpa(temp_gpa);
				user[i].setgpa(temp_gpa);
				user[i + 1].getagpa(temp_agpa);
				user[i].setagpa(temp_agpa);
			}
		}
	}
	nElem--;
}
void UserDatabase::modify_record(Student *p, int score[])
{
	p->setscore(score);
	p->computegpa();
	p->computeagpa();
}
Student * UserDatabase::query(char *num)
{
	int i;
	for (i = 0; i < nElem; i++)
	{
		if (strcmp(user[i].getnum(), num) == 0)
		{
			return &user[i];
		}
	}
	return NULL;
}
void UserDatabase::sorta_num()
{
	int i, j;
	int min_entry;
	for (i = 0; i < nElem; i++)
	{
		min_entry = i;
		for (j = i + 1; j < nElem; j++)
		{
			if (strcmp(user[j].getnum(), user[min_entry].getnum()) < 0)
				min_entry = j;
		}
		swap(user[i], user[min_entry]);
	}
}
void UserDatabase::sorta_name()
{
	int i, j;
	Student current;
	for (i = 1; i < nElem; i++)
	{
		if (strcmp(user[i].getname(), user[i - 1].getname()) < 0)
		{
			j = i;
			current.copy(user[i]);
			do
			{
				user[j].copy(user[j - 1]);
				j--;
			} while (j > 0 && strcmp(user[j - 1].getname(), current.getname()) > 0);
			user[j].copy(current);
		}
	}
}
void UserDatabase::sorta_agpa()
{
	int i, j;
	double a, b;
	for (i = nElem - 1; i >= 1; i--)
	{
		for (j = 0; j < i; j++)
		{
			user[j].getagpa(a);
			user[j + 1].getagpa(b);
			if (a > b)
			{
				swap(user[j], user[j + 1]);
			}
		}
	}
}
void UserDatabase::sort_num()
{
	int i, j;
	int max_entry;
	for (i = 0; i < nElem; i++)
	{
		max_entry = i;
		for (j = i + 1; j < nElem; j++)
		{
			if (strcmp(user[j].getnum(), user[max_entry].getnum()) > 0)
				max_entry = j;
		}
		swap(user[i], user[max_entry]);
	}
}
void UserDatabase::sort_name()
{
	int i, j;
	Student current;
	for (i = 1; i < nElem; i++)
	{
		if (strcmp(user[i].getname(), user[i - 1].getname()) > 0)
		{
			j = i;
			current.copy(user[i]);
			do
			{
				user[j].copy(user[j - 1]);
				j--;
			} while (j > 0 && strcmp(user[j - 1].getname(), current.getname()) < 0);
			user[j].copy(current);
		}
	}
}
void UserDatabase::sort_agpa()
{
	double a, b;
	for (int i = nElem - 1; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			user[j].getagpa(a);
			user[j + 1].getagpa(b);
			if (a < b)
			{
				swap(user[j], user[j + 1]);
			}
		}
	}
}
int UserDatabase::disp(int begin)
{
	cout << endl;
	int i, j;
	if (nElem == 0)
	{
		form_head();
		form_title("ERROR!");
		form_body("没有任何记录");
		divideline();
		form_body("3秒后自动返回菜单");
		_sleep(3 * 1000);
		return 0;
	}
	int start = (begin - 1) * 10;
	int total = (nElem % 10 == 0) ? nElem / 10 : nElem / 10 + 1;
	int temp_score[K];
	double temp_gpa[K];
	double temp_agpa;
	char c[10];
	form_head();
	form_title("记录显示");
	form_choice("学号           姓名             高数   物理   程序设计 绩点1   绩点2   绩点3   平均绩点");
	if ((nElem - start) <= 10)
	{
		for (i = start; i < nElem; i++)
		{
			cout << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << " ";
			}
			cout << "|";
			user[i].getscore(temp_score);
			user[i].getgpa(temp_gpa);
			user[i].getagpa(temp_agpa);
			printf("%-14s ", user[i].getnum());
			printf("%-16s ", user[i].getname());
			printf("%-4d   %-4d   %-4d   ", temp_score[0], temp_score[1], temp_score[2]);
			printf("  %-4.1lf    %-4.1lf    %-4.1lf     ", temp_gpa[0], temp_gpa[1], temp_gpa[2]);
			printf("%.1lf", temp_agpa);
			for (int i = 0; i < 17; i++)
			{
				cout << " ";
			}
			cout << "|" << endl;
		}
	}
	else
	{
		for (i = start; i < 10; i++)
		{

			user[i].getscore(temp_score);
			user[i].getgpa(temp_gpa);
			user[i].getagpa(temp_agpa);
			printf("%-14s ", user[i].getnum());
			printf("%-16s ", user[i].getname());
			printf("%-4d   %-4d   %-4d   ", temp_score[0], temp_score[1], temp_score[2]);
			printf("  %-4.1lf    %-4.1lf    %-4.1lf     ", temp_gpa[0], temp_gpa[1], temp_gpa[2]);
			printf("%.1lf", temp_agpa);
			for (int i = 0; i < 17; i++)
			{
				cout << " ";
			}
			cout << "|" << endl;
		}

	}
	for (int i = 0; i < 5; i++)
		cout << " ";
	for (i = 0; i < 80; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << " ";
	printf("现在所在页数：%d, 共%d页\n", begin, total);
	for (int i = 0; i < 5; i++)
		cout << " ";
	printf("下一页（Y/N）:");
	cin >> c;
	for (int i = 0; i < 5; i++)
		cout << " ";
	for (i = 0; i < 91; i++)
		cout << "-";
	cout << endl;
	if (begin == total)
	{
		return 1;
	}
	if (strcmp(c, "Y") == 0 || strcmp(c, "y") == 0)
	{
		disp(begin + 1);
	}
	return 1;
}



int add_page(UserDatabase &user)
{
	char num[N];
	char name[M];
	int score[K];
	form_head();
	form_title("增加记录");
	form_input("请输入学生学号: ");
	cin >> num;
	if (user.query(num) != NULL)
	{
		form_head();
		form_title("  ERROR!  ");
		form_body("该学生已存在");
		form_body("3秒后自动返回菜单");
		_sleep(3 * 1000);
		return 0;
	}
	else
	{
		form_input("请输入学生姓名：");
		cin >> name;
		form_input("请输入学生高数成绩：");
		cin >> score[0];
		form_input("请输入学生物理成绩：");
		cin >> score[1];
		form_input("请输入学生程序设计成绩：");
		cin >> score[2];
		user.add_record(num, name, score);
		user.sorta_num();
		divideline();
		form_body("添加成功");
		divideline();
		cout << endl;

		form_body("3秒后自动返回菜单");
		_sleep(3 * 1000);

		return 0;
	}
}

int modify_page(UserDatabase &user)
{
	cout << endl;
	char num[N];
	char name[M];
	int score[K];
	Student *temp;
	char c[N];
	form_head();
	form_title("修改记录");
	form_input("请输入学生学号: ");
	cin >> num;
	if (user.query(num) == NULL)
	{
		form_head();
		form_title("  ERROR!  ");
		form_body("该学生不存在");
		form_body("3秒后自动返回菜单");
		_sleep(3 * 1000);
		return 0;
	}
	else
	{
		temp = user.query(num);
		temp->disp();
		form_input("请输入学生修改后高数成绩：");
		cin >> score[0];
		form_input("请输入学生修改后物理成绩：");
		cin >> score[1];
		form_input("请输入学生修改后程序设计成绩：");
		cin >> score[2];
		divideline();
		form_input("确认修改（Y/N）：");
		cin >> c;
		divideline();
		if (strcmp(c, "Y") == 0 || strcmp(c, "y") == 0)
		{
			user.modify_record(temp, score);

			divideline();
			form_title("修改成功");
			user.sorta_num();
			form_body("3秒后自动返回菜单");
			_sleep(3 * 1000);
			return 1;
		}
		else
		{
			form_head();
			form_title("  ERROR!  ");
			form_body("修改失败");
			form_body("3秒后自动返回菜单");
			_sleep(3 * 1000);
			return 0;

		}
	}
}

int delete_page(UserDatabase &user)
{
	cout << endl;
	int i, j, k;
	char num[N];
	char name[M];
	int score[K];
	double gpa[K];
	double agpa;
	Student *temp;
	char c[N];
	form_head();
	form_title("删除记录");
	form_input("请输入学生学号: ");
	cin >> num;
	if (user.query(num) == NULL)
	{
		form_head();
		form_title("  ERROR!  ");
		form_body("该学生不存在");
		form_body("3秒后自动返回菜单");
		_sleep(3 * 1000);
		return 0;
	}
	else
	{
		temp = user.query(num);
		temp->disp();
		divideline();
		form_input("确认删除（Y/N）：");
		cin >> c;
		cout << endl;
		if (strcmp(c, "Y") == 0 || strcmp(c, "y") == 0)
		{
			user.delete_record(temp);
			divideline();
			form_body("删除成功");
			form_body("3秒后自动返回菜单");
			_sleep(3 * 1000);
			user.sorta_num();
			return 1;
		}
		else
		{
			form_body("删除失败");
			form_body("3秒后自动返回菜单");
			_sleep(3 * 1000);
			return 0;
		}
	}

}
int search_page(UserDatabase &user)
{
	cout << endl;
	int i, j, k;
	char num[N];
	char name[M];
	int score[K];
	double gpa[K];
	double agpa;
	Student *temp;
	char c[N];
	form_head();
	form_title(" 查找 ");
	form_input("请输入学生学号: ");
	cin >> num;
	if (user.query(num) == NULL)
	{
		form_head();
		form_title("  ERROR!  ");
		form_body("该学生不存在");
		form_body("3秒后自动返回菜单");
		_sleep(3 * 1000);
		return 0;
	}
	else
	{
		char in;
		temp = user.query(num);
		temp->disp();
		divideline();
		form_input("输入任意字符再按回车即可返回菜单:");
		cin >> in;
		form_body("3秒后自动返回菜单");
		_sleep(3 * 1000);
		return 0;
	}

}
int sort_page(UserDatabase &user)
{
start:
	cout << endl;
	int i, j, k;
	form_head();
	form_title("排序页");
	form_choice("请选择排序方式");
	form_body("1 - 按学号（升序）");
	form_body("2 - 按姓名（升序）");
	form_body("3 - 按平均绩点（升序）");
	form_body("4 - 按学号（降序）");
	form_body("5 - 按姓名（降序）");
	form_body("6 - 按平均绩点（降序）");
	form_body("0 - 退出  ");
	form_input("请输入你的选择：");
	int num;
	cin >> num;
	switch (num)
	{
	case 0:
		return 0;
	case 1:
		user.sorta_num();
		break;
	case 2:
		user.sorta_name();
		break;
	case 3:
		user.sorta_agpa();
		break;
	case 4:
		user.sort_num();
		break;
	case 5:
		user.sort_name();
		break;
	case 6:
		user.sort_agpa();
		break;
	default:
		form_head();
		form_title("  ERROR!  ");
		form_body("输入的号码超出服务范围，请进入菜单重新选择");
		form_body("3秒后自动返回菜单");
		_sleep(3 * 1000);
		goto start;
	}

	form_head();
	form_title("排序成功");
	form_body("3秒后自动返回菜单");
	_sleep(3 * 1000);

	return 1;
}
int all_delete(UserDatabase &user)
{
	int i, j;
	char c[10];
	form_head();
	form_title("全部删除");
	form_input("确认删除（Y/N）：");
	cin >> c;
	for (i = 0; i < 40; i++)
		cout << "-";
	cout << endl;
	if (strcmp(c, "Y") == 0 || strcmp(c, "y") == 0)
	{
		user.clear();
		form_head();
		form_title("清除成功");
		form_body("3秒后自动返回菜单");
		_sleep(3 * 1000);
		return 1;
	}
	else
	{
		form_head();
		form_body("3秒后自动返回菜单");
		_sleep(3 * 1000);
		return 0;
	}
}


void error_page()
{
	form_head();
	form_title("  ERROR!  ");
	form_body("输入的号码超出服务范围，请进入菜单重新选择");
	form_body("3秒后自动返回菜单");
	_sleep(3 * 1000);
}

int main()
{
	UserDatabase user;
start:
	system("cls");
	int flag = main_menu();
	while (flag != 0)
	{
		switch (flag)
		{
		case 1:
			add_page(user);
			break;
		case 2:
			modify_page(user);
			break;
		case 3:
			delete_page(user);
			break;
		case 4:
			search_page(user);
			break;
		case 5:
			sort_page(user);
			break;
		case 6:
			user.disp(1);
			break;
		case 7:
			all_delete(user);
			break;
		case 0:
			return 0;
		default:
			error_page();
		}

		flag = main_menu();
	}
	return 0;
}
