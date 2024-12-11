DESCRIPTION = "Example library use"
LICENSE = "CLOSED"

DEPENDS = "nlohmann-json gtest spdlog"

inherit cmake

SRC_URI = "git://github.com/darwendarwendarwen/lnx500-lab9.git;branch=working-branch;protocol=https"
SRCREV = "dc79c177da7afe058212debd14a11c5648325b84"

S = "${WORKDIR}/git"


do_install() {
    install -d ${D}${bindir}
    install -m 0755 tests/simple-library-test ${D}${bindir}/
}

FILES:${PN} += "${bindir}/simple-library-test"
