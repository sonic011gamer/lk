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

#ifndef _PANEL_TEQUILA_720P_VIDEO_H_
#define _PANEL_TEQUILA_720P_VIDEO_H_
/*---------------------------------------------------------------------------*/
/* HEADER files                                                              */
/*---------------------------------------------------------------------------*/
#include "panel.h"

/*---------------------------------------------------------------------------*/
/* Panel configuration                                                       */
/*---------------------------------------------------------------------------*/
static struct panel_config tequila_720p_video_panel_data = {
	.panel_node_id = "qcom,mdss_dsi_tequila_720p_video",
	.panel_controller = "dsi:0:",
	.panel_compatible = "qcom,mdss-dsi-panel",
	.panel_interface = MIPI_VIDEO_PANEL,
	.panel_type = 0,
	.panel_destination = "DISPLAY_1",
	.panel_orientation = 0,
	.panel_clockrate = 0, //deprecated, uses bitclock_freq now
	.panel_framerate = 60,
	.panel_channelid = 1,
	.dsi_virtualchannel_id = 0,
	.panel_broadcast_mode = 0,
	.panel_lp11_init = 0,
	.panel_init_delay = 0,
	.dsi_stream = 0,
	.interleave_mode = 0,
	.panel_bitclock_freq = 386000000, //set to 0 to calculate automatically
	.panel_operating_mode = 0,
	.panel_with_enable_gpio = 0,
	.mode_gpio_state = 0,
};

/*---------------------------------------------------------------------------*/
/* Panel resolution                                                          */
/*---------------------------------------------------------------------------*/
static struct panel_resolution tequila_720p_video_panel_res = {
	.panel_width = 720,
	.panel_height = 1280,
	.hfront_porch = 76,
	.hback_porch = 18,
	.hpulse_width = 8,
	.hsync_skew = 0,
	.vfront_porch = 14,
	.vback_porch = 8,
	.vpulse_width = 2,
	.hleft_border = 0,
	.hright_border = 0,
	.vtop_border = 0,
	.vbottom_border = 0,
	.hactive_res = 0,
	.vactive_res = 0,
	.invert_data_polarity = 0,
	.invert_vsync_polarity = 0,
	.invert_hsync_polarity = 0
};

/*---------------------------------------------------------------------------*/
/* Panel color information                                                   */
/*---------------------------------------------------------------------------*/
static struct color_info tequila_720p_video_color = {
	.color_format = 24,
	.color_order = 0,
	.underflow_color = 0xff,
	.border_color = 0,
	.pixel_packing = 0,
	.pixel_alignment = 0
};

/*---------------------------------------------------------------------------*/
/* Panel on/off command information                                          */
/*---------------------------------------------------------------------------*/
static char tequila_720p_video_on_cmd0[] = {
	0x11, 0x00, 0x05, 0x80
};

static char tequila_720p_video_on_cmd1[] = {
	0x53, 0x28, 0x15, 0x80
};

static char tequila_720p_video_on_cmd2[] = {
	0x51, 0x80, 0x15, 0x80
};

static char tequila_720p_video_on_cmd3[] = {
	0x29, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd tequila_720p_video_on_command[] = {
	{0x4, tequila_720p_video_on_cmd0, 0x78},
	{0x4, tequila_720p_video_on_cmd1, 0x00},
	{0x4, tequila_720p_video_on_cmd2, 0x78},
	{0x4, tequila_720p_video_on_cmd3, 0x00}
};

#define TEQUILA_720P_VIDEO_ON_COMMAND 4


static char tequila_720p_videooff_cmd0[] = {
	0x28, 0x00, 0x05, 0x80
};

static char tequila_720p_videooff_cmd1[] = {
	0x53, 0x00, 0x15, 0x80
};

static char tequila_720p_videooff_cmd2[] = {
	0x10, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd tequila_720p_video_off_command[] = {
	{0x4, tequila_720p_videooff_cmd0, 0x00},
	{0x4, tequila_720p_videooff_cmd1, 0x00},
	{0x4, tequila_720p_videooff_cmd2, 0x78}
};

#define TEQUILA_720P_VIDEO_OFF_COMMAND 3


static struct command_state tequila_720p_video_state = {
	.oncommand_state = 0,
	.offcommand_state = 1
};

/*---------------------------------------------------------------------------*/
/* Command mode panel information                                            */
/*---------------------------------------------------------------------------*/
static struct commandpanel_info tequila_720p_video_command_panel = {
	.techeck_enable = 0,
	.tepin_select = 0,
	.teusing_tepin = 0,
	.autorefresh_enable = 1,
	.autorefresh_framenumdiv = 1,
	.tevsync_rdptr_irqline = 0,
	.tevsync_continue_lines = 0,
	.tevsync_startline_divisor = 0,
	.tepercent_variance = 0,
	.tedcs_command = 0,
	.disable_eotafter_hsxfer = 0,
	.cmdmode_idletime = 0
};

/*---------------------------------------------------------------------------*/
/* Video mode panel information                                              */
/*---------------------------------------------------------------------------*/
static struct videopanel_info tequila_720p_video_video_panel = {
	.hsync_pulse = 0,
	.hfp_power_mode = 0,
	.hbp_power_mode = 0,
	.hsa_power_mode = 0,
	.bllp_eof_power_mode = 1,
	.bllp_power_mode = 1,
	.traffic_mode = 2,
	.dma_delayafter_vsync = 0,
	.bllp_eof_power = 0x9
};

/*---------------------------------------------------------------------------*/
/* Lane configuration                                                        */
/*---------------------------------------------------------------------------*/
static struct lane_configuration tequila_720p_video_lane_config = {
	.dsi_lanes = 4,
	.dsi_lanemap = 0,
	.lane0_state = 1,
	.lane1_state = 1,
	.lane2_state = 1,
	.lane3_state = 1,
	.force_clk_lane_hs = 0
};

/*---------------------------------------------------------------------------*/
/* Panel timing                                                              */
/*---------------------------------------------------------------------------*/
static const uint32_t tequila_720p_video_timings[] = {
	0x76, 0x18, 0x10, 0x00, 0x3A, 0x46, 0x0A, 0x1C, 0x12, 0x03, 0x04, 0x00
};

static struct panel_timing tequila_720p_video_timing_info = {
	.dsi_mdp_trigger = 0,
	.dsi_dma_trigger = 4,
	.tclk_post = 0xC3,
	.tclk_pre = 0x14
};

/*---------------------------------------------------------------------------*/
/* Panel reset sequence                                                      */
/*---------------------------------------------------------------------------*/
static struct panel_reset_sequence tequila_720p_video_reset_seq = {
	.pin_state = {1, 0, 1, },
	.sleep = {10, 10, 10, },
	.pin_direction = 2
};

/*---------------------------------------------------------------------------*/
/* Backlight setting                                                         */
/*---------------------------------------------------------------------------*/
static struct backlight tequila_720p_video_backlight = {
	.bl_interface_type = 1,
	.bl_min_level = 1,
	.bl_max_level = 128,
	.bl_step = 10,
	.bl_pmic_controltype = 2,
	.bl_pmic_model = "PMIC_8941"
};

#endif /*_PANEL_TEQUILA_720P_VIDEO_H_*/
