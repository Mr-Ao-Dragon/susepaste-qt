#include <iostream>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "MainWindow.h"


using namespace std;

int main(int argc, char **argv) {
    QApplication app (argc, argv);
    QApplication::setApplicationName("susepaste-qt");
    QApplication::setApplicationVersion("0.1.0");
    QApplication::setWindowIcon(QIcon::fromTheme("suse"));

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addPositionalArgument("filename", "File to share.");
    parser.process(app);

    const QStringList args = parser.positionalArguments();
    QString filename;
    if (args.size() == 1) {
        filename = args.at(0);
    } else {
        filename = QString::fromLatin1("");
    }

    // Create a widget
    MainWindow *w = new MainWindow();
    w->init();
    w->setFilePath(filename);
    // Display
    w->show();

    int code = app.exec();
    delete w;
    return code;
}