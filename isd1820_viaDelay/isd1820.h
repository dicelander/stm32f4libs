/**
 * original authors:  David Simon Marques <davidsimon@ufmg.br> and Victor

   ----------------------------------------------------------------------
   	Copyright (C)David Simon Marques, 2022
    Copyright (C) Victor , 2022
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.
     
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   ----------------------------------------------------------------------
 */
#ifndef ISD1820
#define ISD1820

/* C++ detection */
#ifdef __cplusplus
extern C {
#endif


/**
 * This SSD1306 LCD uses I2C for communication
 *
 * Library features functions for recording and playing audio using ISD 1820 chip.
 *
 * Default pinout
 *
SSD1306    |STM32F4xx    |DESCRIPTION

VCC        |3.3V         |
GND        |GND          |
FT         |PB6          |Serial clock line
P-L        |PB6          |Serial clock line
P-E        |PB6          |Serial clock line
REC        |PB6          |Serial clock line
 */

#include "stm32f4xx_hal.h"

void ISD1820_Record(uint16_t rec_time);
/**
 * @brief  Records audio using ISD1820 chip. It records a total of {rec_time} milliseconds.
 * @note   The recording time limit depends on the resistance of resistor R4. For R4=100k, the limit is 10 seconds.
 * @param  rec_time: Recording time required [milliseconds].
 * @retval None
 */

void ISD1820_PlayComplete(void);
/**
 * @brief  Plays audio stored on EEPROM to the end.
 * @retval None
 */

void ISD1820_Play(uint16_t play_time);
/**
 * @brief  Plays audio stored on EEPROM up to {play_time} milliseconds.
 * @note   If the audio stored has less than {play_time} milliseconds
 * @param  rec_time: Recording time required [milliseconds].
 * @param  play_time: Play time [milliseconds].
 * @retval None
 */

void ISD1820_RecordAndPlay(uint16_t rec_time, uint16_t play_time);
/**
 * @brief  Records audio using ISD1820 chip and then play it back. It records a total of [rec_time] milliseconds.
 * @note   The recording time limit depends on the resistance of resistor R4. For R4=100k, the limit is 10 seconds.
 * @param  rec_time: Recording time required [milliseconds].
 * @param  play_time: Play time [milliseconds].
 * @retval None
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif
