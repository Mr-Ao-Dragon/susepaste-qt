//
// Created by marcin on 08.04.16.
//

#ifndef SUSEPASTE_QT_EXPIREMODEL_H
#define SUSEPASTE_QT_EXPIREMODEL_H


#include <QtCore/QString>

class ExpireModel
{

public:
    ExpireModel(int key, QString value);
    int getKey();
    QString getValue();

protected:
    int key;
    QString value;
};


#endif //SUSEPASTE_QT_EXPIREMODEL_H
