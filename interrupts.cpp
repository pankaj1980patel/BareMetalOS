#include "interrupts.h"
#include "port.h"
#include "gdt.h"

void InterruptManager::SetInterruptDescriptorTableEntry(
    uint8_t interruptNumber,
            uint16_t codeSegmentSelectorOffset,
            void (*handle)(),
            uint8_t DescriptorPrivateOffset,
            uint8_t DescriptorType)
{
    const uint8_t IDT_DESC_PRESENT = 0x80;

    interruptDescriptorTable[interruptNumber].handlerAddressLowBits = ((uint32_t)handler) & 0xFFFF;
    interruptDescriptorTable[interruptNumber].handlerAddressHighBits = (((uint32_t)handler)>> 16) & 0xFFFF;
    interruptDescriptorTable[interruptNumber].access = IDT_DESC_PRESENT | DescriptorType | ((DescriptorPrivateOffset&3)<<5);
    interruptDescriptorTable[interruptNumber].reserved = 0;

}
InterruptManager::InterruptManager(GlobalDescriptorTable* gdt)
{
    uint16_t CodeSegment = gdt->CodeSegmentSelector();
    
}

InterruptManager::~InterruptManager()
{

}

void print(char *str);
uint32_t InterruptManager::handleInterrupt(uint8_t interruptNumber, uint32_t esp){
    print("INTERRUPT");
    return esp;
}