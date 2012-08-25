ifneq (build, $(notdir $(CURDIR)))
include target.mk
else

SRC_DIR:=$(ROOT_DIR)/src
INCLUDE_DIR:=$(ROOT_DIR)/include
BUILD_DIR:=.

vpath % $(SRC_DIR)

.SECONDARY:

.PHONY: all clean

all: gltchsrf.d64

%.asm: %.src
	k2pp -I$(INCLUDE_DIR) -I$(SRC_DIR) -I$(BUILD_DIR) <$< >$@

%.prg: %.asm
	k2asm -o $@ -x $(@:%.prg=%.hdr) -c $(@:%.prg=%.dnc) $<

%.hdr: %.prg

%.dnc: %.prg

%.prg: %.bas
	petcat -w2 <$< >$@

main.asm: main.src $(INCLUDE_DIR)/c64.inc startup.src screen.src zero_page.inc

sprites.prg: sprites.d64
	d642prg $< sprites $@

gltchsrf.prg: main.prg main.dnc sprites.prg
	k2link -d gltchsrf.dnc $^ -o $@

gltchsrf.dnc: gltchsrf.prg

gltchsrf.exo2.prg: gltchsrf.prg
	exomizer sfx 0x4000 -t64 -o $@ '-X dec $$d020 inc $$d020' \
		'-s lda #$$0 sta $$d011 sta $$d015 sta $$d020 sta $$d021' \
		-- $<

gltchsrf.d64: gltchsrf.exo2.prg
	mkd64 $@ 'gltchsrf,00'
	copy2d64 $@ $<

clean:
	# handled by target.mk

endif
