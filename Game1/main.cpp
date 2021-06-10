#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "playmenucontroler.h"
#include "registermenucontroller.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    Playmenucontroler Playmenu;
    //Playmenu.setUsername();
    //Playmenu.setPassword();
    RegisterMenuController Registermenu;



    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("Playmenucontroler",QVariant::fromValue(&Playmenu));
    engine.rootContext()->setContextProperty("RegisterMenucontroller",QVariant::fromValue(&Registermenu));




    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
