#ifndef MAINWINDOWFIRST_H
#define MAINWINDOWFIRST_H

#include <QMainWindow>

namespace Ui {
class MainWindowFirst;
}

class MainWindowFirst : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowFirst(QWidget *parent = nullptr);
    ~MainWindowFirst();
    void createFillTree(); // Объявление функции createFillTree()

private:
    Ui::MainWindowFirst *ui;
};

#endif // MAINWINDOWFIRST_H
