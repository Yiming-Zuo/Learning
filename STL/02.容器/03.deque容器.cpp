#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

#define NUM 10

class Student {
public:
	Student() {}
	Student(string name) {
		this->name = name;
	}
	void mark_score() {
		int grade;
		for (int i=0;i<NUM;i++) {
			grade = rand()%41+60;
			this->score.push_back(grade);
		}
	}
	void show_score() {
		cout << name << ":";
		for (deque<int>::const_iterator p=score.begin();p!=score.end();p++) {
			cout << (*p) << ' ';
		}
		cout << endl;
	}
	double get_avg() {
		int sum = 0;
		sort(score.begin(), score.end());
		score.pop_back();
		score.pop_front();
		for (deque<int>::const_iterator p=score.begin();p!=score.end();p++) {
			sum+=(*p);
		}
		avg = sum*1.0/score.size();	
		return avg;
	}
private:
	string name;
	deque<int>score;
	double avg;
};

vector<Student> create_team() {
	vector<Student>team;
	string studentseed = "ABCDEFGHLJKLMNOPQRSTUVWXYZ";
	for (int i=0;i<studentseed.size();i++) {
		string studentname = "选手";
		studentname+=studentseed[i];
		Student s(studentname);  // 随后被释放
		team.push_back(s);  // 将s对象push到容器中
	}
	return team;
}

void show_result(vector<Student> &team) {
	for (vector<Student>::iterator p=team.begin();p!=team.end();p++) {
		p->mark_score();
		p->show_score();
		cout << "平均分:"<< p->get_avg() << endl;
	}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	vector<Student>team = create_team();
	show_result(team);
	return 0;
}