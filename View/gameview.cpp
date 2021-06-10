#include "View/gameview.h"
#include<QDebug>
GameView::GameView(QObject *parent) : QAbstractTableModel(parent), state(1), m_opponent("Opponent name")
{
    QVector<QString> tmp;
    QString s;
    tmp.append(s);
    tmp.append(s);
    tmp.append(s);
    tmp.append(s);
    tmp.append(s);
    tmp.append(s);
    tmp.append(s);
    tmp.append(s);
    tmp.append(s);
    tmp.append(s);

    table.append(tmp);
    table.append(tmp);
    table.append(tmp);
    table.append(tmp);
    table.append(tmp);
    table.append(tmp);
    table.append(tmp);
    table.append(tmp);
    table.append(tmp);
    table.append(tmp);


}

bool GameView::initialize()
{
    resetModel();
    mEngine.load(QUrl(QStringLiteral("qrc:/Game.qml")));
    if (mEngine.rootObjects().isEmpty())
        return false;

    return true;
}

bool GameView::destroy()
{
    mEngine.destroyed();
    return true;
}

int GameView::rowCount(const QModelIndex &) const
{
    return table.size();
}

int GameView::columnCount(const QModelIndex & ) const
{
    return table.at(0).size();
}

QVariant GameView::data(const QModelIndex &index, int role) const
{
    switch(role){
    case TableDataRole:{
        return table.at(index.row()).at(index.column());
    }
        break;
    case StateRole:{
        return state;
    }
    }

    return QVariant();
}

bool GameView::setData(const QModelIndex &index, const QVariant &value, int role)
{
    QString tmp=table[index.row()][index.column()];
    bool somethingChanged=false;
    switch (role) {
    case TableDataRole:{
        if(tmp!=value.toString()){
            tmp=(value.toString());
            qDebug()<<"Your move ["+QString::number(index.column())+"]["+QString::number(index.row()) +"]";
            somethingChanged=true;
        }
    }
    }
    if (somethingChanged){
        table[index.row()][index.column()]=tmp;
        emit dataChanged(index,index,QVector<int>()<<role);
        return true;
    }
    return false;

}

QHash<int, QByteArray> GameView::roleNames() const
{
    QHash<int,QByteArray>roles;
    roles[TableDataRole]="tableData";
    roles[StateRole]="currentState";
    return roles;
}

Qt::ItemFlags GameView::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable;
}

bool GameView::move(int x, int y)
{
    if ((x<0)||(y<0)||(x>table.size())||(y>table.at(0).size())){
        qDebug()<<"Invalid Move from Opponent";
        return false;
    }
    else {
        qDebug()<<"Opponent Move: ["+QString::number(x)+"]["+QString::number(y)+"]";
        table[x][y]="X";
        return true;
    }
}

void GameView::resetModel()
{
    mEngine.rootContext()->setContextProperty("myGameContext",this);
    //mEngine.rootContext()->setContextProperty("myInfoContext",QVariant::fromValue(this));
}

const QString &GameView::opponent() const
{
    return m_opponent;
}

void GameView::setOpponent(const QString &newOpponent)
{
    if (m_opponent == newOpponent)
        return;
    m_opponent = newOpponent;
    qDebug()<<"Set opponent to: " + m_opponent;
    emit opponentChanged();
}

void GameView::pushbtn()
{
    qDebug()<<"Push";
}
