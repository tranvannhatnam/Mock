#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"View/gameview.h"
#include<QQmlContext>
#include"View/loginview.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    GameView gameview;

    gameview.move(1,3);
    gameview.move(3,6);
    gameview.move(7,2);
    gameview.setOpponent("nam");

    LoginView loginview;


//    engine.rootContext()->setContextProperty("myContext",&loginview);
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);
    if(!gameview.initialize())
        return -1;

    if(!loginview.initialize())
        return -1;

    app.exec();
}
