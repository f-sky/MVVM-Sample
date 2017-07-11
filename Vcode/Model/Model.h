#pragma once
#include<Common\Common.h>
#include<opencv2\opencv.hpp>
#include<qdebug.h>
#include<fstream>

class Model :public Observable
{
protected:
	cv::Mat m;
public:
	Model() {}
	~Model() {}

	cv::Mat& getMat() { return m; }

	void loadPicture(const string& path) {
		m = cv::imread(path,1);
		if (m.empty()) {
			this->notify(false);
		}
		else {
			string s = "image";
			this->notify(s);
		}
	}
};