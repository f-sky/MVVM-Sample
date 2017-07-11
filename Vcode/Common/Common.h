#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<memory>
#include<vector>

using namespace std;

class Param {

};

class BaseCommand {
public:
	virtual void setParams(const shared_ptr<Param>& p) = 0;
	virtual void exec() = 0;
};


class Observer
{
public:
	
	virtual void update(const string& attribute) = 0;
	virtual void commandSucceed(bool flag) = 0;
};

class Observable
{
private:

	vector<shared_ptr<Observer> >observerList;
public:
	void addObserver(shared_ptr<Observer> pobj) {
		observerList.push_back(pobj);
	}

	void notify(const string& attribute) {
		
		for (auto it = observerList.begin(), end = observerList.end(); it != end; it++) {
			(*it)->update(attribute);
		}
	}
	void notify(bool flag) {
		for (auto it = observerList.begin(), end = observerList.end(); it != end; it++) {
			(*it)->commandSucceed(flag);
		}
	}
};

class StringParam:public Param {
private:
	string path;
public:
	void setPath(string p) {
		path = p;
	}
	string getPath() {
		return path;
	}
};