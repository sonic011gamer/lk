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

#ifndef _PANEL_TALKOV_WQHD_DUALDSI_CMD_H_
#define _PANEL_TALKOV_WQHD_DUALDSI_CMD_H_
/*---------------------------------------------------------------------------*/
/* HEADER files                                                              */
/*---------------------------------------------------------------------------*/
#include "panel.h"

/*---------------------------------------------------------------------------*/
/* Panel configuration                                                       */
/*---------------------------------------------------------------------------*/
static struct panel_config talkov_wqhd_dualdsi_cmd_panel_data = {
	"qcom,mdss_dsi_talkov_wqhd_dualdsi_cmd", "dsi:0:", "qcom,mdss-dsi-panel",
	8, 1, "DISPLAY_1", 0, 0, 60, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel resolution                                                          */
/*---------------------------------------------------------------------------*/
static struct panel_resolution talkov_wqhd_dualdsi_cmd_panel_res = {
	1440, 2560, 180, 44, 4, 0, 8, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel color information                                                   */
/*---------------------------------------------------------------------------*/
static struct color_info talkov_wqhd_dualdsi_cmd_color = {
	24, 0, 0xff, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel on/off command information                                          */
/*---------------------------------------------------------------------------*/
static char talkov_wqhd_dualdsi_cmd_on_cmd0[] = {
	0x36, 0x80, 0x15, 0x80
};

static char talkov_wqhd_dualdsi_cmd_on_cmd1[] = {
	0x3A, 0x70, 0x15, 0x80
};

static char talkov_wqhd_dualdsi_cmd_on_cmd2[] = {
	0xB0, 0x04, 0x23, 0x80
};

static char talkov_wqhd_dualdsi_cmd_on_cmd3[] = {
	0x00, 0x00, 0x05, 0x80
};

static char talkov_wqhd_dualdsi_cmd_on_cmd4[] = {
	0x00, 0x00, 0x05, 0x80
};

static char talkov_wqhd_dualdsi_cmd_on_cmd5[] = {
	0xD6, 0x01, 0x23, 0x80
};

static char talkov_wqhd_dualdsi_cmd_on_cmd6[] = {
	0x07, 0x00, 0x29, 0xC0,
	0xB3, 0x14, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd7[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xB4, 0x0C, 0x00, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd8[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xB6, 0x3A, 0xD3, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd9[] = {
	0x04, 0x00, 0x29, 0xC0,
	0xC3, 0x01, 0x00, 0x0F,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd10[] = {
	0x07, 0x00, 0x29, 0xC0,
	0xC0, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x00, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd11[] = {
	0x25, 0x00, 0x29, 0xC0,
	0xC1, 0x84, 0x61, 0xc0,
	0x21, 0x9D, 0x32, 0x96,
	0x7A, 0x30, 0xC2, 0x08,
	0x00, 0x00, 0x00, 0x00,
	0x10, 0x61, 0x84, 0x4F,
	0x2D, 0x41, 0x0C, 0x02,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x62, 0x01, 0x08,
	0x0A, 0x00, 0x01, 0x11,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd12[] = {
	0x0A, 0x00, 0x29, 0xC0,
	0xC2, 0x31, 0xF0, 0x0A,
	0x00, 0x08, 0x08, 0x00,
	0x00, 0xFF, 0xFF, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd13[] = {
	0x1C, 0x00, 0x29, 0xC0,
	0xC4, 0x70, 0x00, 0x00,
	0x44, 0x00, 0x44, 0x44,
	0x00, 0x44, 0x00, 0x00,
	0x06, 0x03, 0x00, 0x00,
	0x00, 0x44, 0x00, 0x44,
	0x44, 0x00, 0x44, 0x00,
	0x00, 0x01, 0x03, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd14[] = {
	0x2A, 0x00, 0x29, 0xC0,
	0xC6, 0x5A, 0x06, 0x50,
	0x06, 0x50, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x13, 0x1A,
	0x07, 0x5A, 0x06, 0x50,
	0x06, 0x50, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x13, 0x1A,
	0x07, 0xFF, 0xFF, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd15[] = {
	0x0C, 0x00, 0x29, 0xC0,
	0xCB, 0x1F, 0x0F, 0xF0,
	0xF8, 0x20, 0x00, 0x00,
	0x04, 0xC0, 0x00, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd16[] = {
	0xCC, 0x1E, 0x23, 0x80
};

static char talkov_wqhd_dualdsi_cmd_on_cmd17[] = {
	0x03, 0x00, 0x29, 0xC0,
	0xD2, 0x00, 0x00, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd18[] = {
	0x19, 0x00, 0x29, 0xC0,
	0xD7, 0x84, 0xF0, 0x7F,
	0xA8, 0xCE, 0x38, 0xFC,
	0xC1, 0x18, 0xE7, 0x8F,
	0x1F, 0x3C, 0x10, 0xFA,
	0xC3, 0x0F, 0x04, 0x41,
	0x00, 0x00, 0x00, 0x00,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd19[] = {
	0x04, 0x00, 0x29, 0xC0,
	0xD9, 0x00, 0x00, 0x00,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd20[] = {
	0x20, 0x00, 0x29, 0xC0,
	0xC7, 0x02, 0x10, 0x15,
	0x1E, 0x2A, 0x38, 0x43,
	0x53, 0x37, 0x3F, 0x4C,
	0x5A, 0x66, 0x70, 0x7C,
	0x09, 0x0E, 0x15, 0x1E,
	0x2A, 0x38, 0x43, 0x53,
	0x37, 0x3F, 0x4C, 0x5A,
	0x66, 0x70, 0x7F, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd21[] = {
	0x15, 0x00, 0x29, 0xC0,
	0xC8, 0x01, 0x00, 0x00,
	0x00, 0x00, 0xFC, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0xFC, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xFC, 0x00,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd22[] = {
	0x0C, 0x00, 0x29, 0xC0,
	0xD0, 0x55, 0x81, 0xBB,
	0x19, 0x9A, 0x4C, 0x19,
	0x19, 0x0C, 0x00, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd23[] = {
	0x1B, 0x00, 0x29, 0xC0,
	0xD3, 0x1B, 0x33, 0xBB,
	0xAB, 0xA3, 0x33, 0x33,
	0x33, 0x00, 0x01, 0x00,
	0xA0, 0xF8, 0xA0, 0x0F,
	0x47, 0x49, 0x22, 0x3B,
	0x37, 0x72, 0x07, 0x3D,
	0xBF, 0x33, 0xFF, 0xFF,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd24[] = {
	0x09, 0x00, 0x29, 0xC0,
	0xD5, 0x06, 0x00, 0x00,
	0x01, 0x35, 0x01, 0x35,
};

static char talkov_wqhd_dualdsi_cmd_on_cmd25[] = {
	0x29, 0x00, 0x05, 0x80
};

static char talkov_wqhd_dualdsi_cmd_on_cmd26[] = {
	0x11, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd talkov_wqhd_dualdsi_cmd_on_command[] = {
	{0x4, talkov_wqhd_dualdsi_cmd_on_cmd0, 0x00},
	{0x4, talkov_wqhd_dualdsi_cmd_on_cmd1, 0x05},
	{0x4, talkov_wqhd_dualdsi_cmd_on_cmd2, 0x00},
	{0x4, talkov_wqhd_dualdsi_cmd_on_cmd3, 0x00},
	{0x4, talkov_wqhd_dualdsi_cmd_on_cmd4, 0x00},
	{0x4, talkov_wqhd_dualdsi_cmd_on_cmd5, 0x00},
	{0xc, talkov_wqhd_dualdsi_cmd_on_cmd6, 0x00},
	{0x8, talkov_wqhd_dualdsi_cmd_on_cmd7, 0x00},
	{0x8, talkov_wqhd_dualdsi_cmd_on_cmd8, 0x00},
	{0x8, talkov_wqhd_dualdsi_cmd_on_cmd9, 0x00},
	{0xc, talkov_wqhd_dualdsi_cmd_on_cmd10, 0x00},
	{0x28, talkov_wqhd_dualdsi_cmd_on_cmd11, 0x00},
	{0x10, talkov_wqhd_dualdsi_cmd_on_cmd12, 0x00},
	{0x20, talkov_wqhd_dualdsi_cmd_on_cmd13, 0x00},
	{0x30, talkov_wqhd_dualdsi_cmd_on_cmd14, 0x00},
	{0x10, talkov_wqhd_dualdsi_cmd_on_cmd15, 0x00},
	{0x4, talkov_wqhd_dualdsi_cmd_on_cmd16, 0x00},
	{0x8, talkov_wqhd_dualdsi_cmd_on_cmd17, 0x00},
	{0x1c, talkov_wqhd_dualdsi_cmd_on_cmd18, 0x00},
	{0x8, talkov_wqhd_dualdsi_cmd_on_cmd19, 0x00},
	{0x24, talkov_wqhd_dualdsi_cmd_on_cmd20, 0x00},
	{0x18, talkov_wqhd_dualdsi_cmd_on_cmd21, 0x00},
	{0x10, talkov_wqhd_dualdsi_cmd_on_cmd22, 0x00},
	{0x20, talkov_wqhd_dualdsi_cmd_on_cmd23, 0x00},
	{0xc, talkov_wqhd_dualdsi_cmd_on_cmd24, 0x78},
	{0x4, talkov_wqhd_dualdsi_cmd_on_cmd25, 0x78},
	{0x4, talkov_wqhd_dualdsi_cmd_on_cmd26, 0x00}
};

#define TALKOV_WQHD_DUALDSI_CMD_ON_COMMAND 27


static char talkov_wqhd_dualdsi_cmdoff_cmd0[] = {
	0x28, 0x00, 0x05, 0x80
};

static char talkov_wqhd_dualdsi_cmdoff_cmd1[] = {
	0x10, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd talkov_wqhd_dualdsi_cmd_off_command[] = {
	{0x4, talkov_wqhd_dualdsi_cmdoff_cmd0, 0x21},
	{0x4, talkov_wqhd_dualdsi_cmdoff_cmd1, 0x78}
};

#define TALKOV_WQHD_DUALDSI_CMD_OFF_COMMAND 2


static struct command_state talkov_wqhd_dualdsi_cmd_state = {
	0, 1
};

/*---------------------------------------------------------------------------*/
/* Command mode panel information                                            */
/*---------------------------------------------------------------------------*/
static struct commandpanel_info talkov_wqhd_dualdsi_cmd_command_panel = {
	1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Video mode panel information                                              */
/*---------------------------------------------------------------------------*/
static struct videopanel_info talkov_wqhd_dualdsi_cmd_video_panel = {
	32, 0, 0, 0, 1, 1, 2, 0, 0x9
};

/*---------------------------------------------------------------------------*/
/* Lane configuration                                                        */
/*---------------------------------------------------------------------------*/
static struct lane_configuration talkov_wqhd_dualdsi_cmd_lane_config = {
	4, 0, 1, 1, 1, 1
};

/*---------------------------------------------------------------------------*/
/* Panel timing                                                              */
/*---------------------------------------------------------------------------*/
static const uint32_t talkov_wqhd_dualdsi_cmd_timings[] = {
	0xB9, 0x60, 0x42, 0x1, 0xA4, 0xA4, 0x4A, 0x64, 0x4E, 0x03, 0x04, 0x00
};

static struct panel_timing talkov_wqhd_dualdsi_cmd_timing_info = {
	0, 4, 0x5D, 0x05
};

/*---------------------------------------------------------------------------*/
/* Panel reset sequence                                                      */
/*---------------------------------------------------------------------------*/
static struct panel_reset_sequence talkov_wqhd_dualdsi_cmd_reset_seq = {
	{1, 0, 1, }, {10, 10, 10, }, 2
};

/*---------------------------------------------------------------------------*/
/* Backlight setting                                                         */
/*---------------------------------------------------------------------------*/
static struct backlight talkov_wqhd_dualdsi_cmd_backlight = {
	1, 1, 4095, 100, 2, "PMIC_8941"
};

#endif /*_PANEL_TALKOV_WQHD_DUALDSI_CMD_H_*/
