#include "audioout.h"

AudioOut::AudioOut(QByteArray dataRaw)
{
    qDebug()<<"taille dataRaw"<<dataRaw.size();
    audioOut_buffer = dataRaw;
    init(QAudioDeviceInfo::defaultOutputDevice());
}

void AudioOut::init(const QAudioDeviceInfo &deviceInfo)
{
    QAudioFormat format;
    format.setSampleRate(48000);
    format.setChannelCount(2);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    if (!deviceInfo.isFormatSupported(format)) {
        qDebug() << "not supported";

     }

    m_dataFeeding = new DataFeeding(audioOut_buffer);
    m_dataFeeding->open(QIODevice::ReadOnly);
    m_audioOutput = new QAudioOutput(deviceInfo, format);
    m_audioOutput->setBufferSize(5*16384);
    qDebug()<<"taille du buffer:" <<m_audioOutput->bufferSize();
    m_audioOutput->start(m_dataFeeding);
    m_dataFeeding->ouvrir();


}



