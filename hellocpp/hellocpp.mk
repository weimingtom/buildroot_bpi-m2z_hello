################################################################################
#
# helloworld
# see https://github.com/cirosantilli/buildroot/blob/in-tree-package-2016.05/package/hello/hello.mk
# rm -rf output/build/hellocpp-1.0/ && make
#
################################################################################

HELLOCPP_VERSION = 1.0
HELLOCPP_SITE = ./package/hellocpp/src
HELLOCPP_SITE_METHOD = local
#HELLOCPP_INSTALL_STAGING = YES
HELLOCPP_LICENSE = MIT

define HELLOCPP_BUILD_CMDS
	$(MAKE) CC="$(TARGET_CC)" CXX="$(TARGET_CXX)" LD="$(TARGET_LD)" -C $(@D)
endef

define HELLOCPP_INSTALL_STAGING_CMDS
endef

define HELLOCPP_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/hellocpp $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))
#$(eval $(host-generic-package))

