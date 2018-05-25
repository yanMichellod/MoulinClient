#include "data.h"
#include "serverconnection.h"
#include "View/view.h"

#define MaxView 4
#define MaxPosition 24

Data::Data()
{
    allView = new View*[MaxView];
    for( int i = 0 ; i < MaxView ; i++)
    {
        allView[i] = nullptr;
    }
    viewCnt = 0;
    player = 0;
    tocken = new int[MaxPosition];
}

Data::~Data()
{

}

void Data::subscribe(View *view)
{
    if ( viewCnt < MaxView){
        allView[viewCnt] = view;
        viewCnt ++;
    }
}

void Data::setVisible(QString view, bool visible)
{
    for(int i = 0; i < viewCnt ;i++){
        if(allView[i]->getTitle().compare(view) == 0){
            allView[i]->setVisible(visible);
        }
    }
}

void Data::enableWindow(QString view, bool enable)
{
    for(int i = 0; i < viewCnt ;i++){
        if(allView[i]->getTitle().compare(view) == 0){
            allView[i]->setEnabled(enable);
        }
    }
}

View *Data::getView(QString title)
{
    View* retview = nullptr;
    for(int i = 0; i < viewCnt ;i++){
        if(allView[i]->getTitle().compare(title) == 0){
            retview = allView[i];
        }
    }
    return retview;
}

void Data::setPlayer(int number)
{
    player = number;
}

int Data::getPlayer()
{
    return player;
}

void Data::setMoulin(bool val)
{
    moulin = val;
}

bool Data::isMoulin()
{
    return moulin;
}


void Data::ipSet()
{
    emit ipEntered();
}

void Data::commandEntered()
{
    emit commandToSend();
}
