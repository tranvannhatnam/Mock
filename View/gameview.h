#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include<QAbstractTableModel>
#include <QQmlApplicationEngine>
#include <QQmlContext>
class GameView : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(QString opponent READ opponent WRITE setOpponent NOTIFY opponentChanged)
    enum BoardRoles{
        TableDataRole=Qt::UserRole +1,
        StateRole
    };
public:
    explicit GameView(QObject *parent = nullptr);

    bool initialize();
    bool destroy();
    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const override;
    Q_INVOKABLE bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    QHash<int, QByteArray> roleNames() const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    bool move(int x, int y);
    const QString &opponent() const;
    void setOpponent(const QString &newOpponent);
    Q_INVOKABLE void pushbtn();

signals:
    void opponentChanged();

private:
    QVector<QVector<QString>> table;
    QQmlApplicationEngine mEngine;
    void resetModel();
    int state;
    QString m_opponent;
};

#endif // BOARD_H
