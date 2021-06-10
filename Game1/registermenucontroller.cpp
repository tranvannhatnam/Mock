#include "registermenucontroller.h"

RegisterMenuController::RegisterMenuController(QObject *parent) : QObject(parent),
  m_usernameRegister(""),
    m_passwordRegister("")
{

}

const QString &RegisterMenuController::usernameRegister() const
{
    return m_usernameRegister;
}

void RegisterMenuController::setUsernameRegister(const QString &newUsernameRegister)
{
    if (m_usernameRegister == newUsernameRegister)
        return;
    m_usernameRegister = newUsernameRegister;
    emit usernameRegisterChanged();
}

const QString &RegisterMenuController::passwordRegister() const
{
    return m_passwordRegister;
}

void RegisterMenuController::setPasswordRegister(const QString &newPasswordRegister)
{
    if (m_passwordRegister == newPasswordRegister)
        return;
    m_passwordRegister = newPasswordRegister;
    emit passwordRegisterChanged();
}
