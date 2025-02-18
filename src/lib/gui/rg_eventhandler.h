/****************************************************************************
**
** Copyright (C) 2018 AWSoft.
** Contact: https://www.
**
** Это файл является частью программы RiskF - Программы по проведению
** расчетов величины индивидуального пожарного риска.
**
** Программа использует кроссплатформенный фреймворк для разработки ПО Qt
** под лицензией GNU LGPL v3.0 динамически подключая ее
** https://www.qt.io
**
** Лицензия на использовние исходных текстов и программы RiskF
** находится в файле licenses.txt
**
****************************************************************************/

#ifndef RG_EVENTHANDLER_H
#define RG_EVENTHANDLER_H

#include <QObject>
#include <QList>
#include <qevent.h>

class RG_ActionInterface;

class RG_EventHandler : public QObject
{
    Q_OBJECT
public:
    explicit RG_EventHandler(QObject *parent = nullptr);
    virtual ~RG_EventHandler();

    void setCurrentAction(RG_ActionInterface* action);
    void setDefaultAction(RG_ActionInterface* action);
    void onChangedAction();
    bool hasAction();
    void cleanUp();

    void killAllActions();

    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);

    void leaveEvent(QEvent* e);

signals:

public slots:

private:
    QList<RG_ActionInterface*> currentActions;
    RG_ActionInterface* defaultAction;
};

#endif // RG_EVENTHANDLER_H
