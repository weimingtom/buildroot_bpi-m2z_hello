################################################################################
#
# helloworld
# see https://github.com/cirosantilli/buildroot/blob/in-tree-package-2016.05/package/hello/hello.mk
# rm -rf output/build/helloworld-1.0/ && make
#
################################################################################

HELLOWORLD_VERSION = 1.0
HELLOWORLD_SITE = ./package/helloworld/src
HELLOWORLD_SITE_METHOD = local
#HELLOWORLD_INSTALL_STAGING = YES
HELLOWORLD_LICENSE = MIT

define HELLOWORLD_BUILD_CMDS
	$(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D)
endef

define HELLOWORLD_INSTALL_STAGING_CMDS
endef

define HELLOWORLD_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/helloworld $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))
#$(eval $(host-generic-package))

