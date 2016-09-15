//
// Created by marcin on 08.04.16.
//

#include "ExpireModel.h"

int ExpireModel::getKey() {
    return key;
}

QString ExpireModel::getValue() {
    return value;
}

ExpireModel::ExpireModel(int key, QString value) {
    this->key = key;
    this->value = QString(value);
}





