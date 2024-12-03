SUMMARY = "Example of how to build an external Linux kernel module"
DESCRIPTION = "${SUMMARY}"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://COPYING;md5=12f884d2ae1ff87c09e5b7ccc2c4ca7e"

inherit module

SRCREV= "e4221b6a9ab518d461f771457ac78f19efe5a8fe"
SRC_URI = "git://github.com/darwendarwendarwen/LNX500_Lab8.git;protocol=https;branch=working-branch"

S = "${WORKDIR}/git"

RPROVIDES:${PN} += "pmu-mod"