#pragma once
#include <handler.h>
#include <QMainWindow>

class DebuggingHandler : public Handler
{
public:
    DebuggingHandler();
    
    virtual void initialize(MainWindow*) override;
};

