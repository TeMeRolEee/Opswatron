#include <iostream>

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include "Worker.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    app.setApplicationVersion(QStringLiteral("0.1.0"));

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addOption(
            {{QStringLiteral("i"), QStringLiteral("info")}, QStringLiteral("Get the players info")}
    );

    parser.process(app);

    if (parser.isSet(QStringLiteral("i"))) {
        std::cout << R"({"name":"drop_table_users"})" << std::endl;
        return 0;
    }

    bool go = true;

    std::string temp;

    Worker *worker = new Worker();

    QString serverResponse;

    //std::cout << R"({"name": "drop_table_users"})" << std::endl;

    //qDebug() << "fdafsdalfjsodajfiopsodafjsdio";

    while (go) {
        //std::cout << R"({"name":"drop_table_users"})" << std::endl;
        std::getline(std::cin, temp);
        serverResponse = QString::fromStdString(temp);

        serverResponse.clear();
        std::cout << R"({"dir": "UP"})" << std::endl;
    }


    return 0;
}