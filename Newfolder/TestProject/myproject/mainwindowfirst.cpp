#include "mainwindowfirst.h"
#include "ui_mainwindowfirst.h"
#include "mainwindow.h" // Добавленный include

#include <QTreeWidget>
#include <QVBoxLayout>
#include <QSettings>

MainWindowFirst::MainWindowFirst(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFirst)
{
    ui->setupUi(this);
    loadSavedTheme();
    // Загрузка сохраненной темы
//    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
//    QString savedTheme = settings.value("theme").toString();
//    if (!savedTheme.isEmpty()) {
//        d->AdvancedStyleSheet->setCurrentTheme(savedTheme);
//        d->AdvancedStyleSheet->updateStylesheet();
//    }

    createFillTree();

    // Подключение сигнала triggered() к слоту openCMainWindow()
    connect(ui->actionChooseTheme, &QAction::triggered, this, &MainWindowFirst::openCMainWindow);

}

MainWindowFirst::~MainWindowFirst()
{
    delete ui;
}

#include <QScrollArea>

void MainWindowFirst::createFillTree()
{
    // Создаем объект дерева
    QTreeWidget* treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(1); // Устанавливаем количество столбцов в дереве

    // Создаем заголовки столбцов
    QStringList headers;
    headers << "Просто какое-то дерево";
    treeWidget->setHeaderLabels(headers);

    // Создаем корневой элемент дерева
    QTreeWidgetItem* rootItem = new QTreeWidgetItem(treeWidget);
    rootItem->setText(0, "Root");

    // Создаем дочерние элементы для корневого элемента
    for (int i = 1; i <= 10; ++i)
    {
        QTreeWidgetItem* childItem = new QTreeWidgetItem(rootItem);
        childItem->setText(0, QString("Child %1").arg(i));

        // Создаем дочерние элементы для каждого дочернего элемента
        for (int j = 1; j <= 5; ++j)
        {
            QTreeWidgetItem* subChildItem = new QTreeWidgetItem(childItem);
            subChildItem->setText(0, QString("Subchild %1-%2").arg(i).arg(j));

            // Создаем дочерние элементы для каждого поддочернего элемента
            for (int k = 1; k <= 2; ++k)
            {
                QTreeWidgetItem* subSubChildItem = new QTreeWidgetItem(subChildItem);
                subSubChildItem->setText(0, QString("Subsubchild %1-%2-%3").arg(i).arg(j).arg(k));
            }
        }
    }

    // Создаем виджет с прокруткой и устанавливаем в него дерево

    ui->scrollArea->setWidget(treeWidget);
    ui->scrollArea->setWidgetResizable(true);  // Позволяет изменять размер виджета внутри области прокрутки

    // Устанавливаем ограниченный размер для виджета с прокруткой
    ui->scrollArea->setFixedSize(400, 400);

    // Устанавливаем виджет с деревом в scrollArea
    ui->scrollArea->setWidget(treeWidget);
//    scrollArea->setWidgetResizable(true);

    // Обновляем отображение scrollArea
//    scrollArea->update();
}

void MainWindowFirst::openCMainWindow()
{
        CMainWindow* cMainWindow = new CMainWindow(this);
        cMainWindow->show();
}
void MainWindowFirst::loadSavedTheme()
{
    // Загрузка сохраненной темы
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    QString savedTheme = settings.value("theme").toString();
    if (!savedTheme.isEmpty()) {
        // Создание экземпляра CMainWindow
        CMainWindow* cMainWindow = new CMainWindow(this);
        // Установка сохраненной темы
        cMainWindow->setTheme(savedTheme);
    }
}
