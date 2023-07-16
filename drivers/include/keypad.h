/*
 * keypad.h
 *
 *  Created on: May 20, 2022
 *      Author: Doaa
 */

#ifndef INCLUDE_KEYPAD_H_
#define INCLUDE_KEYPAD_H_
void KeyPad_INIT(void);
void KeyPad_MANAGE(void);
char KeyPad_GET_VALUE(void);
void KeypadCallouts_KeyPressNotificaton(void);

#endif /* INCLUDE_KEYPAD_H_ */
