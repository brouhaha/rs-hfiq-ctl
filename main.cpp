// Copyright 2017 Eric Smith

#include <stdexcept>

#include <QApplication>
#include <QCommandLineParser>
#include <QLabel>

#include "mainwindow.h"
#include "radiointerface.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("rs-hfiq-ctl");
    app.setApplicationVersion("0.1");

    QCommandLineParser parser;

    parser.setApplicationDescription("Test helper");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("port",
				 QCoreApplication::translate("main", "com port"));

    parser.process(app);

    const QStringList args = parser.positionalArguments();

    QString com_port;

    // source is args.at(0), destination is args.at(1)
    if (args.size() >= 1)
      com_port = args.at(0);

    if (com_port.isEmpty())
      {
      }

    try
      {
	;
      }
    catch (std::runtime_error &e)
    {
        QLabel note(e.what());
        note.show();
        return app.exec();
    }

    RadioInterface *radio_interface = new RadioInterface();

    MainWindow mainWin(radio_interface);
    mainWin.show();

    return app.exec();
}
