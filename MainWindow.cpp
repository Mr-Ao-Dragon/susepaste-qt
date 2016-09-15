//
// Created by marcin on 09.04.16.
//
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "MainWindow.h"
#include <unistd.h>
#include <pwd.h>
#include "ExpireModel.h"
#include "ExpireListModel.h"
#include "SyntaxModel.h"
#include "SyntaxListModel.h"

void MainWindow::init() {
    QList<ExpireModel> expireList = ExpireListModel::getExpireList();
    QList<SyntaxModel> syntaxList = SyntaxListModel::getSyntaxList();

    QFormLayout *layoutForm = new QFormLayout;
    QHBoxLayout *hLayoutFileChose = new QHBoxLayout;

    uid_t uid = geteuid();
    struct passwd *passwd1 = getpwuid(uid);

    cmbExpire = new QComboBox(this);
    cmbExpire->setToolTip("for how log will be paste stored on the server");

    cmbSyntax = new QComboBox(this);
    cmbSyntax->setToolTip("what kind of syntax highlighting should be used.");

    txtNick = new QLineEdit(this);
    txtNick->setToolTip("nickname of the author of the paste");
    txtNick->setText(QString::fromLatin1(passwd1->pw_name));

    txtTitle = new QLineEdit(this);
    txtTitle->setToolTip("name of the paste");

//    txtApiKey = new QLineEdit(this);
//    txtApiKey->setToolTip("API key to paste as you");

    txtFilePath = new QLineEdit(this);

    for (int i=0; i<expireList.count(); i++) {
        ExpireModel expireModel = expireList.at(i);
        cmbExpire->addItem(expireModel.getValue(), expireModel.getKey());
    }

    for (int i=0; i<syntaxList.count(); i++) {
        SyntaxModel syntaxModel = syntaxList.at(i);
        cmbSyntax->addItem(syntaxModel.getValue(), syntaxModel.getKey());
    }

    // Vertical layout with 3 buttons
    QPushButton *btnShare = new QPushButton("Send and share", this);
    QPushButton *btnFileDialog = new QPushButton("Select file", this);

    QObject::connect(btnShare, SIGNAL(released()), this, SLOT(handleButton()));
    QObject::connect(btnFileDialog, SIGNAL(clicked()), this, SLOT(handleBtnFileDialog()));

    QLabel *lblNick = new QLabel("Nick", this);
    QLabel *lblTitle = new QLabel("Title", this);
//    QLabel *lblApiKey = new QLabel("Key", this);
    QLabel *lblSyntax = new QLabel("Syntax", this);
    QLabel *lblExpire = new QLabel("Expire", this);

    QLabel *lblFile = new QLabel("File", this);
    hLayoutFileChose->addWidget(txtFilePath);
    hLayoutFileChose->addWidget(btnFileDialog);


    layoutForm->addRow(lblNick, txtNick);
    layoutForm->addRow(lblTitle, txtTitle);
//    layoutForm->addRow(lblApiKey, txtApiKey);
    layoutForm->addRow(lblSyntax, cmbSyntax);
    layoutForm->addRow(lblExpire, cmbExpire);
    layoutForm->addRow(lblFile, hLayoutFileChose);
    layoutForm->addRow("", btnShare);

    // Outer Layer
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Add the previous two inner layouts
    mainLayout->addLayout(layoutForm);

    // Set the outer layout as a main layout
    // of the widget
    this->setLayout(mainLayout);

    // Window title
    this->setWindowTitle("susepaste-qt");
}

void MainWindow::handleButton()
{
    const QString &filename = txtFilePath->text();
    QFileInfo fileInfo(filename);
    if (!fileInfo.exists()) {
        QString msg = QString::fromLatin1("File %1 not exist");
        QMessageBox::warning(this, "File not exist", msg.arg(filename));
        return;
    }

    if (!fileInfo.isReadable()) {
        QString msg = QString::fromLatin1("File %1 is not readable");
        QMessageBox::warning(this, "File not readable", msg.arg(filename));
        return;
    }

    QStringList  args = QStringList();

    QString nick = txtNick->text();
    if (!nick.isEmpty()) {
        args << QString("-n");
        args << txtNick->text();
    }

    QString title = txtTitle->text();
    if (!title.isEmpty()) {
        args << QString("-t");
        args << txtTitle->text();
    }
//    args << QString("-k");
//    args << txtApiKey->text();

    QString syntax = cmbSyntax->currentData().toString();
    if (!syntax.isEmpty()) {
        args << QString("-f");
        args << cmbSyntax->currentData().toString();
    }

    args << QString("-e");
    args << cmbExpire->currentData().toString();
    args << filename;

    qDebug() << args;

    QProcess *process = new QProcess();
    process->start("susepaste", args);
    process->waitForFinished();
    QString s = QString::fromUtf8(process->readAllStandardOutput());
    QString s2 = QString::fromUtf8(process->readAllStandardError());
    qDebug() << "stdout" << s;
    qDebug() << "stderr" << s2;

    QRegularExpression rx("https?://susepaste.org/([\\d]+)");
    const QRegularExpressionMatch &expressionMatch = rx.match(s);
    if (expressionMatch.hasMatch()) {
        QString id = expressionMatch.captured(1);
        QClipboard *clipboard = QApplication::clipboard();
        QString info = QString::fromLatin1("http://susepaste.org/%1").arg(id);
        clipboard->setText(info, QClipboard::Clipboard);
        QMessageBox::information(this, "susepaste", info);
    } else {
        QString output = s.append(s2);
        QMessageBox::information(this, "susepaste", output);
    }

    delete process;
}

void MainWindow::handleBtnFileDialog()
{
    QString file = QFileDialog::getOpenFileName(this, "Chose file to share", "/");
    this->setFilePath(file);
}

void MainWindow::setFilePath(QString &file)
{
    txtFilePath->setText(file);
}







