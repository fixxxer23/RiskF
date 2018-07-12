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

#ifndef RG_MODIFICATION_H
#define RG_MODIFICATION_H

class RG_EntityContainer;
class RG_GraphicView;
class RG_Vector;

class RG_Modification
{
public:
    RG_Modification(RG_EntityContainer* container, RG_GraphicView* graphicView);

    void moveRef(const RG_Vector& ref, const RG_Vector& offset);
protected:

private:
    RG_EntityContainer* container;
    RG_GraphicView* graphicView;
};

#endif // RG_MODIFICATION_H
