#ifndef DATAFEEDING_H
#define DATAFEEDING_H

#include <QObject>
#include <QIODevice>
#include <QDebug>
#include <QUdpSocket>

class DataFeeding : public QIODevice
{
    Q_OBJECT
public:
    DataFeeding(QByteArray data4device);
    void ouvrir();
    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;

private:
    QByteArray buffer;
    qint64 m_pos = 0;
    QByteArray m_buffer;
    char passage = 0;
    QUdpSocket* m_udpSocket = nullptr;

};

#endif // DATAFEEDING_H
