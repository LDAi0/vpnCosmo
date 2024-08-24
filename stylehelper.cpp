#include "stylehelper.h"



QString stylehelper::getConnectBtnStyle()
{
    return "QPushButton{"
           "    background: none !important;"
        "border: none !important;"
    "border-radius: 25px !important;"
    "background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(80, 45, 174, 255), stop:1 rgba(158, 72, 214, 255)) !important;"
           "font: 14pt 'TitilliumWeb-Black';"
           "}"
    "QPushButton::hover{"
           "background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(120, 101, 174, 255), stop:0.994382 rgba(171, 105, 214, 255));"
           "}"
    "QPushButton::pressed{"
           "background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(48, 23, 115, 255), stop:0.994382 rgba(103, 35, 147, 255));"
           "}";
}



QString stylehelper::getWindowStyle()
{
    return "QWidget{"
            "background-color: rgb(22,22,22);"
           "}";
}

QString stylehelper::getSignInStyle()
{
    return "QPushButton{"
"           background-color: rgb(22,22,22)!important; "
           "border-width: 2px !important;"
"color: rgb(14, 204, 0);"
    "border-radius: 15px !important;"
    "border-color: rgb(14, 204, 0) !important;"
    "border-style: solid !important;"
    "font-size: 12pt;"
    "font-family: 'Titillium Web'"
"}"
"QPushButton::hover{"
    "background-color: rgb(14, 204, 0);"
"color: rgb(22, 22, 22);"
"}"
"QPushButton::pressed{"
    "border-color:rgb(11, 127, 0);"
    "background-color: rgb(11, 127, 0);"
"}";
}
