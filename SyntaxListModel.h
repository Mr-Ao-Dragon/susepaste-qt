//
// Created by marcin on 09.04.16.
//

#ifndef SUSEPASTE_QT_SYNTAXLISTMODEL_H
#define SUSEPASTE_QT_SYNTAXLISTMODEL_H

#include <QtCore/QList>
#include "SyntaxModel.h"

class SyntaxListModel {
public:
    static QList<SyntaxModel> getSyntaxList();
};


#endif //SUSEPASTE_QT_SYNTAXLISTMODEL_H
