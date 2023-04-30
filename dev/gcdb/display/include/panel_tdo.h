/* Copyright (c) 2017, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of The Linux Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*---------------------------------------------------------------------------
 * This file is autogenerated file using gcdb parser. Please do not edit it.
 * Update input XML file to add a new entry or update variable in this file
 * VERSION = "1.0"
 *---------------------------------------------------------------------------*/

#ifndef _PANEL_TDO_HD0466K40002_0810_H_
#define _PANEL_TDO_HD0466K40002_0810_H_
/*---------------------------------------------------------------------------*/
/* HEADER files                                                              */
/*---------------------------------------------------------------------------*/
#include "panel.h"

/*---------------------------------------------------------------------------*/
/* Panel configuration                                                       */
/*---------------------------------------------------------------------------*/
static struct panel_config tdo_hd0466k40002_0810_panel_data = {
	"qcom,mdss_dsi_tdo_hd0466k40002_0810", "dsi:0:", "qcom,mdss-dsi-panel",
	8, 0, "DISPLAY_1", 0, 0, 75, 1, 0, 0, 0, 0, 0, 0, 498000000, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel resolution                                                          */
/*---------------------------------------------------------------------------*/
static struct panel_resolution tdo_hd0466k40002_0810_panel_res = {
	720, 1280, 264, 70, 50, 0, 16, 14, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel color information                                                   */
/*---------------------------------------------------------------------------*/
static struct color_info tdo_hd0466k40002_0810_color = {
	24, 2, 0xff, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel on/off command information                                          */
/*---------------------------------------------------------------------------*/
static char tdo_hd0466k40002_0810_on_cmd0[] = { };
	
static char tdo_hd0466k40002_0810_on_cmd1[] = { };
	
static char tdo_hd0466k40002_0810_on_cmd2[] = { };
	
static char tdo_hd0466k40002_0810_on_cmd3[] = { };
	
static char tdo_hd0466k40002_0810_on_cmd4[] = { };
	
static char tdo_hd0466k40002_0810_on_cmd5[] = { };
	
static char tdo_hd0466k40002_0810_on_cmd6[] = { };
	
static char tdo_hd0466k40002_0810_on_cmd7[] = { };
	
static struct mipi_dsi_cmd tdo_hd0466k40002_0810_on_command[] = {
	
	
	
	
	
	
	

};

#define TDO_HD0466K40002_0810_ON_COMMAND 0


static struct mipi_dsi_cmd tdo_hd0466k40002_0810_off_command[] = {

};

#define TDO_HD0466K40002_0810_OFF_COMMAND 0


static struct command_state tdo_hd0466k40002_0810_state = {
	0, 1
};

/*---------------------------------------------------------------------------*/
/* Command mode panel information                                            */
/*---------------------------------------------------------------------------*/
static struct commandpanel_info tdo_hd0466k40002_0810_command_panel = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Video mode panel information                                              */
/*---------------------------------------------------------------------------*/
static struct videopanel_info tdo_hd0466k40002_0810_video_panel = {
	2, 0, 0, 0, 1, 1, 2, 0, 0x9
};

/*---------------------------------------------------------------------------*/
/* Lane configuration                                                        */
/*---------------------------------------------------------------------------*/
static struct lane_configuration tdo_hd0466k40002_0810_lane_config = {
	4, 0, 1, 1, 1, 1
};

/*---------------------------------------------------------------------------*/
/* Panel timing                                                              */
/*---------------------------------------------------------------------------*/
static const uint32_t tdo_hd0466k40002_0810_timings[] = {
	0x80, 0x40, 0x2c, 0x00, 0x76, 0x7a, 0x30, 0x44, 0x34, 0x3, 0x4
};

static struct panel_timing tdo_hd0466k40002_0810_timing_info = {
	0, 4, 0x6D, 0x07
};

/*---------------------------------------------------------------------------*/
/* Panel reset sequence                                                      */
/*---------------------------------------------------------------------------*/
static struct panel_reset_sequence tdo_hd0466k40002_0810_reset_seq = {
	{1, 20, 20, }, {0, 0, 1, }, 20
};

/*---------------------------------------------------------------------------*/
/* Backlight setting                                                         */
/*---------------------------------------------------------------------------*/
static struct backlight tdo_hd0466k40002_0810_backlight = {
	1, 1, 255, 100, 2, "PMIC_8941"
};

#endif /*_PANEL_TDO_HD0466K40002_0810_H_*/
