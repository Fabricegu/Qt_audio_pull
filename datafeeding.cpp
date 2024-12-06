#include "datafeeding.h"

DataFeeding::DataFeeding(QByteArray data4device)
{
    m_udpSocket = new QUdpSocket(this);
    qDebug()<<"datafeeeding construct";
    m_buffer = data4device;
    buffer = data4device;
    qDebug()<<"taille m_buffer"<<m_buffer.size();
    qDebug()<<"taille buffer"<<buffer.size();
}
void DataFeeding::ouvrir()
{
    //open(QIODevice::ReadOnly);
    qDebug()<<"ok5";
}

/*
 * la méthode readData est appelée à chaque de que l'IOdevice
 * à besoin de donnée.
 * cette méthode virtuelle passe en paramétre le pointeur de la zone
 * qu'il va lire et la quantité de données maximal qu'il va lire.
 *
m_buffer.size() = quantité à lire
total = quantité lu
data = adresse du début du buffer


*/
/*
qint64 DataFeeding::readData(char *data, qint64 len)
{

    QByteArray tampon(16384, 0x00);
    tampon = buffer.left(len);
    buffer.remove(0, len);

    data = tampon.data();
    //memcpy(data , buffer.constData() , len);

    //qDebug()<<"ok6";
    qDebug()<<len;
    //qDebug()<<"-----";
    //qDebug()<<data;
    return len;
}
*/

qint64 DataFeeding::readData(char *data, qint64 longueur)
{
    qint64 len = 1400*6;
    qint64 total = 0;

    if (!m_buffer.isEmpty()) {
        while (len - total > 0) {
            const qint64 chunk = qMin((m_buffer.size() - m_pos), len - total);
            memcpy(data + total, m_buffer.constData() + m_pos, chunk);
            m_pos = (m_pos + chunk) % m_buffer.size();
            total += chunk;
            qDebug()<<"passage: "<<passage;
            qDebug()<<"chunk: "<<chunk;
            qDebug()<<"total: "<<total;
            qDebug()<<"position"<<m_pos;
            passage++;
           //m_udpSocket->writeDatagram(data,len, QHostAddress("227.1.2.210"), 5001);
             m_udpSocket->writeDatagram(data+1400*0,1400, QHostAddress(QHostAddress::Broadcast), 5001);
             m_udpSocket->writeDatagram(data+1400*1,1400, QHostAddress(QHostAddress::Broadcast), 5001);
             m_udpSocket->writeDatagram(data+1400*2,1400, QHostAddress(QHostAddress::Broadcast), 5001);
             m_udpSocket->writeDatagram(data+1400*3,1400, QHostAddress(QHostAddress::Broadcast), 5001);
             m_udpSocket->writeDatagram(data+1400*4,1400, QHostAddress(QHostAddress::Broadcast), 5001);
             m_udpSocket->writeDatagram(data+1400*5,1400, QHostAddress(QHostAddress::Broadcast), 5001);
        }
    }
    qDebug()<<total;
    return total;
}


qint64 DataFeeding::writeData(const char *data, qint64 len)
{
    Q_UNUSED(data);
    Q_UNUSED(len);

    return 0;
}
