#include "kernel/log.h"

// UNUSED macro
#define UNUSED(x) (void)(x)

void hcf() {
    asm("cli");
    for (;;) { asm("hlt"); }
}

void panic(const char *message) {
    g_log.fatal("Kernel panic: {0}", message);
    g_log.flush();  // Force a flush to ensure the message is printed
    hcf();
}
