/**
 * isd1820.h
Copyright (C)David Simon Marques, 2022
Copyright (C)Victor Araujo Sander Silva, 2022

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
 * Created on: November 4, 2022.
 * Last update: November 6, 2022.
 * Authors:  David Simon Marques <davidsimon@ufmg.br> and Victor Araujo Sander Silva <victorsander@ufmg.br>
 * Institution: Universidade Federal de Minas Gerais (UFMG)
 * Version: 1.0.0
----------------------------------------------------------------------
This API was developed as part of the Embedded Systems Programming course at UFMG
	 - Prof. Ricardo de Oliveira Duarte – Department of Electronic Engineering
----------------------------------------------------------------------
ISD1820 recording module API
----------------------------------------------------------------------
This API contains functions to provide use of some hardware resources
from ISD 1820 recording module available at:
https://wiki.keyestudio.com/KS0463_keyestudio_ISD1820_Voice_Recording_and_Playback_Module

* API main files:
	- isd1820.c
	- isd1820.h
* Hardware requirements:
	- ISD 1820 recording module.
		Datasheet: https://www.nuvoton.com/resource-files/EN_ISD1800_Datasheet_Rev_1.0.pdf
	 	Default pinout:
			ISD1820    |STM32F446RE        |DESCRIPTION
		    -----------------------------------------------------
			VCC        |3.3V               |Power source
			GND        |GND                |Ground.
			FT         |FT (GPIO_Output)   |Feed Through: if HIGH, the microphone drives the speaker directly.
			P-L        |PL (GPIO_Output)   |PLAY-L: Playback level-activated. While HIGH, it plays the audio stored on EEPROM, until it is over.
			P-E        |PE (GPIO_Output)   |PLAY-E: Playback edge-activated. if HIGH, even for a short period, it plays the audio stored entirely
			REC        |REC (GPIO_Output)  |Recording pin. This pin must remain HIGH for the duration of the recording.
			SP+        |       None        |Speaker out.
			SP-        |       None        |Speaker out.

	- STM32F446RET6 64 PINS.
		Manufacturer website: https://www.st.com/en/microcontrollers-microprocessors/stm32f446re.html
* Software requirements:
	- STM32CubeIDE 1.6.1: Available at https://www.st.com/en/development-tools/stm32cubeide.html
----------------------------------------------------------------------
 */
#ifndef ISD1820
#define ISD1820

/* C++ detection */
#ifdef __cplusplus
extern C {
#endif

#include "stm32f4xx_hal.h"

void ISD1820_StartRecording(void);
/**
 * @brief  Starts recording audio using ISD1820 chip by setting REC_Pin to high until Pin is set to low or ISD1820_StopRecording is called or time limit is reached.
 * @note   Recording takes precedence over Playing. The recording time limit depends on the resistance of resistor R4. For R4=100k, the limit is 10 seconds.
 * @retval None
 */

void ISD1820_StopRecording(void);
/**
 * @brief  Stops recording audio using ISD1820 chip by setting REC_Pin to low.
 * @note   Recording takes precedence over Playing. The recording time limit depends on the resistance of resistor R4. For R4=100k, the limit is 10 seconds.
 * @retval None
 */

void ISD1820_StartPlaying(void);
/**
 * @brief  Starts playing audio using ISD1820 chip by setting PL_Pin to high.
 * @note   If not stopped by other means (ie. ISD1820_StopPlaying()), plays until the end of the record.
 * @retval None
 */

void ISD1820_StopPlaying(void);
/**
 * @brief  Stops playing audio using ISD1820 chip by setting PL_Pin to low.
 * @retval None
 */

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

void ISD1820_EnableFeedThrough(void);
/**
 * @brief  Enable feed through.
 * @retval None
 */

void ISD1820_DisableFeedThrough(void);
/**
 * @brief  Disable feed through.
 * @retval None
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif
