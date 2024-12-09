DESCRIPTION = "Project app"
AUTHOR = "Darwin Luk"
LICENSE = "CLOSED"


SRC_URI = "git://github.com/darwendarwendarwen/Final-project-app.git;branch=working-branch;protocol=https"
SRCREV = "8a2d1f928b1317fdb75f6208dd1b2cfa6f96c035"

S = "${WORKDIR}/git"

DEPENDS += ""

do_compile(){
    oe_runmake -C ${S}/files
}

do_install(){
    install -d ${D}/usr/bin
    install -m 0755 accelerometer-app ${D}/usr/bin
}

inherit autotools