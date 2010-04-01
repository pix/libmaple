#ifndef _USB_H_
#define _USB_H_

#define USB_ISR_ADDR              (0x08000090)
#define USB_SERIAL_ENDP_TXADDR    ((uint32) 0xC0)
#define USB_SERIAL_ENDP_RXADDR    ((uint32) 0x110)
#define USB_SERIAL_ENDP_TX        ((uint16) 0x1)
#define USB_SERIAL_ENDP_RX        ((uint16) 0x3)
#define USB_SERIAL_BUF_SIZE       (0x40)

#ifdef __cplusplus
extern "C" {
#endif

void usb_lpIRQHandler(void);
void usb_userToPMABufferCopy(uint8  *pbUsrBuf,uint16 wPMABufAddr,uint16 wNBytes);
void usb_PMAToUserBufferCopy(uint8  *pbUsrBuf,uint16 wPMABufAddr,uint16 wNBytes);
void usb_serialWriteStr(const char *outStr);
void usb_serialWriteChar(unsigned char ch);
uint8 usb_serialGetRecvLen();
void usb_copyRecvBuffer(unsigned char* dest, uint8 len);

#ifdef __cplusplus
} // extern "C"
#endif
#endif //_USB_H
