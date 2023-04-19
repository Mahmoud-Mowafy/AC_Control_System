/*
 * lcd_interface.h
 *
 * Created: 4/17/2023 6:22:38 PM
 *  Author: Mahmoud Mowafey
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/************************************************************************/
/* Type Definitions                                                     */
/************************************************************************/
/**
 * @brief Enumeration of LCD error codes
 *
 * This enumeration defines the possible error codes that can be returned by
 * functions in the LCD driver.
 *
 */  
typedef enum {
	LCD_OK,		/**< Operation completed successfully */
	LCD_ERROR	/**< An error occurred during the operation */
}EN_LCD_ERROR_T;

/************************************************************************/
/* Function Prototypes                                                  */
/************************************************************************/

void LCD_init(void);
void LCD_displayCharacter(uint8_t character);
void LCD_senCommand(uint8_t command);
void LCD_sendData(uint8_t data);
void LCD_displayString(uint8_t *string);
void LCD_displayInteger(uint8_t number );
void LCD_goToRowColumn(uint8_t row,uint8_t col);
void LCD_clear(void);


#endif /* LCD_INTERFACE_H_ */