#include "loginview.h"
#include<QDebug>
#include<QString>
LoginView::LoginView(QObject *parent) : QObject(parent)
{

}

bool LoginView::initialize()
{
    resetModel();
    mEngine.load(QUrl(QStringLiteral("qrc:/Login.qml")));
    if (mEngine.rootObjects().isEmpty())
        return false;

    return true;
}

const QString &LoginView::name() const
{
    return m_name;
}

void LoginView::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    qDebug()<<"Set name to: "<<m_name;
    emit nameChanged();
}

void LoginView::resetModel()
{
    mEngine.rootContext()->setContextProperty("myLoginContext",QVariant::fromValue(this));
}

const QString &LoginView::password() const
{
    return m_password;
}

void LoginView::setPassword(const QString &newPassword)
{
    if (m_password == newPassword)
        return;
    m_password = newPassword;
    qDebug()<<"Set password to: "+m_password;
    emit passwordChanged();
}

void LoginView::gotoRegister()
{

}
