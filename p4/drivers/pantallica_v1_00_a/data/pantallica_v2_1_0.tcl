##############################################################################
## Filename:          C:\hlocal\p2-20171023T092356Z-001\p2-20171023T092356Z-001\p2/drivers/pantallica_v1_00_a/data/pantallica_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Thu Nov 16 16:14:27 2017 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "pantallica" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
