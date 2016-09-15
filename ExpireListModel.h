//
// Created by marcin on 09.04.16.
//

#ifndef SUSEPASTE_QT_EXPIRELISTMODEL_H
#define SUSEPASTE_QT_EXPIRELISTMODEL_H


#include <QtCore/QList>
#include "ExpireModel.h"

class ExpireListModel
{
public:
    static QList<ExpireModel> getExpireList();
};


#endif //SUSEPASTE_QT_EXPIRELISTMODEL_H
