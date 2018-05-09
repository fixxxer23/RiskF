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

#ifndef RG_ACTIONINTERFACE_H
#define RG_ACTIONINTERFACE_H

#include <QObject>

#include "rg.h"
#include "rg_snapper.h"

class QMouseEvent;
class RG_EntityContainer;
class RG_GraphicView;
class RG_Graphic;

class RG_ActionInterface : public QObject, public RG_Snapper
{
    Q_OBJECT
public:
    explicit RG_ActionInterface(const char* name,
                                RG_EntityContainer& container,
                                RG_GraphicView& graphicView);
    virtual ~RG_ActionInterface();

    virtual void init();

    virtual void mousePressEvent(QMouseEvent* e);
    virtual void mouseMoveEvent(QMouseEvent* e);
    virtual void mouseReleaseEvent(QMouseEvent* e);

signals:

public slots:

protected:
    const char* name;
    RG_Graphic* graphic;

    RG::ActionType actionType;
};

#endif // RG_ACTIONINTERFACE_H
