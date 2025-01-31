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

#include "rs_actionfactory.h"

#include <QAction>
#include <QActionGroup>

#include "rs_actiongroupmanager.h"

RS_ActionFactory::RS_ActionFactory(QObject *parent, QObject *a_handler)
    : QObject(parent)
    , action_handler(a_handler)
    , main_window(parent)
{

}

void RS_ActionFactory::fillActionContainer(QMap<QString, QAction *> &a_map, RS_ActionGroupManager *agm)
{
    QAction* action;


    // == File ==

    action = new QAction(tr("&New"), agm->file);
    action->setIcon(QIcon(":/icons/new.png"));
    connect(action, SIGNAL(triggered(bool)), main_window, SLOT(slotFileNew()));
    action->setObjectName("FileNew");
    a_map["FileNew"] = action;

    // == Insert ==
    action = new QAction(tr("&Line"), agm->insert);
    action->setIcon(QIcon(":/icons/activity.svg"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotInsertLine()));
    action->setObjectName("InsertLine");
    a_map["InsertLine"] = action;

    action = new QAction(tr("&Room"), agm->insert);
    action->setIcon(QIcon(":/icons/square.svg"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotInsertRoom()));
    action->setObjectName("InsertRoom");
    a_map["InsertRoom"] = action;

    action = new QAction(tr("&Rectangle"), agm->insert);
    action->setIcon(QIcon(":/icons/Rectangle.png"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotInsertRectangle()));
    action->setObjectName("InsertRectangle");
    a_map["InsertRectangle"] = action;

    action = new QAction(tr("&Polygon"), agm->insert);
    action->setIcon(QIcon(":/icons/Polygon.png"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotInsertPolygon()));
    action->setObjectName("InsertPolygon");
    a_map["InsertPolygon"] = action;



    // == Edit ==
    action = new QAction(tr("&Select"), agm->edit);
    action->setIcon(QIcon(":/icons/mouse cursor.ico"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotSelect()));
    action->setObjectName("Select");
    a_map["Select"] = action;

    action = new QAction(tr("&Copy"), agm->edit);
    action->setIcon(QIcon(":/icons/Copy.png"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotCopy()));
    action->setObjectName("Copy");
    a_map["Copy"] = action;

    action = new QAction(tr("&Rotate"), agm->edit);
    action->setIcon(QIcon(":/icons/Rotate.png"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotEditRotate()));
    action->setObjectName("Rotate");
    a_map["Rotate"] = action;

    action = new QAction(tr("&AddVertex"), agm->edit);
    action->setIcon(QIcon(":/icons/AddVertex.png"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotEditAddVertex()));
    action->setObjectName("AddVertex");
    a_map["AddVertex"] = action;

    action = new QAction(tr("&DelVertex"), agm->edit);
    action->setIcon(QIcon(":/icons/DelVertex.png"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotEditDelVertex()));
    action->setObjectName("DelVertex");
    a_map["DelVertex"] = action;

    action = new QAction(tr("&Undo"), agm->edit);
    action->setIcon(QIcon(":/icons/Undo.png"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotUndo()));
    action->setObjectName("Undo");
    a_map["Undo"] = action;

    action = new QAction(tr("&Redo"), agm->edit);
    action->setIcon(QIcon(":/icons/Redo.png"));
    connect(action, SIGNAL(triggered(bool)), action_handler, SLOT(slotRedo()));
    action->setObjectName("Redo");
    a_map["Redo"] = action;
}
