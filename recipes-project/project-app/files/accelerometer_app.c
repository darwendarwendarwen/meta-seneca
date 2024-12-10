#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdint.h>

#define I2C_BUS "/dev/i2c-5"
#define DEV_ADDR 0x53
#define DEVICE_ID_REG 0x00
#define POWER_CTL_REG 0x2D
#define DATA_FORMAT_REGISTER 0x31
#define X_REG 0x32

int main() {
    int fd;
    char buf[6];

    // Open I2C bus
    if ((fd = open(I2C_BUS, O_RDWR)) < 0) {
        perror("Failed to open the I2C bus");
        return 1;
    }

    // Set the I2C slave address
    if (ioctl(fd, I2C_SLAVE, DEV_ADDR) < 0) {
        perror("Failed to set I2C slave address");
        close(fd);
        return 1;
    }

    // Read the device ID
    buf[0] = DEVICE_ID_REG;
    if (write(fd, buf, 1) != 1 || read(fd, buf, 1) != 1) {
        perror("Failed to read device ID");
        close(fd);
        return 1;
    }
    printf("Device ID: 0x%02X\n", buf[0]);

    // Set to measurement mode
    buf[0] = POWER_CTL_REG;
    buf[1] = 0x08;  // Measurement mode
    if (write(fd, buf, 2) != 2) {
        perror("Failed to configure the device");
        close(fd);
        return 1;
    }

    // Read axis data 
    for (int i = 0; i < 50; i++) {
        // read data from all axes starting from X_REG
        buf[0] = X_REG;
        if (write(fd, buf, 1) != 1 || read(fd, buf, 6) != 6) {
            perror("Failed to read x-axis data");
            close(fd);
            return 1;
        }
        // Combine MSB and LSB
        // shift buf[1] << 8 (MSB) + (or) buf[0] (LSB)
        // MSB <1111> -> <11110000> | <1111> == 11111111
        int16_t x = (int16_t)(buf[1] << 8 | buf[0]);
        int16_t y = (int16_t)(buf[3] << 8 | buf[2]);
        int16_t z = (int16_t)(buf[5] << 8 | buf[4]);
        printf("X = %d,  Y = %d, Z = %d\n", x, y, z);

        usleep(100*1000); // Delay 200 ms
    }

    printf("Completed\n");
    close(fd);
    return 0;
}
