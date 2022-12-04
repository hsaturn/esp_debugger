#include "debugginghandler.h"

DebuggingHandler::DebuggingHandler() : Handler("Debugging")
{

}

void DebuggingHandler::initialize(MainWindow *main)
{
  main->addMenuEntry("Debugging", "Start new");
}
