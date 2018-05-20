#include "data.h"
#include "serverconnection.h"
#include "View/view.h"

#define MaxView 3

Data::Data()
{
    allView = new View*[MaxView];
    for( int i = 0 ; i < MaxView ; i++)
    {
        allView[i] = nullptr;
    }
    viewCnt = 0;
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

View *Data::getView(QString view)
{
    View* retview = nullptr;
    for(int i = 0; i < viewCnt ;i++){
        if(allView[i]->getTitle().compare(view) == 0){
            retview = allView[i];
        }
    }
    return retview;
}


void Data::ipSet()
{
}
