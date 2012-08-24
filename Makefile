ifneq (build, $(notdir $(CURDIR)))
include target.mk
else

SRC_DIR:=$(ROOT_DIR)/src
INCLUDE_DIR:=$(ROOT_DIR)/include
BUILD_DIR:=.

vpath % $(SRC_DIR)

.SECONDARY:

%.asm: %.src
	k2pp -I$(INCLUDE_DIR) -I$(SRC_DIR) -I$(BUILD_DIR) <$< >$@

%.prg: %.asm
	k2asm -o $@ -x $(@:%.prg=%.hdr) -c $(@:%.prg=%.dnc) $<

%.hdr: %.prg

%.dnc: %.prg

%.prg: %.bas
	petcat -w2 <$< >$@

main.asm: main.src $(INCLUDE_DIR)/c64.inc startup.src screen.src

endif
