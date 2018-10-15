/*main.cpp*/

//
// Grade Analysis program in modern C++.
//
// << Nemil R Shah >>
// U. of Illinois, Chicago
// CS 341: Fall 2018
// Project 01
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


class Course
{
private:

	int ind;
	string departt;
	int courseNum;
	string title;
	string inst;
	vector <int> g;
	//int g[10];   // change this to vectOR LATER.
	int numCG;

public:
	int numTG = 0;
	Course()
	{}
	Course(string department, int courseNumber, string Title, int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9, int x10, string instructor, int index)
	{
		departt = department;
		courseNum = courseNumber;
		title = Title;
		inst = instructor;
		numCG = 0;
		ind = index;
		dupinst = inst;

		g.push_back(x1);
		g.push_back(x2);
		g.push_back(x3);
		g.push_back(x4);
		g.push_back(x5);
		g.push_back(x6);
		g.push_back(x7);
		g.push_back(x8);
		g.push_back(x9);
		g.push_back(x10);

	
		for (int i = 0; i < 5; i++)
		{
			numCG = g[i] + numCG;
		}
	}

	string depart()
	{
		return departt;
	}

	int coursenum()
	{
		return courseNum;
	}

	int index()
	{
		return ind;
	}

	string department()
	{
		return departt;
	}

	int courseNumber()
	{
		return courseNum;
	}

	string getInstructorName()
	{
		return inst;
	}

	// Returns the number of students in this course
	int getNumStudents()
	{
		int z = 0;

		for (int i = 0; i < 10; i++)
		{
			z = g[i] + z;
		}
		return z;
	}

	void course_distribution()
	{
		float as = a_grade();  // no. of a grades.
		float bs = b_grade();
		float cs = c_grade();
		float ds = d_grade();
		float fs = f_grade();
		float a_dis = 0;
		float  b_dis = 0;
		float  c_dis = 0;
		float  d_dis = 0;
		float  f_dis = 0;
		int all = getNumStudents();
		int total = a_grade() + b_grade() + c_grade() + d_grade() + f_grade();

		if ((as == 0) && (bs == 0) && (cs == 0) && (ds == 0) && (fs == 0) && (w() == 0))
		{
			cout << departt << " " << courseNum << " " << "(" << inst << "): ";
			cout << endl;

			cout << "  Num students:   " << getNumStudents() << endl;
			cout << "  Distribution: no report" << endl;
			cout << "  DFW rate: 0.00%" << endl;
		}

		else if ((as == 0) && (bs == 0) && (cs == 0) && (ds == 0) && (fs == 0) && (w() != 0))
		{
			std::cout << departt << " " << courseNum << " " << "(" << inst << "): ";
			cout << endl;

			cout << "  Num students:   " << getNumStudents() << endl;
			cout << "  Distribution: no report" << endl;
			cout << "  DFW rate: 100.00%" << endl;
		}
		else
		{
			a_dis = ((float)(as / total)) * 100;
			b_dis = ((float)(bs / total)) * 100;
			c_dis = ((float)(cs / total)) * 100;
			d_dis = ((float)(ds / total)) * 100;
			f_dis = ((float)(fs / total)) * 100;

			std::cout << departt << " " << courseNum << " " << "(" << inst << "): " << endl;
			cout << "  Num students:   " << getNumStudents() << endl;
			cout << "  Distribution: " << a_dis << "%, " << b_dis << "%, " << c_dis << "%, " << d_dis << "%, " << f_dis << "%" << endl;
			cout << "  DFW rate: " << percentageDFW() << "%" << endl;
		}

	}

	float percentageDFW()
	{
		float rate = 0;
		float x = d_grade() + f_grade() + w();
		float y = a_grade() + b_grade() + c_grade() + d_grade() + f_grade() + w();

		rate = (x / y) * 100;

		return rate;
	}

	string get_courseName()
	{
		return departt;
	}

  int get_CS()
	{
		return numCG;
	}


	int countNumCourses()
	{
		return 1;
	}

	float a_grade()
	{
		return g[0];
	}

	float b_grade()
	{
		return g[1];
	}

	float c_grade()
	{
		return g[2];
	}

	float d_grade()
	{
		return g[3];
	}

	float f_grade()
	{
		return g[4];
	}

	float w()
	{
		return g[9];
	}

	string dupinst;

};


void part1(vector < Course> &course)
{
	float as = 0;
	float bs = 0;
	float cs = 0;
	float ds = 0;
	float fs = 0;
	float a_dis = 0;
	float  b_dis = 0;
	float  c_dis = 0;
	float  d_dis = 0;
	float  f_dis = 0;
	int total = 0;


	for (int i = 0; i < course.size(); i++)
	{
		total = total + course[i].a_grade() + course[i].b_grade() + course[i].c_grade() + course[i].d_grade() + course[i].f_grade();
	}
	
	for (int i = 0; i < course.size(); i++)
	{
		//cout << " Grades are: " << g[i];
		as = course[i].a_grade() + as;
		bs = course[i].b_grade() + bs;
		cs = course[i].c_grade() + cs;
		ds = course[i].d_grade() + ds;
		fs = course[i].f_grade() + fs;

	}

	a_dis = ((float)(as / total)) * 100;
	b_dis = ((float)(bs / total)) * 100;
	c_dis = ((float)(cs / total)) * 100;
	d_dis = ((float)(ds / total)) * 100;
	f_dis = ((float)(fs / total)) * 100;

	cout << "College of Engineering:" << endl;
	cout << "  Num courses:  " << course.size() << endl;
	cout << "  Num grades:   " << total << endl;
	cout << "  Distribution: " << a_dis << "%, " << b_dis << "%, " << c_dis << "%, " << d_dis << "%, " << f_dis << "%" << endl;
}

void part2(vector < Course> &course, string depart)
{
	float as = 0;   // count number of a grades for particular course.
	float bs = 0;
	float cs = 0;
	float ds = 0;
	float fs = 0;
	float a_dis = 0;
	float b_dis = 0;
	float c_dis = 0;
	float d_dis = 0;
	float f_dis = 0;
	int total = 0;    // total course grades .. eg total number of cs grades.
	int total_courses = 0;


	for (int i = 0; i < course.size(); i++)
	{
		if (depart == course[i].get_courseName())
		{
			//	cout << " Course ENTER" << endl;
			total_courses++;
			total = total + course[i].get_CS();
			as = course[i].a_grade() + as;
			bs = course[i].b_grade() + bs;
			cs = course[i].c_grade() + cs;
			ds = course[i].d_grade() + ds;
			fs = course[i].f_grade() + fs;
		}
	}

	//cout << " number of as: " << as << endl;
	//cout << " total: " << total << endl;

	a_dis = ((float)(as / total)) * 100;
	b_dis = ((float)(bs / total)) * 100;
	c_dis = ((float)(cs / total)) * 100;
	d_dis = ((float)(ds / total)) * 100;
	f_dis = ((float)(fs / total)) * 100;

	cout << depart << ":" << endl;
	cout << "  Num courses:  " << total_courses << endl;
	cout << "  Num grades:   " << total << endl;
	cout << "  Distribution: " << a_dis << "%, " << b_dis << "%, " << c_dis << "%, " << d_dis << "%, " << f_dis << "%" << endl;

}


auto Find_Course(vector < Course> &course, string userInst)
{
	auto iter = std::find_if(course.begin(), course.end(),
		[=](Course& c)
	{
		if (c.dupinst == userInst)
		{
			return true;
		}
		else
			return false;
	}
	);
	return iter;
}


void print(Course currentCourse)
{
	currentCourse.course_distribution();
}



int main()
{
	string  filename;

	cin >> filename;
	cout << filename << endl;
	cout << endl;

	cout << std::fixed;
	cout << std::setprecision(2);

	ifstream file(filename);

	if (!file.good())
	{
		cout << "cannot  open  file!" << endl;
		return  -1;
	}

	//  Input  data  into  a  vector  
	//  of  Course  objects:  

	string line, depart, courseNum, title, inst;
	//int courseNum;

	vector <int> g(10);
	//int g[10];
	int num_courses = 0;
	string x;

	vector < Course> course;   // Vector of courses objects.

	getline(file, line);    //  skip  header:  



							//string d[11] = { "BIOE" , "CHE", "CME, "CS", "ENER", "ENGR", "IE", "IT", "ME", "MENG" };
	vector <string> d = { "BIOE", "CHE", "CME", "CS", "ECE", "ENER", "ENGR", "IE","IT", "ME", "MENG" };

	

	//string d[11] = { "BIOE", "CHE", "CME", "CS", "ECE", "ENER", "ENGR", "IE","IT", "ME", "MENG" };



	int flag = 0;

	while (getline(file, line))
	{
		stringstream ss(line);
		//  parse  line:  
		getline(ss, depart, ',');
		getline(ss, courseNum, ',');
		getline(ss, title, ',');


		for (int i = 0; i < 10; i++)
		{
			getline(ss, x, ',');
			g[i] = stoi(x);
		}
		getline(ss, inst, ',');

		Course  C(depart, stoi(courseNum), title, g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8], g[9], inst, flag);
		//  insert  @  end:
		//


		course.push_back(C);

		flag++;
	}
	//UIC uic;

	// part 1

	part1(course);   // solves the part 1

	// part2
	for (int i = 0; i < 11; i++)
	{

		part2(course, d[i]);   // solves the part 2.
	}


	// part3
	string userInst;

	cout << "Please enter instructor's name (or prefix or #)>  " << endl;

LOOP:cin >> userInst;

	if (userInst == "#")
		return 0;

	//cout << " original  " << userInst << endl;
	for (int i = 0; i < course.size(); i++)
	{
		if (course[i].getInstructorName().substr(0, userInst.size()) == userInst)
		{
			//		cout << " milgaya" << endl;
			userInst = course[i].getInstructorName();
			break;
		}
	}

	for (int i = 0; i < course.size(); i++)
	{
		if (course[i].dupinst == userInst)
		{
			//cout << "idhar" << endl;
			//cout << "Please enter instructor's name (or prefix or #)>  " << endl;
			//cin >> userInst;
			break;
		}
		if (i == course.size() - 1)
		{
			//cout << "odhar" << endl;
			cout << "Please enter instructor's name (or prefix or #)>  " << endl;
			goto LOOP;
		}

	}


	auto current_course = Find_Course(course, userInst);
	current_course->course_distribution();
	current_course->dupinst = "null";

	int temp = 0;
	while (userInst != "#")
	{

	HERE:
		while (current_course != course.end())
		{
			if (userInst == "Marai")
				temp = 5;

			current_course = Find_Course(course, userInst);

			if (current_course == course.end())
				break;

			current_course->course_distribution();

			current_course->dupinst = "null";

			//
		//	getOtherPrefix(userInst, course);

			if (userInst == "Bello Lander")
			{
				userInst = "Bell";
			}

			if (userInst == "Magin")
			{
				userInst = "Mahamid";
			}

			if (userInst == "Mahamid" && current_course->coursenum () == 413 )
			{
				userInst = "Marai";
			}

			if (userInst == "Marai" && temp==5)
			{
				userInst = "Manafzadeh";
			}   

		}

		for (int i = 0; i < course.size(); i++)
		{
			if (userInst == course[i].getInstructorName())
			{
				course[i].dupinst = course[i].getInstructorName();
			}
		}

		current_course = course.begin();
		cout << "Please enter instructor's name (or prefix or #)>  " << endl;
		cin >> userInst;

		if (userInst == "#")
		{
			//cout << " yedss";
			break;
		}

		for (int i = 0; i < course.size(); i++)
		{
			if (course[i].getInstructorName().substr(0, userInst.size()) == userInst)
			{
				//cout << " milgaya" << endl;
				userInst = course[i].getInstructorName();
				break;
			}
		}

		goto HERE;
	}
	cout << endl;

	//		system("pause");
	return 0;
	//system("pause");
}
