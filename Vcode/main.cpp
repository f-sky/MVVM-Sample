#include<View/View.h>
#include <QtWidgets/QApplication>
#include<ViewModel\ViewModel.h>
#include<Model/Model.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	shared_ptr<View> pv(new View);
	shared_ptr<Model> pm(new Model);
	shared_ptr<ViewModel> pvm(new ViewModel());
	pvm->setModel(pm);
	//bind
	pv->setLoadPictureCommand(pvm->getLoadPictureCommand());
	pv->setImg(pvm->getpImg());
	//observer
	pm->addObserver(static_pointer_cast<Observer, ViewModel>(pvm));
	pvm->addObserver(static_pointer_cast<Observer, View>(pv));

	pv->show();
	return a.exec();
}
