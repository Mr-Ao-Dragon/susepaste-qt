//
// Created by marcin on 09.04.16.
//

#include "ExpireListModel.h"

QList<ExpireModel> ExpireListModel::getExpireList()
{
    QList<ExpireModel> list = QList<ExpireModel>();

    ExpireModel expireModel1 = ExpireModel(30, "30 Minutes");
    ExpireModel expireModel2 = ExpireModel(60, "1 Hour");
    ExpireModel expireModel3 = ExpireModel(360, "6 Hours");
    ExpireModel expireModel4 = ExpireModel(720, "12 Hours");
    ExpireModel expireModel5 = ExpireModel(1440, "1 Day");
    ExpireModel expireModel6 = ExpireModel(10080, "1 Week");
    ExpireModel expireModel7 = ExpireModel(40320, "1 Month");
    ExpireModel expireModel8 = ExpireModel(151200, "3 Months");
    ExpireModel expireModel9 = ExpireModel(604800, "1 Year");
    ExpireModel expireModel10 = ExpireModel(1209600, "2 Years");
    ExpireModel expireModel11 = ExpireModel(1814400, "3 Years");
    ExpireModel expireModel12 = ExpireModel(0, "Never");

    list.append(expireModel1);
    list.append(expireModel2);
    list.append(expireModel3);
    list.append(expireModel4);
    list.append(expireModel5);
    list.append(expireModel6);
    list.append(expireModel7);
    list.append(expireModel8);
    list.append(expireModel9);
    list.append(expireModel10);
    list.append(expireModel11);
    list.append(expireModel12);

    return list;
}

