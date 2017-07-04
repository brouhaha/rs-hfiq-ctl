// Control panel application for RS-HFIQ SDR transceiver
// Copyright 2017 Eric Smith <spacewar@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of version 3 of the GNU General Public License
// as published by the Free Software Foundation.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
    if (! radio_interface->choose())
      return 1; // XXX need better return value?

    MainWindow mainWin(radio_interface);
    mainWin.show();

    return app.exec();
}
