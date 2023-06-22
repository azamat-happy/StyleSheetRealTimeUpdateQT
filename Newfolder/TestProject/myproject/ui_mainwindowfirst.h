/********************************************************************************
** Form generated from reading UI file 'mainwindowfirst.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWFIRST_H
#define UI_MAINWINDOWFIRST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowFirst
{
public:
    QAction *actionChooseTheme;
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QRadioButton *radioButton;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowFirst)
    {
        if (MainWindowFirst->objectName().isEmpty())
            MainWindowFirst->setObjectName("MainWindowFirst");
        MainWindowFirst->resize(800, 600);
        actionChooseTheme = new QAction(MainWindowFirst);
        actionChooseTheme->setObjectName("actionChooseTheme");
        centralwidget = new QWidget(MainWindowFirst);
        centralwidget->setObjectName("centralwidget");
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 0, 431, 461));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(formLayoutWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 427, 457));
        scrollArea->setWidget(scrollAreaWidgetContents);

        formLayout->setWidget(0, QFormLayout::SpanningRole, scrollArea);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(450, 10, 121, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(590, 10, 131, 41));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(460, 70, 111, 31));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(600, 60, 131, 41));
        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(450, 140, 221, 61));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(440, 230, 161, 51));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(460, 110, 181, 31));
        MainWindowFirst->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowFirst);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        MainWindowFirst->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowFirst);
        statusbar->setObjectName("statusbar");
        MainWindowFirst->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menu->menuAction());
        menu->addAction(actionChooseTheme);

        retranslateUi(MainWindowFirst);

        QMetaObject::connectSlotsByName(MainWindowFirst);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowFirst)
    {
        MainWindowFirst->setWindowTitle(QCoreApplication::translate("MainWindowFirst", "MainWindow", nullptr));
        actionChooseTheme->setText(QCoreApplication::translate("MainWindowFirst", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\202\320\265\320\274\321\203", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowFirst", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindowFirst", "PushButton", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindowFirst", "RadioButton", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindowFirst", "CheckBox", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindowFirst", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindowFirst", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowFirst: public Ui_MainWindowFirst {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWFIRST_H
