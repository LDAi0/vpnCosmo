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
    connect(ui->pushButton_2,&QPushButton::clicked, this, &Widget::showLoginForm);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showLoginForm()
{
    // Создание полупрозрачного и размытого слоя
    QWidget *blurOverlay = new QWidget(this);
    blurOverlay->setGeometry(this->rect());  // Покрывает весь основной виджет
    blurOverlay->setStyleSheet("background-color: rgba(0, 0, 0, 128);");  // Полупрозрачный черный фон

    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect(this);
    blurEffect->setBlurRadius(10);
    blurOverlay->setGraphicsEffect(blurEffect);

    blurOverlay->show();  // Показать слой с размытием

    // Создание формы авторизации
    QWidget *loginForm = new QWidget(this);
    loginForm->setFixedSize(300, 200);  // Задаем фиксированный размер формы
    loginForm->setStyleSheet("background-color: #ffffff; border-radius: 15px;");

    // Центрирование формы
    int x = (this->width() - loginForm->width()) / 2;
    int y = (this->height() - loginForm->height()) / 2;
    loginForm->move(x, y);

    // Добавляем поля ввода и кнопку "Войти" в форму авторизации
    QLineEdit *username = new QLineEdit(loginForm);
    username->setPlaceholderText("Username");
    username->setGeometry(50, 50, 200, 30);

    QLineEdit *password = new QLineEdit(loginForm);
    password->setPlaceholderText("Password");
    password->setGeometry(50, 100, 200, 30);
    password->setEchoMode(QLineEdit::Password);

    QPushButton *submitButton = new QPushButton("Submit", loginForm);
    submitButton->setGeometry(100, 150, 100, 30);

    // Показываем форму авторизации
    loginForm->show();
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
