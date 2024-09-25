#ifndef CLOSEH_H
#define CLOSEH_H

typedef struct{
	int studID;
	char studName[16];
	char program[16];
	bool sex; //t-male f-female
	int level;
}Student;


typedef struct{
	Student *data;
	int count;
	int max;
}StudDictionary;

int hash(Student s, int max);
void init(StudDictionary *sd, int max);
bool insert(StudDictionary *sd, Student s);
bool removeStudent(StudDictionary *sd, Student s);
void get(StudDictionary *sd, int studentID);
void visualize(StudDictionary sd);

//make
Student makeStud(int ID, char name[16], char prog[16], bool sex, int lvl);

#endif
