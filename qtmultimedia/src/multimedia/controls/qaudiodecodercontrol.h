/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QAUDIODECODERCONTROL_H
#define QAUDIODECODERCONTROL_H

#include <QtMultimedia/qmediacontrol.h>
#include <QtMultimedia/qaudiodecoder.h>

#include <QtCore/qpair.h>

#include <QtMultimedia/qaudiobuffer.h>

QT_BEGIN_NAMESPACE

class QIODevice;
class Q_MULTIMEDIA_EXPORT QAudioDecoderControl : public QMediaControl
{
    Q_OBJECT

public:
    ~QAudioDecoderControl();

    virtual QAudioDecoder::State state() const = 0;

    virtual QString sourceFilename() const = 0;
    virtual void setSourceFilename(const QString &fileName) = 0;

    virtual QIODevice* sourceDevice() const = 0;
    virtual void setSourceDevice(QIODevice *device) = 0;

    virtual void start() = 0;
    virtual void stop() = 0;

    virtual QAudioFormat audioFormat() const = 0;
    virtual void setAudioFormat(const QAudioFormat &format) = 0;

    virtual QAudioBuffer read() = 0;
    virtual bool bufferAvailable() const = 0;

    virtual qint64 position() const = 0;
    virtual qint64 duration() const = 0;

Q_SIGNALS:
    void stateChanged(QAudioDecoder::State newState);
    void formatChanged(const QAudioFormat &format);
    void sourceChanged();

    void error(int error, const QString &errorString);

    void bufferReady();
    void bufferAvailableChanged(bool available);
    void finished();

    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);

protected:
    QAudioDecoderControl(QObject* parent = 0);
};

#define QAudioDecoderControl_iid "org.qt-project.qt.audiodecodercontrol/5.0"
Q_MEDIA_DECLARE_CONTROL(QAudioDecoderControl, QAudioDecoderControl_iid)

QT_END_NAMESPACE

#endif  // QAUDIODECODERCONTROL_H
