#ifndef REGISTERMENUCONTROLLER_H
#define REGISTERMENUCONTROLLER_H

#include <QObject>

class RegisterMenuController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString usernameRegister READ usernameRegister WRITE setUsernameRegister NOTIFY usernameRegisterChanged);
    Q_PROPERTY(QString passwordRegister READ passwordRegister WRITE setPasswordRegister NOTIFY passwordRegisterChanged);



public:
    explicit RegisterMenuController(QObject *parent = nullptr);

    const QString &usernameRegister() const;
    Q_INVOKABLE void setUsernameRegister(const QString &newUsernameRegister);

     const QString &passwordRegister() const;
    Q_INVOKABLE void setPasswordRegister(const QString &newPasswordRegister);

signals:

    void usernameRegisterChanged();
    void passwordRegisterChanged();

private:
    QString m_usernameRegister;
    QString m_passwordRegister;
};

#endif // REGISTERMENUCONTROLLER_H
