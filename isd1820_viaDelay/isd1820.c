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
#include "isd1820.h"
#include "main.h"

void ISD1820_Record(uint16_t rec_time){
	HAL_GPIO_WritePin(REC_GPIO_Port, REC_Pin, 1);
	HAL_Delay(rec_time);
	HAL_GPIO_WritePin(REC_GPIO_Port, REC_Pin, 0);
}

void ISD1820_PlayComplete(void){
	HAL_GPIO_WritePin(PE_GPIO_Port, PE_Pin, 1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(PE_GPIO_Port, PE_Pin, 0);
}

void ISD1820_Play(uint16_t play_time){
	HAL_GPIO_WritePin(PL_GPIO_Port, PE_Pin, 1);
	HAL_Delay(play_time);
	HAL_GPIO_WritePin(PL_GPIO_Port, PE_Pin, 0);
}

void ISD1820_RecordAndPlay(uint16_t rec_time, uint16_t play_time){
	//Record:
	HAL_GPIO_WritePin(REC_GPIO_Port, REC_Pin, 1);
	HAL_Delay(rec_time);
	HAL_GPIO_WritePin(REC_GPIO_Port, REC_Pin, 0);
	HAL_Delay(100);
	//---
	//Play:
	HAL_GPIO_WritePin(PL_GPIO_Port, PL_Pin, 1);
	HAL_Delay(play_time);
	HAL_GPIO_WritePin(PL_GPIO_Port, PL_Pin, 0);
	//---
}

