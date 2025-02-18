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

#ifndef RG_SNAPPER_H
#define RG_SNAPPER_H

#include "rg.h"
#include "rg_vector.h"

class RG_Entity;
class RG_EntityContainer;
class RG_GraphicView;
class QMouseEvent;
class QPointF;

class RG_Snapper
{
public:
    RG_Snapper(RG_EntityContainer& container, RG_GraphicView& graphicView);
    virtual ~RG_Snapper();

    virtual void init(int status=0);
    virtual void finish();
    bool isFinished();

    void deleteSnapper();
    void drawSnapper();

    void setSnapperType(RG::SnapperType type);
    RG::SnapperType getSnapperType();

    /**
     * @brief catchEntity - Возвращает сущность расположенную рядом с заданной точкой
     * @param pos
     * @return
     */
    RG_Entity* catchEntity(const RG_Vector &pos);

    /**
     * @brief setSnapPoint - Ручная установка координат курсора
     *                       и нарисовать курсор на накладываемом слое Snapper
     * @param coord - координаты, которые необходимо установить
     * @return
     */
    RG_Vector setSnapPoint(const RG_Vector& coord);
    RG_Vector snapPoint(QMouseEvent* e);

protected:
    /**
     * @brief setSnapPoint - Создает объект RG_Vector из точки QT
     * @param p - точка QT из которой нужно сделать вектор
     * @return объект RG_Vector
     */
    static RG_Vector makeVector(const QPointF &p);

protected:
    RG_EntityContainer* container;
    RG_GraphicView* graphicView;

    bool finished = {false};

private:
    struct Indicator;

    Indicator* snapIndicator;
    RG_Vector snapCoord;
    RG_Vector snapSpot;
};

#endif // RG_SNAPPER_H
