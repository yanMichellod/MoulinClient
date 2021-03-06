#ifndef SETUPVIEW_H
#define SETUPVIEW_H
#include "View/view.h"
#include <QLineEdit>
#include <QLabel>
#include <QString>

class SetupView : public View
{
    Q_OBJECT
public:
    SetupView(int x, int y, int width, int heigth, QString title);
    ~SetupView();

private:
    void setupUI();

    QLineEdit* le;
    QLabel* ip;
    QLabel* port;

    QString data;

    // View interface
public:
    QString getData();

protected:
    void changed();

private slots:
    void onCommandEntered();

signals:
    void ipEntered();


};

#endif // SETUPVIEW_H
