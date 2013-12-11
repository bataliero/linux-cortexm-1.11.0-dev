/*
 * (C) Copyright 2011
 * Emcraft Systems, <www.emcraft.com>
 * Alexander Potashev <aspotashev@emcraft.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <linux/kernel.h>

#include <asm/hardware/cortexm3.h>
#include <mach/eth.h>

/*
 * Perform the low-level reboot.
 */
void lpc178x_reboot(void)
{
#ifdef CONFIG_LPC178X_ETHER
	/*
	 * We have to reset the PHY immediately before doing a software SoC
	 * reset, because otherwise the Ethernet block of the SoC will hang
	 * after reset.
	 */
	lpc178x_phy_final_reset();
#endif

	/*
	 * Perform the software reset (SYSRESET)
	 */
	cortex_m3_reboot();
}
