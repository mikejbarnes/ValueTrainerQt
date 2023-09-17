#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "appmanager.h"
#include "colorhandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    AppManager appManager;

    ColorHandler colorHandler;

    QQmlApplicationEngine engine;

    QQmlContext* context = engine.rootContext();
    context->setContextProperty("appManager", &appManager);
    context->setContextProperty("colorHandler", &colorHandler);

    const QUrl url(u"qrc:/DynamicQMLTest/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
