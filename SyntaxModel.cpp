//
// Created by marcin on 09.04.16.
//

#include "SyntaxModel.h"

QString &SyntaxModel::getKey() {
    return key;
}

QString &SyntaxModel::getValue() {
    return value;
}

SyntaxModel::SyntaxModel(QString &key, QString &value) {
    this->key = QString(key);
    this->value = QString(value);
}

SyntaxModel::SyntaxModel(const char *key, const char *value) {
    this->key = QString::fromUtf8(key);
    this->value = QString::fromUtf8(value);
}






