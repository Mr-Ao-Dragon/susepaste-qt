//
// Created by marcin on 09.04.16.
//

#ifndef SUSEPASTE_QT_MAINWINDOW_H
#define SUSEPASTE_QT_MAINWINDOW_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>

class MainWindow : public QWidget
{
Q_OBJECT
public:
    void init();
    void setFilePath(QString &file);

protected:
    QLineEdit *txtFilePath = NULL;
    QLineEdit *txtNick     = NULL;
    QLineEdit *txtTitle    = NULL;
    QLineEdit *txtApiKey   = NULL;

    QComboBox   *cmbExpire = NULL;
    QComboBox   *cmbSyntax = NULL;
private slots:
    void handleButton();
    void handleBtnFileDialog();
};


#endif //SUSEPASTE_QT_MAINWINDOW_H
