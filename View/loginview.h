#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QObject>
#include<QQmlApplicationEngine>
#include<QQmlContext>
class LoginView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    QString m_name;

public:
    explicit LoginView(QObject *parent = nullptr);
    bool initialize();
    const QString &name() const;
    Q_INVOKABLE void setName(const QString &newName);

    const QString &password() const;
    void setPassword(const QString &newPassword);
    Q_INVOKABLE void gotoRegister();
signals:
    void nameChanged();
    void passwordChanged();

private:
    QQmlApplicationEngine mEngine;
    void resetModel();
    QString m_password;
};

#endif // LOGINVIEW_H
