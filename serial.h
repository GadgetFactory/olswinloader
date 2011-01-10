/*
 * OS independent serial interface
 *
 * Heavily based on Pirate-Loader:
 * http://the-bus-pirate.googlecode.com/svn/trunk/bootloader-v4/pirate-loader/source/pirate-loader.c
 *
 */
#ifndef MYSERIAL_H_
#define MYSERIAL_H_

#ifdef WIN32
#else

#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>

#endif

#ifdef MACOSX
#include <IOKit/serial/ioss.h>
#include <sys/ioctl.h>

#define B1500000 1500000
#define B1000000 1000000
#define B921600  921600
#endif

int serial_setup(int fd, unsigned long speed);
int serial_write(int fd, const uint8_t *buf, int size);
int serial_read(int fd, uint8_t *buf, int size);
int serial_open(const char *port);
int serial_close(int fd);


#endif

