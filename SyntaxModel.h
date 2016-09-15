//
// Created by marcin on 09.04.16.
//

#ifndef SUSEPASTE_QT_SYNTAXMODEL_H
#define SUSEPASTE_QT_SYNTAXMODEL_H


#include <QtCore/QString>

class SyntaxModel
{
public:
    SyntaxModel(QString &key, QString &value);
    SyntaxModel(const char *key, const char *value);
    QString &getKey();
    QString &getValue();

protected:
    QString key;
    QString value;
};


#endif //SUSEPASTE_QT_SYNTAXMODEL_H
