#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsBlurEffect>
#include <QGraphicsOpacityEffect>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void showLoginForm();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Widget *ui;
    QWidget *blurOverlay;
    void setInterfaceStyle();
};

#endif // WIDGET_H
