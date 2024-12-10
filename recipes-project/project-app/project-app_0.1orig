SUMMARY = "Input App"
DESCRIPTION = "Compiles and installs a c program"
LICENSE = "ClOSED"

SRC_URI = "file://accelerometer_app.c"

S = "${WORKDIR}"

do_compile() {
        ${CC} accelerometer_app.c -o accelerometer_app
}

do_install() {
        install -d ${D}${bindir}
        install -m 0755 accelerometer_app ${D}${bindir}
}