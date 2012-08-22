%.asm: %.src
	k2pp <$< >$@

%.prg: %.asm
	k2asm -o $@ -x $(@:%.prg=%.hdr) -c $(@:%.prg=%.dnc) $<

%.hdr: %.prg

%.dnc: %.prg

%.prg: %.bas
	petcat -w2 <$< >$@
