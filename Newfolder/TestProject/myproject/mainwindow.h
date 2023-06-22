#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct MainWindowPrivate;

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    virtual ~CMainWindow();
    void setTheme(const QString& theme);
    QString setThemeFileName();
    QString primaryColor;
    QString primaryLightColor;
    QString secondaryColor;
    QString secondaryLightColor;
    QString secondaryDarkColor;
    QString primaryTextColor;
    QString secondaryTextColor;
    QString STYLES_DIR;
    bool isLightColor(const QString& color);
    bool checkThemeExists(const QString& themeName);
    void DeleteItem(const QString& themeName);

private:
    MainWindowPrivate* d;
    friend struct MainWindowPrivate;// pimpl

private slots:
    void onThemeActionTriggered();
    void onStyleManagerStylesheetChanged();
    void onThemeColorButtonClicked();
    void connectThemeActions();
    void onThemeButtonClicked();
    void onAddNewThemeClicked();
    void createColorThemeFile(const QString& fileName,
                              const QString& primaryColor,
                              const QString& primaryLightColor,
                              const QString& secondaryColor,
                              const QString& secondaryLightColor,
                              const QString& secondaryDarkColor,
                              const QString& primaryTextColor,
                              const QString& secondaryTextColor);




};
#endif // CMAINWINDOW_H
