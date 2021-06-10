#include "playmenucontroler.h"
#include <QDebug>

Playmenucontroler::Playmenucontroler(QObject *parent) : QObject(parent)
  , m_username(""),
    m_password("")
{

}

const QString &Playmenucontroler::username() const
{
    return m_username;
}

void Playmenucontroler::setUsername(const QString &newUsername)
{
    if (m_username == newUsername)
        return;
    m_username = newUsername;
    emit usernameChanged();
}

const QString &Playmenucontroler::password() const
{
    return m_password;
}

void Playmenucontroler::setPassword(const QString &newPassword)
{
    if (m_password == newPassword)
        return;
    m_password = newPassword;
    emit passwordChanged();
}
