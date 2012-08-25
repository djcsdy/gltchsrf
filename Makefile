ifneq (build, $(notdir $(CURDIR)))
include target.mk
else

SRC_DIR:=$(ROOT_DIR)/src
INCLUDE_DIR:=$(ROOT_DIR)/include
BUILD_DIR:=.

vpath % $(SRC_DIR)

.SECONDARY:

.PHONY: all clean

all: main.d64

%.asm: %.src
	k2pp -I$(INCLUDE_DIR) -I$(SRC_DIR) -I$(BUILD_DIR) <$< >$@

%.prg: %.asm
	k2asm -o $@ -x $(@:%.prg=%.hdr) -c $(@:%.prg=%.dnc) $<

%.hdr: %.prg

%.dnc: %.prg

%.prg: %.bas
	petcat -w2 <$< >$@

main.asm: main.src $(INCLUDE_DIR)/c64.inc startup.src screen.src zero_page.inc

main.exo2.prg: main.prg
	exomizer sfx 0x4000 -t64 -o $@ '-X dec $$d020 inc $$d020' \
		'-s lda #$$0 sta $$d011 sta $$d015 sta $$d020 sta $$d021' \
		-- $<

main.d64: main.exo2.prg
	mkd64 $@ 'main,00'
	copy2d64 $@ $<

clean:
	# handled by target.mk

endif
