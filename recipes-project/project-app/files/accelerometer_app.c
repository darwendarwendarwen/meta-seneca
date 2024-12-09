#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>


#define I2C_BUS "/dev/i2c-5"
#define DEVICE_ADDR 0x53
#define DEVICE_ID_REGISTER 0x00
#define WRITE_REG 0xA6


int main() {
    int fd;
    char buf[2];

    // Open I2C bus
    if ((fd = open(I2C_BUS, O_RDWR)) < 0) {
        perror("Failed to open the I2C bus");
        return 1;
    }


    // Set the I2C slave address
    if (ioctl(fd, I2C_SLAVE, DEVICE_ADDR) < 0) {
        perror("Failed to set I2C slave address");
        close(fd);
        return 1;
    }
    
    // Read the device id
    buf[0] = DEVICE_ID_REGISTER;
    if (write(fd, buf, 1) !=1) {
        perror("Failed to select register for reading");
        close(fd);
        return 1;
    }

    if (read(fd, buf, 1) != 1) {
        perror("Failed to read from the I2C device");
        close(fd);
        return 1;
    }
    printf("Device id: 0x%02X from register 0x%02X\n", buf[0], DEVICE_ID_REGISTER);

    close(fd);    
    
    return 0;
}