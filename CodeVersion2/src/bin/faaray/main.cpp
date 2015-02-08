#include <QtGui/QApplication>
#include "GUI/MainWindow.h"
//#include "tbb/task_scheduler_init.h"

//#define TBB_DO_THREADING_TOOLS 1

//using namespace tbb;

int main(int argv, char **args)
{
    //task_scheduler_init init;

    QApplication app(argv, args);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}

