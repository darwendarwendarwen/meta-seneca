SUMMARY = "Final Project code"
DESCRIPTION = "Compiles and installs a c program for the LNX500 Final project"
LICENSE = "CLOSED"

SRC_URI = "git://github.com/darwendarwendarwen/final-project-code.git;protocol=https;branch=working-branch"

SRCREV = "4f1869edac75d07f7befdbff361e466da2897935"

S = "${WORKDIR}/git"

do_compile() {
        oe_runmake
}

do_install() {
        install -d ${D}/usr/bin
        install -m 0755 accelerometer_app ${D}/usr/bin
}

