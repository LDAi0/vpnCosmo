#include "widget.h"
#include "ui_widget.h"
#include <stylehelper.h>
#include <QStyleOption.h>
#include <QFontDatabase>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setInterfaceStyle();
    int id  = QFontDatabase::addApplicationFont(":/fonts/TitilliumWeb-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    qDebug() << family;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void Widget::setInterfaceStyle()
{
    ui->pushButton->setStyleSheet(stylehelper::getConnectBtnStyle());
    this->setStyleSheet(stylehelper::getWindowStyle());
    ui->pushButton_2->setStyleSheet(stylehelper::getSignInStyle());
}
