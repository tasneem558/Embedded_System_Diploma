/*linker_script_cortexM3.s
Eng.tasneem
*/

MEMORY
{
  flash(RX) : ORIGIN = 0X08000000, LENGTH = 128K
  sram(RWX) : ORIGIN = 0X20000000, LENGTH = 20K
}

SECTIONS
{
  .text : {
          *(.vectors*)
          *(.text*)
          *(.rodata)
          E_text = . ;
  }> flash

  .data : {
  _S_Data = . ;
  *(.data)
  _E_Data = . ;
  }> sram AT> flash

  .bss : {
  _S_bss = . ;
  *(.bss)
  . = ALIGN(4);
  _E_bss = . ;

  . = ALIGN(4);
  . = . + 0X1000;
  _stack_top = . ;
  
  }> sram

}