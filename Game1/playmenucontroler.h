#ifndef PLAYMENUCONTROLER_H
#define PLAYMENUCONTROLER_H

#include <QObject>

class Playmenucontroler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged);
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged);
    QString m_username;

public:
    explicit Playmenucontroler(QObject *parent = nullptr);

    const QString &username() const;
    Q_INVOKABLE void setUsername(const QString &newUsername);

    const QString &password() const;
    Q_INVOKABLE void setPassword(const QString &newPassword);

signals:

    void usernameChanged();

    void passwordChanged();

private:

    QString m_password;
};

#endif // PLAYMENUCONTROLER_H
