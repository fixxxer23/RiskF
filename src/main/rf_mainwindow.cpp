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

#include "rf_mainwindow.h"

#include <QStatusBar>

#include "rl_debug.h"
#include "rs_centralwidget.h"
#include "rs_actionhandler.h"
#include "rs_actionfactory.h"
#include "rs_actiongroupmanager.h"
#include "rs_widgetfactory.h"
#include "ru_dialogfactory.h"
#include "rl_dialogfactory.h"
#include "ru_mdiwindow.h"
#include "rs_graphicview.h"
#include "ru_coordinatewidget.h"

RF_MainWindow::RF_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , action_handler( new RS_ActionHandler(this) )
    , dialogFactory (nullptr)
    , ag_manager( new RS_ActionGroupManager(this) )
{
    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    // Инициализация строки состояния
    QStatusBar* status_bar = statusBar();
    coordinateWidget = new RU_CoordinateWidget(status_bar);
    status_bar->addWidget(coordinateWidget);


    status_bar->setMinimumHeight( 28 );

    auto central = new RS_CentralWidget(this);
    setCentralWidget(central);
    mdiAreaCAD = central->getMdiArea();

    connect(mdiAreaCAD, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            this, SLOT(slotWindowActivated(QMdiSubWindow*)));

    auto a_factory = new RS_ActionFactory(this, action_handler);
    a_factory->fillActionContainer(a_map, ag_manager);

    auto widget_factory = new RS_WidgetFactory(this, a_map, ag_manager);
    widget_factory->createMenus(menuBar());
    widget_factory->createCategoriesToolBar();

    // ===============================================
    // Dialog Factory
    RL_DEBUG << "create DialogFactory";
    dialogFactory = new RU_DialogFactory(this, widget_factory->option_toolbar);
    if (dialogFactory) {
        RL_DialogFactory::instance()->setFactoryObject(dialogFactory);
        dialogFactory->setCoordinateWidget(coordinateWidget); // Пока здесь потом надо перенести в
                                                                // обработку сигнала NewFile
        RL_DEBUG << "create DialogFactory Ok";
    }



    // Disable menu and toolbar items
    //emit windowsChanged(false);



}

RF_MainWindow::~RF_MainWindow()
{
    if (dialogFactory) delete dialogFactory;
}

void RF_MainWindow::slotWindowActivated(QMdiSubWindow *w)
{
    RL_DEBUG << "RF_MainWindow::slotWindowActivate begin";

    RL_DEBUG << "RF_MainWindow::slotWindowActivate Ok";
}

void RF_MainWindow::slotFileNew()
{
    RL_DEBUG << "RF_MainWindow::slotFileNew begin";

    statusBar()->showMessage(tr("Creating new file..."), 2000);

    RU_MDIWindow* w = new RU_MDIWindow(nullptr, mdiAreaCAD);

    RS_GraphicView* view = w->getGraphicView();
    action_handler->setView(view);
    action_handler->setDocument(w->getDocument());
    w->showMaximized();

    view->addScrollbars();
    view->redraw(RG::RedrawAll);

//    coordinateWidget->setVisible(true);
//    statusBar()->setVisible(true);

    RL_DEBUG << "RF_MainWindow::slotFileNew Ok";
}
