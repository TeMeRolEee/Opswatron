#include <iostream>

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include "MapStore.h"
#include "Thinker.h"

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    app.setApplicationVersion(QStringLiteral("0.1.0"));
    std::cout << "Hello, World!" << std::endl;

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addOption(
            {{QStringLiteral("i"), QStringLiteral("info")}, QStringLiteral("Get the players info")}
            );

    parser.process(app);

    if(parser.isSet(QStringLiteral("i")))
    {
        std::cout << R"({"name": "Taprika"})" << std::endl;
    }

    bool go = true;

    std::string temp;


    Thinker *thinker = new Thinker();









    while(go)
    {
        std::getline(std::cin, temp);
    }


    return app.exec();
}