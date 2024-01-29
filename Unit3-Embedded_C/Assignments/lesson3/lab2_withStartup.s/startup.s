/*startup_cortexM3.s
Eng.tasneem
*/

/*SRAM 0x20000000 */

.section .vectors

.word 0X20001000     /*  stack top address */
.word _reset         /*  Reset */
.word vector_handler           /* 2 NMI */
.word vector_handler            /* 3 Hard Fault */
.word vector_handler           /* 4 MM Fault */
.word vector_handler           /* 5 Bus Fault */
.word vector_handler           /* 6 Usage Fault */
.word vector_handler           /* 7 RESERVED */
.word vector_handler           /* 8 RESERVED */
.word vector_handler           /* 9 RESERVED */
.word vector_handler           /* 10 RESERVED */
.word vector_handler           /* 11 SV call */
.word vector_handler           /* 12 Debug reserved */
.word vector_handler           /* 13 RESERVED */ 
.word vector_handler           /* 14 PendSV */
.word vector_handler           /* 15 SysTick */
.word vector_handler           /* 16 IRQ0 */
.word vector_handler           /* 17 IRQ1 */
.word vector_handler  		   /* 18 IRQ2 */
.word vector_handler          /* 19 IRQ3 */
.word vector_handler          /* 20 IRQ4 */
.word vector_handler          /* 21 IRQ5 */
.word vector_handler          /* 22 IRQ6 */
.word vector_handler          /* 23 IRQ7 */
.word vector_handler          /* 24 IRQ8 */
.word vector_handler          /* 25 IRQ9 */
.word vector_handler          /* 26 IRQ10 */
.word vector_handler          /* 27 IRQ11 */
.word vector_handler          /* 28 IRQ12 */
.word vector_handler          /* 29 IRQ13 */
.word vector_handler          /* 30 IRQ14 */
.word vector_handler          /* 31 IRQ15 */
.word vector_handler          /* 32 IRQ16 */
.word vector_handler          /* 33 IRQ17 */
.word vector_handler          /* 34 IRQ18 */
.word vector_handler          /* 35 IRQ19 */
.word vector_handler          /* 36 IRQ20 */
.word vector_handler          /* 38 IRQ21 */
.word vector_handler          /* 39 IRQ22 */
.word vector_handler          /* 40 IRQ23 */
.word vector_handler          /* 41 IRQ24 */
.word vector_handler          /* 42 IRQ25 */
.word vector_handler          /* 43 IRQ26 */
.word vector_handler          /* 44 IRQ27 */
.word vector_handler          /* 45 IRQ28 */
.word vector_handler          /* 46 IRQ29 */
.word vector_handler          /* 47 IRQ30 */
.word vector_handler          /* 48 IRQ31 */
.word vector_handler          /* 49 IRQ32 */
.word vector_handler          /* 50 IRQ33 */
.word vector_handler          /* 51 IRQ34 */
.word vector_handler          /* 52 IRQ35 */
.word vector_handler          /* 53 IRQ36 */
.word vector_handler          /* 54 IRQ37 */
.word vector_handler          /* 55 IRQ38 */
.word vector_handler          /* 56 IRQ39 */
.word vector_handler          /* 57 IRQ40 */
.word vector_handler          /* 58 IRQ41 */
.word vector_handler          /* 59 IRQ42 */
.word vector_handler          /* 60 IRQ43 */
.word vector_handler          /* 61 IRQ44 */
.word vector_handler          /* 62 IRQ45 */
.word vector_handler          /* 63 IRQ46 */
.word vector_handler          /* 64 IRQ47 */
.word vector_handler          /* 65 IRQ48 */
.word vector_handler          /* 66 IRQ49 */
.word vector_handler          /* 67 IRQ50 */
.word vector_handler          /* 68 IRQ51 */
.word vector_handler          /* 69 IRQ52 */
.word vector_handler          /* 70 IRQ53 */
.word vector_handler          /* 71 IRQ54 */
.word vector_handler          /* 72 IRQ55 */
.word vector_handler          /* 73 IRQ56 */
.word vector_handler          /* 74 IRQ57 */
.word vector_handler          /* 75 IRQ58 */
.word vector_handler          /* 76 IRQ59 */
.word vector_handler          /* 77 IRQ60 */
.word vector_handler          /* 78 IRQ61 */
.word vector_handler          /* 79 IRQ62 */
.word vector_handler          /* 80 IRQ63 */
.word vector_handler          /* 81 IRQ64 */
.word vector_handler          /* 82 IRQ65 */
.word vector_handler          /* 83 IRQ66 */
.word vector_handler          /* 84 IRQ67 */

.section .text
_reset :
   bl main
   b .
.thumb_func
vector_handler :
    b _reset