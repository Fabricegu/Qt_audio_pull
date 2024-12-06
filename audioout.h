#ifndef AUDIOOUT_H
#define AUDIOOUT_H

#include <QObject>
#include <QAudioOutput>
#include <QDebug>
#include <QScopedPointer>
#include "datafeeding.h"

#include <QIODevice>

class AudioOut : QObject
{
    Q_OBJECT
public:
    AudioOut(QByteArray dataRaw);
    void init(const QAudioDeviceInfo &deviceInfo);

private:
    DataFeeding *m_dataFeeding = nullptr;
    QAudioOutput *m_audioOutput = nullptr;
    QByteArray audioOut_buffer;
};

#endif // AUDIOOUT_H
