#include "mainwindow.h"

#include <QtAdvancedStylesheet.h>

#include "ui_mainwindow.h"
#include <QDir>
#include <QApplication>
#include <QAction>
#include <QListWidgetItem>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QColorDialog>
#include <QDebug>
#include <QQmlEngine>
#include <QQmlContext>
#include <iostream>
#include <QMessageBox>
#include <QWidget>
#include <QSettings>
#include <QTreeWidget>
#define _STR(x) #x
#define STRINGIFY(x)  _STR(x)
#ifndef STYLES_DIR
#define STYLES_DIR C:/Users/azama/Documents/Newfolder/TestProject/styles
#endif
/**
 * Private data class - pimpl
 */
struct MainWindowPrivate
{
    CMainWindow* _this;
    Ui::MainWindow ui;
    acss::QtAdvancedStylesheet* AdvancedStyleSheet;
    QVector<QPushButton*> ThemeColorButtons;
    QTreeView* treeView;
    /**
     * Private data constructor
     */
    MainWindowPrivate(CMainWindow* _public) : _this(_public) {}

    void createThemeColorDockWidget();
    void fillThemeMenu();
    void setSomeIcons();
    void setupQuickWidget();
    void updateThemeColorButtons();
    void updateQuickWidget();
    void addThemeButtons();
    void createFillTree();
    /**
     * Loads theme aware icons for the actions in the toolbar
     */
    void loadThemeAwareToolbarActionIcons();
};

//отвечает за всплывающую компоненту с кнопками!
void MainWindowPrivate::createThemeColorDockWidget()
{

    QDockWidget* dock = new QDockWidget(_this);
    QWidget* w = new QWidget(dock);
    auto Layout = new QVBoxLayout(w);
    Layout->setContentsMargins(12, 12, 12, 12);
    Layout->setSpacing(12);
    w->setLayout(Layout);
    dock->setWidget(w);
    dock->setFeatures(QDockWidget::NoDockWidgetFeatures); // Убираем возможность закрытия и расширения
     dock->setTitleBarWidget(new QWidget()); // Устанавливаем пустой виджет в качестве заголовка
    _this->addDockWidget(Qt::LeftDockWidgetArea, dock);
//    dock->setFloating(true);
    dock->setFixedWidth(200); // Укажите нужную ширину

    const auto& ThemeColors = AdvancedStyleSheet->themeColorVariables();
    for (auto itc = ThemeColors.constBegin(); itc != ThemeColors.constEnd(); ++itc)
    {
        auto Button = new QPushButton(itc.key());
        QObject::connect(Button, &QPushButton::clicked, _this, &CMainWindow::onThemeColorButtonClicked);
        Layout->addWidget(Button);
        ThemeColorButtons.append(Button);
    }

    updateThemeColorButtons();
}
void MainWindowPrivate::createFillTree()
{
    // Создаем объект дерева
    QTreeWidget* treeWidget = new QTreeWidget(_this);
    treeWidget->setColumnCount(1); // Устанавливаем количество столбцов в дереве

    // Создаем заголовки столбцов
    QStringList headers;
    headers << "Item";
    treeWidget->setHeaderLabels(headers);

    // Создаем корневой элемент дерева
    QTreeWidgetItem* rootItem = new QTreeWidgetItem(treeWidget);
    rootItem->setText(0, "Root");
//    rootItem->setText(1, "Root item description");

    // Создаем дочерние элементы для корневого элемента
    for (int i = 1; i <= 10; ++i)
    {
        QTreeWidgetItem* childItem = new QTreeWidgetItem(rootItem);
        childItem->setText(0, QString("Child %1").arg(i));
//        childItem->setText(1, QString("Child item %1 description").arg(i));

        // Создаем дочерние элементы для каждого дочернего элемента
        for (int j = 1; j <= 5; ++j)
        {
            QTreeWidgetItem* subChildItem = new QTreeWidgetItem(childItem);
            subChildItem->setText(0, QString("Subchild %1-%2").arg(i).arg(j));
//            subChildItem->setText(1, QString("Subchild item %1-%2 description").arg(i).arg(j));

            // Создаем дочерние элементы для каждого поддочернего элемента
            for (int k = 1; k <= 2; ++k)
            {
                QTreeWidgetItem* subSubChildItem = new QTreeWidgetItem(subChildItem);
                subSubChildItem->setText(0, QString("Subsubchild %1-%2-%3").arg(i).arg(j).arg(k));
//                subSubChildItem->setText(1, QString("Subsubchild item %1-%2-%3 description").arg(i).arg(j).arg(k));
            }
        }
    }

    // Добавляем дерево в главное окно
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(treeWidget);
    _this->centralWidget()->setLayout(layout);
}


void MainWindowPrivate::updateThemeColorButtons()
{
    for (auto Button : ThemeColorButtons)
    {
        auto Color = AdvancedStyleSheet->themeColor(Button->text());
        QString TextColor = (Color.value() < 128) ? "#ffffff" : "#000000";
        QString ButtonStylesheet = QString("background-color: %1; color: %2;"
                                           "border: none;").arg(Color.name()).arg(TextColor);
        Button->setStyleSheet(ButtonStylesheet);
    }
}


void MainWindowPrivate::updateQuickWidget()
{
//        const auto Source = ui.quickWidget->source();
//        ui.quickWidget->setSource({});
//        ui.quickWidget->engine()->clearComponentCache();
//        ui.quickWidget->setSource(Source);
//        ui.quickWidget->setStyleSheet(AdvancedStyleSheet->styleSheet());
}

void MainWindowPrivate::addThemeButtons()
{
    const auto& themes = AdvancedStyleSheet->themes();

    QGridLayout* gridLayout = new QGridLayout;

    int columnCount = 9; // Количество столбцов в таблице
    int row = 0;
    int column = 0;

    // Массивы цветов для первого и второго цветов градиента
    QStringList firstColors = { "#333333", "#DCDCDC" }; // Темносерый цвет
    QStringList secondColors = { "#ffd740", "#448aff", "#4dd0e1", "#8bc34a", "#ff4081", "#ab47bc", "#ff1744", "#1de9b6", "#ffff00" }; // Светлосерые цвета

    for (int i = 0; i < themes.size(); i++)
    {
        QPushButton* button = new QPushButton(themes[i]);
        QObject::connect(button, &QPushButton::clicked, _this, &CMainWindow::onThemeButtonClicked);

        // Определение цветов градиента в зависимости от названия темы
        QString firstColor;
        QString secondColor;

        if (themes[i].startsWith('d', Qt::CaseInsensitive)) {
            firstColor = firstColors[0]; // "#333333" для тем, начинающихся с 'd'
        } else if (themes[i].startsWith('l', Qt::CaseInsensitive)) {
            firstColor = firstColors[1]; // "#DCDCDC" для тем, начинающихся с 'l'
        }

        secondColor = secondColors[i % secondColors.size()]; // Выбор цвета из массива secondColors

        // Настроить стиль кнопки с градиентным фоном
        QString buttonStyle = QString("QPushButton {"
                                      "    width: 10px;"
                                      "    height: 20px;"
                                      "    border: none;" // Убираем границы кнопки
                                      "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 %1, stop:1 %2);"
                                       "    color: transparent;"
                                      "}").arg(firstColor).arg(secondColor);
        button->setStyleSheet(buttonStyle);

        gridLayout->addWidget(button, row, column);

        column++;
        if (column >= columnCount)
        {
            column = 0;
            row++;
        }
    }

    // Присоединение GridLayout к виджету
    QWidget* widget = new QWidget;
    widget->setLayout(gridLayout);
    ui.scrollArea->setWidget(widget);
}


//тот  самый метод, который устаналивает список из готовых тем
void MainWindowPrivate::fillThemeMenu()
{
//    // Add actions for theme selection
//    auto m = ui.menuThemes;
//    for (const auto& Theme : AdvancedStyleSheet->themes())
//    {
//        QAction* a = new QAction(Theme);
//        m->addAction(a);
//        QObject::connect(a, &QAction::triggered, _this, &CMainWindow::onThemeActionTriggered);
//    }

}

//устанавливает иконки
void MainWindowPrivate::setSomeIcons()
{
    //    ui.actionToolbar->setIcon(AdvancedStyleSheet->styleIcon());
    //    QIcon Icon(":/full_features/images/logo_frame.svg");
    //    for (int i = 0; i < ui.listWidget_2->count(); ++i)
    //    {
    //    	ui.listWidget_2->item(i)->setIcon(Icon);
    //    }
}

void MainWindowPrivate::setupQuickWidget()
{
    //    QQmlEngine* engine = ui.quickWidget->engine();
    //    QQmlContext* context = engine->rootContext();

    //    QScopedPointer<acss::CQmlStyleUrlInterceptor> urlInterceptor(new acss::CQmlStyleUrlInterceptor(AdvancedStyleSheet));
    //    QVariant styleInterceptorVariant = QVariant::fromValue(urlInterceptor.data());
    //    context->setContextProperty("styleUrlInterceptor", styleInterceptorVariant);

    //    ui.quickWidget->setStyleSheet(AdvancedStyleSheet->styleSheet());
    //    //    ui.quickWidget->setSource(QUrl("qrc:/full_features/qml/simple_demo.qml"));
    //    ui.quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    //    ui.quickWidget->setAttribute(Qt::WA_TranslucentBackground);
    //    ui.quickWidget->setClearColor(Qt::transparent);
}

void MainWindowPrivate::loadThemeAwareToolbarActionIcons()
{
    //	ui.actionSelected->setIcon(AdvancedStyleSheet->loadThemeAwareSvgIcon(":/full_features/images/edit.svg"));
    //	ui.actionaction->setIcon(AdvancedStyleSheet->loadThemeAwareSvgIcon(":/full_features/images/folder_open.svg"));
    //	ui.actionaction2->setIcon(AdvancedStyleSheet->loadThemeAwareSvgIcon(":/full_features/images/save.svg"));
    //	ui.actionaction3->setIcon(AdvancedStyleSheet->loadThemeAwareSvgIcon(":/full_features/images/help_outline.svg"));
}


CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent),
    d(new MainWindowPrivate(this))
{
    d->ui.setupUi(this);
    QDir::setCurrent(QCoreApplication::applicationDirPath()); // Установка текущего рабочего каталога
    QString AppDir = qApp->applicationDirPath();
    QString StylesDir = STRINGIFY(STYLES_DIR);
    QMessageBox::information(nullptr, "Paths", "AppDir: \"" + AppDir + "\"\nStylesDir: \"" + StylesDir + "\"");

    d->AdvancedStyleSheet = new acss::QtAdvancedStylesheet(this);
    d->AdvancedStyleSheet->setStylesDirPath(StylesDir);
    d->AdvancedStyleSheet->setOutputDirPath(AppDir + "/output");
    d->AdvancedStyleSheet->setCurrentStyle("qt_material");
    d->AdvancedStyleSheet->setDefaultTheme();
    d->AdvancedStyleSheet->updateStylesheet();
    setWindowIcon(d->AdvancedStyleSheet->styleIcon());
    qApp->setStyleSheet(d->AdvancedStyleSheet->styleSheet());
    connect(d->AdvancedStyleSheet, SIGNAL(stylesheetChanged()), this,
            SLOT(onStyleManagerStylesheetChanged()));

    d->createThemeColorDockWidget();
    d->fillThemeMenu();
    d->setSomeIcons();
    d->setupQuickWidget();
    d->loadThemeAwareToolbarActionIcons();
    d->addThemeButtons();
    connectThemeActions();

    // Загрузка сохраненной темы
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    QString savedTheme = settings.value("theme").toString();
    if (!savedTheme.isEmpty()) {
        d->AdvancedStyleSheet->setCurrentTheme(savedTheme);
        d->AdvancedStyleSheet->updateStylesheet();
    }
    d->createFillTree();
}

CMainWindow::~CMainWindow()
{
    delete d;
}

//изменение темы из верхнего меню
void CMainWindow::onThemeActionTriggered()
{
    auto Action = qobject_cast<QAction*>(sender());
    d->AdvancedStyleSheet->setCurrentTheme(Action->text());
    d->AdvancedStyleSheet->updateStylesheet();
}
// Определение слота
void CMainWindow::onThemeButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        QString theme = button->text();

        // Сохранение выбранной темы
        QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
        settings.setValue("theme", theme);
        settings.sync();

        // Обработка выбора темы
        d->AdvancedStyleSheet->setCurrentTheme(theme);
        d->AdvancedStyleSheet->updateStylesheet();
    }
}

void CMainWindow::connectThemeActions()
{
//    const auto& themes = d->AdvancedStyleSheet->themes();
//    for (const auto& theme : themes)
//    {
//        QAction* action = d->ui.menuThemes->addAction(theme);
//        connect(action, &QAction::triggered, this, &CMainWindow::onThemeActionTriggered);
//    }
}
void CMainWindow::onStyleManagerStylesheetChanged()
{
    qApp->setStyleSheet(d->AdvancedStyleSheet->styleSheet());
    d->updateThemeColorButtons();
    d->updateQuickWidget();
}

//нажатие на кнопки выбора темы во всплывающем меню
void CMainWindow::onThemeColorButtonClicked()
{
    auto Button = qobject_cast<QPushButton*>(sender());
    QColorDialog ColorDialog;
    auto Color = d->AdvancedStyleSheet->themeColor(Button->text());
    ColorDialog.setCurrentColor(Color);
    if (ColorDialog.exec() != QDialog::Accepted)
    {
        return;
    }
    Color = ColorDialog.currentColor();
    d->AdvancedStyleSheet->setThemeVariableValue(Button->text(), Color.name());
    d->AdvancedStyleSheet->updateStylesheet();
}