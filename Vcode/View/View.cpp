#include <View\View.h>
#include <QFileDialog>
#include <QMessageBox>
#include <qdebug.h>


View::View(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.importPicAction->setShortcuts(QKeySequence::Open);
	ui.importPicAction->setStatusTip(tr("Import a picture of verification code"));

	originScene = new QGraphicsScene();
	ui.leftOriginView->setScene(originScene);
	ui.rightOriginView->setScene(originScene);
	connect(ui.importPicAction, &QAction::triggered, this, &View::importPicture);
	//connect(ui.recognizeButton, SIGNAL(clicked()), this, SLOT(recognizeCode()));
}
void View::importPicture() {

	filename = QFileDialog::getOpenFileName(this, "Select Picture", ".", tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));

	if (!filename.isEmpty()) {

		shared_ptr<StringParam> sp = make_shared<StringParam>();
		sp->setPath(filename.toStdString());

		loadPictureCommand->setParams(static_pointer_cast<Param, StringParam>(sp));

		loadPictureCommand->exec();

	}
}
void View::update(const string& attribute) {
	if (attribute == "image") {
		originScene->clear();
		originScene->addPixmap(QPixmap::fromImage(pImg->scaled(ui.leftOriginView->width(), ui.leftOriginView->height(), Qt::KeepAspectRatio)));
	}
}
void View::commandSucceed(bool flag) {
	if (!flag) {
		QMessageBox::critical(this, "Error", "Error!");
	}
}