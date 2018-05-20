#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include "QString"

class Data;

class View : public QWidget
{
    Q_OBJECT
public:
    View(int x, int y, int width, int heigth, QString title);
    virtual ~View();
    QString getTitle();
    virtual QString getData() = 0;

private:
    void setupUI();

protected:
    virtual void changed() = 0;

private:
    int x;
    int y;
    int height;
    int width;
    QString title;

signals:

public slots:
};

#endif // VIEW_H
