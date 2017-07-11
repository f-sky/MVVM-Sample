#pragma once
#include<ui_Vcode.h>
#include <Common\Common.h>
#include <QtWidgets/QMainWindow>

class View : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	View(QWidget *parent = Q_NULLPTR);

	void setLoadPictureCommand(shared_ptr<BaseCommand> p) {
		loadPictureCommand = p;
	}
	void setImg(shared_ptr<QImage> p) {
		pImg = p;
	}
private:
	Ui::ViewClass ui;
	QString filename;
	QGraphicsScene* originScene;

	shared_ptr<BaseCommand> loadPictureCommand;
	shared_ptr<QImage> pImg;
	void update(const string& attribute);
	virtual void commandSucceed(bool flag);


private slots:

	void importPicture();
};
