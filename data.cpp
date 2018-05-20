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
    allView[viewCnt] = view;
}

void Data::setVisible(QString view, bool visible)
{
    for(int i = 0; i < MaxView ;i++){
        if(allView[i]->getTitle().compare(view) == 0){
            allView[i]->setVisible(visible);
        }
    }
}


void Data::ipSet()
{
}
