#include "Interface.hpp"

#ifndef I2CBackpack_H
#define I2CBackpack_H


class I2CBackpack : public Interface 
{

    public:
        I2CBackpack();
        bool Init() override;
        void Set4BitMode() override; 
        void ClearScreen() override;
        void SetPosition(uint8_t row, uint8_t  col) override;
        void ReturnHome() override;
        void PrintChar() override;
        void CursorControl(bool show_cursor, bool blink_cursor) override; //Replaces NoCursor DisplayCursor, BlinkChar, and SolidChar
        void SetLineDisplay(uint8_t lines) override; //Select 1, 2, or 4 line display
        bool CheckBusyFlag() override;//Check busy flag
        void DisplayControl() override;
        void ShiftCursor() override;
        void SetFont() override;
        ~I2CBackpack();

    private:
        uint8_t device_address_;
        uint8_t col_;
        uint8_t row_;
        void Write(uint8_t address, uint8_t data);
        void Read(uint8_t address)const;

};

#endif
