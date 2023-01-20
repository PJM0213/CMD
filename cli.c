#include "main.h" //UART _HandleTypedef 어디있는지 확인

extern uint8_t data; // 전역 변수 data 포함
extern UART_HandleTypeDef huart1; //전역 변수 huart1 포함

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) //수신 완료시 동작하는 함수
{
  if(huart->Instance == USART1) //채널명을 USART1로 지정
  {

	  if(data == '3') //3 입력시 LED On/Off
	  {
		  HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13); //LED3 toggle
		  printf("--------------------\r\n");
		  printf("Enter a number.\r\n");
		  printf("3. LD3 on/off\r\n");
		  printf("4. LD4 on/off\r\n");
		  printf("--------------------\r\n");
	  }
	  else if(data == '4')//4 입력시 LED On/Off
	  {
	  	  HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_14); //LED4 toggle
	  	  printf("--------------------\r\n");
	  	  printf("Enter a number.\r\n");
	  	  printf("3. LD3 on/off\r\n");
	  	  printf("4. LD4 on/off\r\n");
	  	  printf("--------------------\r\n");
	  }
	  else //3, 4외의 값을 입력할때 해당 문자열 출력
	  {
		  printf("No found\r\n");
	  }

	  HAL_UART_Receive_IT(&huart1, &data, sizeof(data));//데이터를 data 크기만큼 인터럽트 방식으로 전송
  }
}




