# CC ?= gcc
CFLAGS = -Wall -O2
LDFLAGS = 

# Target executable
TARGET = accelerometer-app

# Source files
SRCS = accelerometer-app.c

# Build rules
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SRCS)

# Clean up build artifacts
clean:
	rm -f $(TARGET) *.o

# Install to a directory (optional)
# install: $(TARGET)
# 	install -d $(DESTDIR)/home/root
# 	install -m 0755 $(TARGET) $(DESTDIR)/home/root

.PHONY: all clean install