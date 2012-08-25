zp.screen.char_x = 3 ; 2 bytes
zp.screen.x = zp.screen.char_x + 2 ; 2 bytes
zp.screen.frames_pending = zp.screen.x + 2 ; 1 byte
zp.screen.frames_ready = zp.screen.frames_pending + 1 ; 1 byte
zp.screen.buffer.x = zp.screen.frames_ready + 1 ; 2 bytes
zp.game_loop.player.x = zp.screen.buffer.x + 2 ; 2 bytes
zp.game_loop.player.y = zp.game_loop.player.x + 2 ; 1 byte
zp.tmp = $f0 ; 16 bytes
