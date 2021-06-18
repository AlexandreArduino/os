[BITS 64]
GLOBAL idt_load
EXTERN idtp
idt_load:
    lidt [idtp]
    ret