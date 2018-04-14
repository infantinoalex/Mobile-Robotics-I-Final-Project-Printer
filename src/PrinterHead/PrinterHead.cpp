#include "PrinterHead.hpp"
#include "../Exception/CustomExceptions.hpp"

#include <stdexcept>

PrinterHead::PrinterHead(Motor xMotor, Motor yMotor, int printerHeadPort)
{
    if (printerHeadPort < 0 || printerHeadPort > 5)
    {
        throw invalid_argument("printerHeadPort must not be less than 0 or greater than 5.")
    }

    if (xMotor == NULL)
    {
        throw invalid_argument("xMotor must not be NULL.");
    }

    if (yMotor == NULL)
    {
        throw invalid_argument("yMotor must not be NULL.");
    }

    this->_printerHeadPort = printerHeadPort;

    this->_xMotor = xMotor;
    this->_yMotor = yMotor;

    this->_isLowered = false;
}

void PrinterHead::LowerPrinter()
{
    if (this->_isLowered)
    {
        return;
    }

    enable_servos();
    set_servo_position(this->_printerHeadPort, this->_maxServoPosition);
    disable_servos();

    this->_isLowered = true;
}

void PrinterHead::RaisePrinter()
{
    if (!this->_isLowered)
    {
        return;
    }
    
    enable_servos();
    set_servo_position(this->_printerHeadPort, this->_minServoPosition);
    disable_servos();

    this->_isLowered = false;
}

bool PrinterHead::TryMovePrinterHead(int xDirectionToMove, int yDirectionToMove)
{
    throw not_implemented_exception("MovePrinterHead is not implemented yet");
}

bool PrinterHead::TryMovePrinterHeadHome()
{
    throw not_implemented_exception("MovePrinterHeadHome is not implemented yet");
}