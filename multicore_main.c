/**************************************************************************
--                PICO2 RISC-V Multicore setup
-- 
--           Copyright (C) 2025 By Ulrik Hørlyk Hjort
--
--  This Program is Free Software; You Can Redistribute It and/or
--  Modify It Under The Terms of The GNU General Public License
--  As Published By The Free Software Foundation; Either Version 2
--  of The License, or (at Your Option) Any Later Version.
--
--  This Program is Distributed in The Hope That It Will Be Useful,
--  But WITHOUT ANY WARRANTY; Without Even The Implied Warranty of
--  MERCHANTABILITY or FITNESS for A PARTICULAR PURPOSE.  See The
--  GNU General Public License for More Details.
--
-- You Should Have Received A Copy of The GNU General Public License
-- Along with This Program; if not, See <Http://Www.Gnu.Org/Licenses/>.
***************************************************************************/
#include "pico/stdlib.h"
#include <stdint.h>
#include <stdio.h>
#include "pico/multicore.h"
#include "hardware/structs/sio.h"
#include "uart_pio.h"

#define UART_TX_PIN 2

void core1_entry() {
    while (1) {
        printf("Hello from core %d\n\r", sio_hw->cpuid);
        sleep_ms(1);
    }
}


int main() {
	init_uart(19200,UART_TX_PIN);
	multicore_launch_core1(core1_entry);	
	while(1) {
        printf("Hello from core %d\n\r", sio_hw->cpuid);		
        sleep_ms(1);
	}
}
