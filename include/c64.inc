#ifndef C64_INC
#define C64_INC

pla.ddr=0
pla.dr=1

pla.LORAM=%00000001
pla.HIRAM=%00000010
pla.CHAREN=%00000100

pla.dr.DEFAULT=%00110101
pla.ddr.DEFAULT=%00101111

pla.RAMIO=%00110101
pla.KERNEL=%00110110
pla.ALLRAM=%00110100

irq=$fffe
nmi=$fffa

#ifdef NO_DNC
  vic=$d0000
  sid=$d400
  cia1=$dc00
  cia2=$dd00
#else
  vic=%110100????000000 ; $d000, $d040, ... $d3c0
  sid=%110101?????00000 ; $d400, $d420, ... $d7e0
  cia1=%11011100????0000 ; $dc00, $dc10, ... $dcf0
  cia2=%11011101????0000 ; $dd00, $dd10, ... $ddf0
#endif

colorram=$d800
io1=$de00
io2=$df00

vic.s0x=vic
vic.s0y=vic|1
vic.s1x=vic|2
vic.s1y=vic|3
vic.s2x=vic|4
vic.s2y=vic|5
vic.s3x=vic|6
vic.s3y=vic|7
vic.s4x=vic|8
vic.s4y=vic|9
vic.s5x=vic|$a
vic.s5y=vic|$b
vic.s6x=vic|$c
vic.s6y=vic|$d
vic.s7x=vic|$e
vic.s7y=vic|$f
vic.sxmsb=vic|$10
vic.cr1=vic|$11
vic.raster=vic|$12
vic.lpx=vic|$13
vic.lpy=vic|$14
vic.sen=vic|$15
vic.cr2=vic|$16
vic.sexy=vic|$17
vic.mem=vic|$18
vic.irq=vic|$19
vic.irqmask=vic|$1a
vic.sprio=vic|$1b
vic.smcm=vic|$1c
vic.sexx=vic|$1d
vic.sscoll=vic|$1e
vic.sbcoll=vic|$1f
vic.border=vic|$20
vic.bg0=vic|$21
vic.bg1=vic|$22
vic.bg2=vic|$23
vic.bg3=vic|$24
vic.smc0=vic|$25
vic.smc1=vic|$26
vic.s0c=vic|$27
vic.s1c=vic|$28
vic.s2c=vic|$29
vic.s3c=vic|$2a
vic.s4c=vic|$2b
vic.s5c=vic|$2c
vic.s6c=vic|$2d
vic.s7c=vic|$2e

vic.bg=vic.bg0

vic.cr1.RASTER8=%10000000
vic.cr1.ECM=%01000000
vic.cr1.BITMAP=%00100000
vic.cr1.BLANK=%00010000
vic.cr1.ROW25=%00001000
vic.cr1.YSCROLL=%00000111

vic.cr2.STOP=%00100000
vic.cr2.MCM=%00010000
vic.cr2.COL40=%00001000
vic.cr2.XSCROLL=%00000111

vic.BLACK=$?0
vic.WHITE=$?1
vic.RED=$?2
vic.CYAN=$?3
vic.PURPLE=$?4
vic.GREEN=$?5
vic.BLUE=$?6
vic.YELLOW=$?7
vic.ORANGE=$?8
vic.BROWN=$?9
vic.PINK=$?a
vic.DARKGREY=$?b
vic.GREY=$?c
vic.LIGHTGREEN=$?d
vic.LIGHTBLUE=$?e
vic.LIGHTGREY=$?f

sid.v1.freq=sid
sid.v1.pw=sid|2
sid.v1.ctrl=sid|4
sid.v1.ad=sid|5
sid.v1.sr=sid|6

sid.v2.freq=sid|7
sid.v2.pw=sid|9
sid.v2.ctrl=sid|$b
sid.v2.ad=sid|$c
sid.v2.sr=sid|$d

sid.v3.freq=sid|$e
sid.v3.pw=sid|$10
sid.v3.ctrl=sid|$12
sid.v3.ad=sid|$13
sid.v3.sr=sid|$14

sid.filter=sid|$15
sid.res=sid|$17
sid.fmode=sid|$18

sid.adc1=sid|$19
sid.adc2=sid|$1a

sid.osc=sid|$1b
sid.env=sid|$1c

cia1.pra=cia1
cia1.prb=cia1|1
cia1.ddra=cia1|2
cia1.ddrb=cia1|3
cia1.ta=cia1|4
cia1.tb=cia1|6
cia1.tod.tenth=cia1|8
cia1.tod.sec=cia1|9
cia1.tod.min=cia1|$a
cia1.tod.hour=cia1|$b
cia1.sdr=cia1|$c
cia1.icr=cia1|$d
cia1.cra=cia1|$e
cia1.crb=cia1|$f

cia2.pra=cia2
cia2.prb=cia2|1
cia2.ddra=cia2|2
cia2.ddrb=cia2|3
cia2.ta=cia2|4
cia2.tb=cia2|6
cia2.tod.tenth=cia2|8
cia2.tod.sec=cia2|9
cia2.tod.min=cia2|$a
cia2.tod.hour=cia2|$b
cia2.sdr=cia2|$c
cia2.icr=cia2|$d
cia2.cra=cia2|$e
cia2.crb=cia2|$f
